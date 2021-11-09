#include<vector>
#include<unordered_set>

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
    int type;
    Position pos;
    std::vector<int> neighbors;
};

typedef std::vector<MyNode> Vec_MyNode;

#endif

#ifndef MAPFUNC
#define MAPFUNC
Vec_MyNode Make_map(int size);
Vec_MyNode Make_map_locks(int size, std::unordered_set<int> lock_tags);
//void PushLocks(std::vector<int> lock_car_pos);
Vec_MyNode Update_XML_map_locks(Vec_MyNode map,std::unordered_set<int> lock_tags);

#endif