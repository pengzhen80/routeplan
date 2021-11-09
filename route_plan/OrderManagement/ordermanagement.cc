#include "ordermanagement.h"

OrderManagement *OrderManagement::instance_ = nullptr;

std::mutex OrderManagement::mutex_instance_;

OrderManagement *OrderManagement::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_instance_);
    if (nullptr == instance_)
    {
        instance_ = new OrderManagement();
    }
    return instance_;
}

OrderManagement::~OrderManagement()
{
    orderlist_.clear();
    order_num_index_.clear();
}

int OrderManagement::Add_Order(Order_For_OrderManagement order)
{
    std::cout << " ordermanagement:Add_Order \n ";

    int goods_pos = order.goods_pos;
    int target_pos = order.target_pos;
    Goods_Info data = order.info;
    ORDERTYPE type = order.type;
    ORDERACTION action = order.act;

    if (goods_pos < 0 || target_pos < 0)
    {
        return false;
    }

    OrderManagement_Order om_order;
    om_order.number = make_order_num();
    om_order.time = make_order_time();
    om_order.type = type;
    om_order.state = ORDERSTATE_ACT;
    om_order.data.goods_info = data;
    om_order.data.goods_pos = goods_pos;
    om_order.data.target_pos = target_pos;
    om_order.data.car_id = order.car_id;
    om_order.weight = make_order_weight();
    om_order.action = action;
    om_order.result = ORDERRESULT_DEFAULT;

    push_into_orderlist(om_order);

    return om_order.number;
}
bool OrderManagement::Cancel_Order(int order_num)
{
    if (check_order(order_num))
    {
        Order_For_JobManagement jm_order;
        jm_order = make_order_for_JobManagement(order_num);
        orderlist_jobmanagement_.push_back(jm_order);
    }
    return true;
}
void OrderManagement::Set_Order_State(int order_num, ORDERSTATE state)
{
    int order_index = order_num_index_[order_num];

    orderlist_[order_index].state = state;
}

void OrderManagement::push_into_orderlist(OrderManagement_Order order)
{
    orderlist_.push_back(order);
    order_num_index_.insert(std::make_pair(order.number, orderlist_.size() - 1));

    std::cout<<"OrderManagement::push_into_orderlist:  "<<order.data.car_id<<std::endl;

    std::lock_guard<std::mutex> lock(mutex_orderlist_jobmanagement_);
    orderlist_jobmanagement_.push_back(make_order_for_JobManagement(order));
}

void OrderManagement::pop_from_orderlist(int order_num)
{
    int order_index = order_num_index_[order_num];

    orderlist_.erase(orderlist_.begin() + order_index);
    order_num_index_.erase(order_num);

    //update num-index
    for (int i = order_index; i < orderlist_.size(); i++)
    {
        int order_num = orderlist_[i].number;

        order_num_index_[order_num] = i;
    }
}
bool OrderManagement::check_order(int order_num)
{
    if (order_num_index_.count(order_num) > 0)
    {
        return true;
    }
    return false;
}
bool OrderManagement::insert_into_DB(Data_For_DB data)
{
    dbclient_->Insert_Data(data);
    return true;
}
Order_For_JobManagement OrderManagement::make_order_for_JobManagement(int order_num)
{
    Order_For_JobManagement jm_order;
    if (order_num_index_.count(order_num) == 0)
    {
        jm_order.number = -1;
        return jm_order;
    }

    OrderManagement_Order order = orderlist_[order_num_index_[order_num]];
    jm_order.number = order.number;
    jm_order.action = order.action;
    jm_order.data = order.data;

    return jm_order;
}

Order_For_JobManagement OrderManagement::make_order_for_JobManagement(OrderManagement_Order order)
{
    Order_For_JobManagement jm_order;
    jm_order.number = order.number;
    jm_order.action = order.action;
    jm_order.data = order.data;

    std::cout<<"OrderManagement::make_order_for_JobManagement: "<<order.data.car_id<<std::endl;

    return jm_order;
}
int OrderManagement::make_order_num()
{
    return ++order_count_;
}

std::string OrderManagement::make_order_time()
{
    time_t now = time(0);
    char *dt = ctime(&now);

    std::string result(dt);

    return result;
}

int OrderManagement::make_order_weight()
{
    return 0;
}

