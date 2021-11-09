#include<string>
#include<vector>

#ifndef CARNODE
#define CARNODE

struct Resolution
{
    std::string bg;
    std::string realworld;
};

struct cCarDrivingNode
{
    //int size = 6;
    std::string name;
    std::string nodetype;
    std::string speed;
    std::string pos;
    std::string rfid;
    std::string relativenode;
};

typedef std::vector<cCarDrivingNode> Vec_node;

//std::vector<std::string> Node_Attributes = {"Name","NodeType","Speed","Pos","RFID","RelativeNode"};

struct Data
{
    std::string pos;
    std::string time;
};
struct cCurveWithTime
{
    std::string name;
    std::string count;
    std::string lod;
    Data data;
};
struct cCarDrivingPath
{
    std::string name;
    std::string startnode;
    std::string endnode;
    std::string nodetype;
    std::string speed;
    cCurveWithTime time;
};

typedef std::vector<cCarDrivingPath> Vec_path;

struct Map
{
    Vec_node vec_node;
    Vec_path vec_path;
    Resolution resol;
};
#endif


#ifndef MYMAP
#define MYMAP
struct Position
{
    float x;
    float y;
    float z;
};

struct MyNode
{
    int id;
    //int type;
    Position pos;
    std::vector<int> neighbors;
};

struct MyTypeNode
{
    int id;
    int type;
    Position pos;
    std::vector<int> neighbors;
};

typedef std::vector<MyNode> Vec_MyNode;

#endif