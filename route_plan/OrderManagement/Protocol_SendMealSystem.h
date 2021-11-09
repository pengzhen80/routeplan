
#ifndef PROTOCOL_SENDMEALSYSTEM
#define PROTOCOL_SENDMEALSYSTEM
namespace Protocol_SendMealSystem{
#define TINKERBOARD_SERVER_NETWORK_TARGET_PORT 2979

#pragma pack(push, 1)

enum ORDER_TYPE{
    ORDER_TYPE_DELIVERY = 0,
    ORDER_TYPE_RECEPTION = 1,
};

struct Goods_Info {
    char name[100];
};

struct Order_Data {
    Goods_Info goods_info;
    int position;
    int target;
    int car_id;
};

struct Order{
    int number;
    ORDER_TYPE type;
    Order_Data data;
};

enum MESSAGE_TYPE
{
    MESSAGE_TYPE_CARS_USEFUL=0,
    MESSAGE_TYPE_CUSTOMER_TAGS,
    MESSAGE_TYPE_ORDER,
};

//Server message
struct Message_From_Server
{
    MESSAGE_TYPE type;
    int size;
    int data[1024];
};

//TinkerBoard message
struct Message_SendTo_Server_Info
{
    Order order;
};
struct Message_SendTo_Server
{
    MESSAGE_TYPE type;
    Message_SendTo_Server_Info info;
};
#pragma pack(pop)

}

#endif