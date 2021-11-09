#include <vector>
#include <iostream>
#include <tinyxml2.h>
#include <xmltomap.h>
#include <Astar.h>
#include <CoAstar.h>
//#include <map.h>
//#include "route_planner.h"
//#include <client.h>
#include <CallCarServer.h>
#include <map.h>
#include <queue>
//#include "route_planner.h"
#include <trafficmanager.h>
#include <unordered_set>
#include <ordermanagement.h>
#include <ordermanagement_client.h>
#include <ordermanagement_server.h>
#include <jobmanagement.h>
#include <jobmanagement_server.h>
#include <dbmanagement_server.h>
#include <mongodbmanager.h>
#include <configurationmanager.h>

#define CARNMUMBER 10
#define CHESSBOARD 0
#define TRACK 1

static int Test_Car_Num = -1;

typedef void *(*THREADFUNCPTR)(void *);

bool CheckPathLength(int path_size, int s_id, int e_id)
{
  int s_each = s_id % 10;
  int e_each = e_id % 10;

  s_each = s_each == 0 ? 10 : s_each;
  e_each = e_each == 0 ? 10 : e_each;

  int s_tens = s_id / 10;
  int e_tens = e_id / 10;

  int dis_each = s_each >= e_each ? s_each - e_each : e_each - s_each;
  int dis_tens = s_tens >= e_tens ? s_tens - e_tens : e_tens - s_tens;

  //debug
  //std::cout<<"path size model is "<< (dis_each+dis_tens)*2<<std::endl;
  return path_size > (dis_each + dis_tens) * 3 ? false : true;
}

