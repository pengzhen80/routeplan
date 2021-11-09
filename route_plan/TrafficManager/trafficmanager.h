//#include <map.h>
#include <queue>
#include <thread>
#include <mutex>
#include <unordered_map>
#include<unordered_set>

class TrafficManager
{
public:
struct order_car
{
    int car_id;
    int position;
    int target;
};
struct traffic_car
{
    int car_id;
    int speed;
    std::vector<int> total_path;
    int uninit_count=0;
    std::vector<int> next_path; //if car is stop, then next_path is current position
    std::vector<int> lock_tags;

    int position_tag;
    int target_tag;
    int count_wait; //to count how long has the car waited
};
struct car_cango
{
    int car_id;
    std::vector<int> path;
};
enum LOCKSTATE
{
    LOCKSTATE_EXIT = 0,
    LOCKSTATE_ENTER,
    LOCKSTATE_APPROACH,
    LOCKSTATE_STANDBY,
};

public:
traffic_car Make_Traffic_car(int car_id,int position, int target);

private:
struct traffic_map
{
    std::unordered_map<int,int>  locks_tag_count;
    std::unordered_map<int,LOCKSTATE> locks_tag_state;
    std::unordered_set<int> tags_approaching;
    std::unordered_map<int,std::vector<int>> tags_intersection;
    
};
public:
    explicit TrafficManager()
    {
        std::thread t_waittogo(&TrafficManager::wait_to_go, this);
        t_waittogo.detach();


        //std::thread t_updatelocktags(&TrafficManager::update_locktags, this);
        //t_updatelocktags.detach();
    };
    
    bool HasCarGo();
    std::queue<car_cango> GetCarGo();

    void Deal_Task(order_car car_task);

    void update_car_path(traffic_car car_info);
    void ask_car_path(int car_id);
    
    inline bool Default_EndId(int end_id){
        return end_id == -1;
    }

    void InitCars(int car_num);
    void InitCars_NumPos(std::vector<traffic_car> vec_car_info);

    void InitMap_ChessBoard(int map_x,int map_y);
    std::unordered_set<int> lock_tags();
    //to init cars todo
    bool CheckCarPathInit(int car_id,int end_id);
    bool CheckCarPathUninit(int car_id);
    int  Get_UninitCar_Target(int car_id);
private:
    bool CheckPathComflict(std::vector<int> path);
    std::vector<int> CheckPathCango(std::vector<int> path);

    void wait_to_go();
    void update_lock_tags(std::vector<int> path);
    void release_lock_tags(std::vector<int> tags);
    std::vector<int> get_path_by_carid(int car_id);
    void update_car_paths(int car_id);
    void update_car_paths_bypath(int car_id,std::vector<int> path);

    void update_car_locktags(int car_id,std::vector<int> lock_tags);
    void lock_if_car_arrive(int car_id);
    bool check_path_position(std::vector<int> path,int car_id);
    void uninit_car(int car_id); // wait too long, need route again
    bool move_to_neighbor(int car_id,int direction);//0 is x,1 is y
    int Get_neighbors_lock(int id, int size,int direction);
    void Update_Car_Uninit_Count(int car_id);
    int Get_CarId_ByPosition(int position);
private:
    std::vector<traffic_car> cars_;
    std::unordered_map<int,int> car_ids_indexs_;
    std::mutex mutex_traffic_car_;

    std::vector<int> cars_need_init_;
    std::mutex mutex_traffic_map_;
    traffic_map traffic_map_;
    std::mutex mutex_que_cango_;
    std::queue<car_cango> que_cango_;
    std::mutex mutex_vec_wait_;
    //std::vector<int> vec_wait_;
    std::vector<std::vector<int>> vec_wait_;
    //std::unordered_map<int,int> map_wait_;

     std::mutex mutex_check_congestion_;

     int wait_toolong_count_ = 0;
     double wait_total_time_ = 0;

};