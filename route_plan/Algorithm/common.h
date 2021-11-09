#ifndef MYMAP
#define MYMAP
#include <vector>
struct Position
{
    float x;
    float y;
    float z;
};

struct MyNode
{
    int id;
    Position pos;
    std::vector<int> neighbors;
};

typedef std::vector<MyNode> Vec_MyNode;

#endif