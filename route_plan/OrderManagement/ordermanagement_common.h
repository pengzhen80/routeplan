#include <string>
#ifndef ORDERMANAGEMENT_COMMON
#define ORDERMANAGEMENT_COMMON
namespace ordermangement_common
{
    enum ORDERTYPE
    {
        ORDERTYPE_RESTAURANT_DELEVER = 0,
        ORDERTYPE_RESTAURANT_RECYCLE,
        ORDERTYPE_STOREHOUSE,
    };
    enum ORDERSTATE
    {
        ORDERSTATE_UNINIT = 0,
        ORDERSTATE_INIT,
        ORDERSTATE_ACT,
        ORDERSTATE_FINISH,
        ORDERSTATE_CANCEL,
    };
    enum ORDERACTION
    {
        ORDERACTION_ACT = 0,
        ORDERACTION_CANCEL,
    };
    enum ORDERRESULT
    {
        ORDERRESULT_SUCCESS = 0,
        ORDERRESULT_FAILURE,
        ORDERRESULT_DEFAULT,
    };

    struct Goods_Info
    {
        std::string name;
    };

    struct Order_For_OrderManagement
    {
        int car_id = -1;
        int goods_pos;
        int target_pos;
        ORDERTYPE type = ORDERTYPE_RESTAURANT_DELEVER;
        ORDERACTION act = ORDERACTION_ACT;
        Goods_Info info;
    };

    struct Order_Data
    {
        Goods_Info goods_info;
        int goods_pos;
        int target_pos;
        int car_id = -1;
    };
    struct OrderManagement_Order
    {
        int number;
        std::string time;
        ORDERTYPE type = ORDERTYPE_RESTAURANT_DELEVER;
        Order_Data data;
        ORDERSTATE state;
        int weight;
        ORDERACTION action;
        ORDERRESULT result;
    };

    struct Data_For_DB
    {
        int number;
        int time;
        Order_Data data;
        std::string type;
        std::string result;
    };
    struct Order_For_JobManagement
    {
        int number;
        Order_Data data;
        ORDERACTION action;
    };
}
#endif