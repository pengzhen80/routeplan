#include<string>
#ifndef DBMANAGEMENT_COMMON
#define DBMANAGEMENT_COMMON
namespace dbmanagement_common
{
     struct Goods_Info
    {
        std::string name;
    };
    struct Order_Data
    {
        Goods_Info goods_info;
        int goods_pos;
        int target_pos;
    };
    struct Order
    {
        int number;
        int time;
        Order_Data data;
        // ORDERTYPE type;
        // ORDERRESULT result;
        std::string type;
        std::string result;
    }; 
} 
#endif 