int main()
{
  MongodbManager::GetInstance()->Init();

  DBManagement_OrderManagement_Server *mongodb_server = new DBManagement_OrderManagement_Server();
  std::thread t_mongodb_server(&DBManagement_OrderManagement_Server::Init, mongodb_server);
  t_mongodb_server.detach();

  JobManagement_Server *jobmanagement_server = new JobManagement_Server();
  std::thread t_jobmanagement_server(&JobManagement_Server::Init, jobmanagement_server);
  t_jobmanagement_server.detach();

  OrderManagement_Server *order_management_server = new OrderManagement_Server();
  std::thread t_order_management_server(&OrderManagement_Server::Init, order_management_server);
  t_order_management_server.detach();

  usleep(5000);
  ordermangement_common::Data_For_DB data;
  data.number = 1;
  data.time = 1;
  data.type = std::string("delivery");
  data.result = std::string("success");
  data.data.goods_info.name = std::string("food");
  data.data.goods_pos = 1;
  data.data.target_pos = 2;
  OrderManagement::GetInstance()->insert_into_DB(data);

  // Map::Instance()->Init_Two(map);
  // RoutePlan rp;
  // vec_result = rp.Route(Map::Instance(),1,8);

  // std::cout<<std::endl;
  // // test client
  // RpClient client(
  //   grpc::CreateChannel("localhost:50051",
  //     grpc::InsecureChannelCredentials())
  //   );
  // std::thread thread_ = std::thread(&RpClient::AsyncCompleteRpc,&client);
  // client.SendRequest(1,8);
  // thread_.join();
#if TRACK //this is xml(track) map
  AstarRoute pathplanner;
  CooperativeAstar pathplan_coastar;
  //RoutePlan route_planner;
  TrafficManager trafficManager;
  Map map;

  //map = ReadValueFromXML("../../Resources/Maps/NewTrack - lower.xml");
  map = ReadValueFromXML("../../Resources/Maps/correct.xml");
  Vec_MyNode vec_XML_nodes = XmlMapToMyMap(map);
  Vec_MyNode vec_nodes;
  pathplan_coastar.Init(vec_XML_nodes);

  //init customer tags
  std::vector<int> test_customer_tags = GetCustomers(map);
  std::cout << "init customer tags :" << test_customer_tags.size() << std::endl;
  OrderManagement::GetInstance()->Test_Init_Customers(test_customer_tags);


  //for test
  std::vector<MyTypeNode> test_type_map = XmlMapToMyMap_Type(map);
  std::vector<JobMangement_Common::MyNode> test_jobmanagement_map;
  for(auto node: test_type_map)
  {
    JobMangement_Common::MyNode test_node ;
    test_node.id = node.id;
    test_node.neighbors = node.neighbors;
    test_node.pos.x = node.pos.x;
    test_node.pos.y = node.pos.y;
    test_node.pos.z = node.pos.z;
    test_node.type = node.type;
    test_jobmanagement_map.push_back(test_node);
  }
  JobManagement::JobManagement::Instance()->InitMap(test_jobmanagement_map);
  JobManagement::JobManagement::Instance()->DefaultInitCar();

  // AstarRoute astarr(vec_nodes);
  // AstarRoute::AstarResult astar_result = astarr.Route(27, 34);

  // for (int i = 0; i < astar_result.route.size(); i++)
  // {
  //     printf("%d  ", astar_result.route[i]);
  // }

  // std::cout << astar_result.distance<<std::endl;
  // CooperativeAstar::Vec_Path_Ask vec_path_ask;
  // CooperativeAstar::Node_Path_Ask node_path_ask;
  // node_path_ask.car_id = 1 ;
  // node_path_ask.position = 41;
  // node_path_ask.target = 5;
  // vec_path_ask.push_back(node_path_ask);
  //  CooperativeAstar::Vec_CoAstarResult vec_coastar_path = pathplan_coastar.Co_Route(vec_path_ask);

  // for (int j = 0; j < vec_coastar_path[0].path.size(); j++)
  // {
  //   std::cout <<vec_coastar_path[0].path[j].tag_id << " ";
  // }
  // std::cout << std::endl;
#endif

#if CHESSBOARD //this is chessboard map
  int map_size = 10;
  Vec_MyNode vec_nodes;
  Vec_MyNode vec_chess_board = Make_map(map_size);
  AstarRoute pathplanner;
  CooperativeAstar pathplan_coastar;
  pathplan_coastar.Init(vec_chess_board);
  //RoutePlan route_planner;
  TrafficManager trafficManager;
  //trafficManager.Init(CARNMUMBER);
  //debug
  // int arr[] ={ 6,15,10,31,87,35,17,30,16,29,3,39};
  // std::vector<int> varr(arr, arr+11);
  // std::unordered_set<int> set_locks;
  // for(int i=0;i<varr.size();i++)
  // {
  //   set_locks.insert(varr[i]);
  // }
  // vec_nodes = Make_map_locks(10,set_locks);

  // pathplanner.Init(vec_nodes);
  // AstarRoute::AstarResult result = pathplanner.Route(29,20);
  // //print route
  //           for (int i = 0; i < result.route.size(); i++)
  //           {
  //             std::cout << result.route[i] << " ";
  //           }
  //           std::cout << std::endl;
#endif
  std::queue<std::vector<int>> que_message; //message queue
  std::unordered_set<int> set_car_ids;      // limit: one car one msg
  CallCarServer *server = new CallCarServer();
  std::thread t_server(&CallCarServer::Init, server);
  t_server.detach();

  while (true)
  {
    //sleep(1);
    usleep(100);
    if (trafficManager.HasCarGo())
    {
      std::queue<TrafficManager::car_cango> que_cango = trafficManager.GetCarGo();
      while (!que_cango.empty())
      {
        TrafficManager::car_cango cur_cango = que_cango.front();
        std::vector<int> msg;
        msg.push_back(cur_cango.car_id);
        for (int i = 0; i < cur_cango.path.size(); i++)
        {
          msg.push_back(cur_cango.path[i]);
        }
        server->send_message(msg);
        que_cango.pop();
      }
    }

    if (server->has_message())
    {
      std::vector<std::vector<int>> car_ask = server->get_message();

      //if init car
      if (car_ask.size() > 0 && car_ask[0][0] == SIMULATOR_MSGTYPE::SIMULATOR_MSGTYPE_INIT_CAR)
      {
        std::cout << std::endl
                  << std::endl
                  << std::endl;
        std::cout << "car number is " << car_ask[0][1] << std::endl;
        trafficManager.InitCars(car_ask[0][1]);
        continue;
      }

      //debug
      // std::cout << "get message: ";
      // for (int i = 0; i < car_ask.size(); i++)
      // {
      //   std::cout << car_ask[i][1] << "  " << car_ask[i][2] << "  " << car_ask[i][3] << std::endl;
      // }

      std::vector<TrafficManager::traffic_car> vec_car;
      //CoAstar
      CooperativeAstar::Vec_Path_Ask vec_path_ask;
      std::unordered_set<int> set_map_blocks;

      for (int i = 0; i < car_ask.size(); i++)
      {
        int car_id = car_ask[i][1];
        int car_position = car_ask[i][2];
        int car_target = car_ask[i][3];

        //CoAstar
        CooperativeAstar::Node_Path_Ask node_path_ask;
        node_path_ask.car_id = car_id;
        node_path_ask.position = car_position;
        if (-1 == car_target)
        {
          if (trafficManager.CheckCarPathUninit(car_id))
          {
            car_target = trafficManager.Get_UninitCar_Target(car_id);
          }
          else
          {
            trafficManager.ask_car_path(car_id);
            set_map_blocks.insert(car_position);
            continue;
          }
        }
        node_path_ask.target = car_target;
        vec_path_ask.push_back(node_path_ask);
        continue;
      }
#if CHESSBOARD
      pathplan_coastar.Init(vec_chess_board);
#endif

#if TRACK
      pathplan_coastar.Init(vec_XML_nodes);
#endif
      //debug
      //std::cout << "path ask num is " << vec_path_ask.size() << std::endl;
      //check ask path
      // std::unordered_set<int> set_car_ask_path;
      // set_car_ask_path.clear();

      // for (CooperativeAstar::Vec_Path_Ask::iterator iter = vec_path_ask.begin(); iter != vec_path_ask.end();)
      // {
      //   if (set_car_ask_path.count((*iter).car_id) == 0)
      //   {
      //     std::cout << "car " << (*iter).car_id << " from " << (*iter).position << " to " << (*iter).target << std::endl;
      //     set_car_ask_path.insert((*iter).car_id);
      //     iter++;
      //   }
      //   else
      //   {
      //     iter = vec_path_ask.erase(iter);
      //     std::cout<<"erase an ask\n"<<"";
      //   }
      // }

      CooperativeAstar::Vec_CoAstarResult vec_coastar_path = pathplan_coastar.Co_Route(vec_path_ask);
      for (int i = 0; i < vec_coastar_path.size(); i++)
      {
        TrafficManager::traffic_car traffic_car;
        traffic_car.car_id = vec_coastar_path[i].car_id;
        for (CooperativeAstar::Node_CoPath node : vec_coastar_path[i].path)
        {
          if (node.action != CooperativeAstar::ACTION_WAIT)
          {
            traffic_car.total_path.push_back(node.tag_id);
          }
        }

        if (traffic_car.total_path.size() == 0)
        {
          pathplanner.Init(vec_XML_nodes);
          CooperativeAstar::AstarResult result = pathplan_coastar.Route(vec_coastar_path[i].position, vec_coastar_path[i].target);
          traffic_car.total_path = result.route;
          //debug
          //std::cout << "this is astar\n";
        }
        //traffic_car.total_path = vec_coastar_path[i].path;
        traffic_car.position_tag = vec_coastar_path[i].position;
        traffic_car.target_tag = vec_coastar_path[i].target;
        vec_car.push_back(traffic_car);

        //debug print route
        std::cout << "car " << traffic_car.car_id << " route:" << std::endl;
        for (int j = 0; j < traffic_car.total_path.size(); j++)
        {
          std::cout << traffic_car.total_path[j] << " ";
        }
        std::cout << std::endl;

        //debug print lock
        // std::unordered_set<int> lock_tags = trafficManager.lock_tags();
        // std::cout<<"lock tags "<< lock_tags.size() <<" is : ";
        // for(std::unordered_set<int>::iterator ite = lock_tags.begin();ite!=lock_tags.end();ite++)
        // {
        //   std::cout<<*ite<<" ";
        // }
        // std::cout<<std::endl;
      }

      for (int i = 0; i < vec_car.size(); i++)
      {
        trafficManager.update_car_path(vec_car[i]);
      }
    }
  }
  return 0;
}