bool OrderManagement::HasOrder()
{
    return !orderlist_jobmanagement_.empty();
}
std::vector<Order_For_JobManagement> OrderManagement::GetOrder()
{
    std::vector<Order_For_JobManagement> result = orderlist_jobmanagement_;
    orderlist_jobmanagement_.clear();

    return result;
}

bool OrderManagement::HasData_ForDB()
{
    return !datalist_db_.empty();
}

std::vector<Data_For_DB> OrderManagement::GetData()
{
    std::vector<Data_For_DB> result = datalist_db_;
    datalist_db_.clear();

    return result;
}

void OrderManagement::slot_receive_msg(Message_SendTo_Server msg)
{
    //std::cout<<"ordermanagement: "<<"get a msg\n";
    switch (msg.type)
    {
    case Protocol_SendMealSystem::MESSAGE_TYPE_CARS_USEFUL:
    {
        std::cout << "ordermanagement: "
                  << "get a CARS_USEFUL\n";

        std::vector<int> cars = default_ask_car_useful();
        Protocol_SendMealSystem::Message_From_Server msg;
        msg.type = Protocol_SendMealSystem::MESSAGE_TYPE_CARS_USEFUL;
        msg.size = cars.size();
        for (int i = 0; i < cars.size(); i++)
        {
            msg.data[i] = cars[i];
        }

        sig_send_msg(std::move(msg));
    }
    break;
    case Protocol_SendMealSystem::MESSAGE_TYPE_CUSTOMER_TAGS:
    {
        std::cout << "ordermanagement: "
                  << "get a CUSTOMER_TAGS\n";

        std::vector<int> tags = default_ask_customer_tags();
        Protocol_SendMealSystem::Message_From_Server msg;
        msg.type = Protocol_SendMealSystem::MESSAGE_TYPE_CUSTOMER_TAGS;
        msg.size = tags.size();
        for (int i = 0; i < tags.size(); i++)
        {
            msg.data[i] = tags[i];
        }

        sig_send_msg(std::move(msg));
    }
    break;
    case Protocol_SendMealSystem::MESSAGE_TYPE_ORDER:
    {
        std::cout << "ordermanagement: "
                  << "get an order:"<< msg.info.order.data.car_id<<std::endl;

        Order_For_OrderManagement order;
        order.car_id = msg.info.order.data.car_id;
        switch (msg.info.order.type)
        {
        case Protocol_SendMealSystem::ORDER_TYPE_DELIVERY:
            order.type = ORDERTYPE_RESTAURANT_DELEVER;
            break;
        case Protocol_SendMealSystem::ORDER_TYPE_RECEPTION:
            order.type = ORDERTYPE_RESTAURANT_RECYCLE;
            break;
        default:
            break;
        }
        order.target_pos = msg.info.order.data.target;
        order.act = ORDERACTION_ACT;

        Add_Order(order);
    }

    break;
    default:
        break;
    }
}

std::vector<int> OrderManagement::default_ask_car_useful()
{
    std::vector<int> cars;
    for (int i = 1; i < 5; i++)
    {
        cars.push_back(i);
    }

    return cars;
}

std::vector<int> OrderManagement::default_ask_customer_tags()
{
    // std::vector<int> tags;
    // for(int i=1;i<5;i++)
    // {
    //     tags.push_back(test_customers_[i]);
    //     //tags.push_back(i+1);
    // }

    // return tags;
    return test_customers_;
}

void OrderManagement::Test_Init_Cars(std::vector<int> init_cars)
{
    test_cars_ = init_cars;
}
void OrderManagement::Test_Init_Customers(std::vector<int> init_customers)
{
    test_customers_ = init_customers;
}

void OrderManagement::test_set_car_unusable(int car_id)
{
    //todo
}
void OrderManagement::test_set_car_usable(int car_id)
{
    //todo
}

void OrderManagement::thread_act_order()
{
    std::vector<Order_For_JobManagement> tmp_vec;
    while (true)
    {
        usleep(1000);
        std::lock_guard<std::mutex> lock(mutex_orderlist_jobmanagement_);
        if(!orderlist_jobmanagement_.empty())
        {
            for(auto order : orderlist_jobmanagement_)
            {
                tmp_vec.push_back(order);
            }
            orderlist_jobmanagement_.clear();
        }
        else{
            continue;
        }

        for(auto order : tmp_vec)
        {
            std::cout<<" OrderManagement::thread_act_order: "<<order.data.car_id<<std::endl;
            jobclient_->Act_Order(order);
        }
    }
}