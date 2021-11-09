#include<vector>
//#include<csignal>
#include"common.h"

#define ERRORNUM -1.0
#define WEIGHT 10

#ifndef ASTARNODE
#define ASTARNODE
struct AstarNode{
  MyNode node;
  int parent_id = -1;
  float g=-1.0, h=-1.0, f=-1.0;
  bool operator<(const AstarNode& n) const {
    return f < n.f;
  }
  AstarNode(MyNode n) :node(n) {}
};

typedef std::vector<AstarNode> Vec_AstarNode;
#endif

class AstarRoute
{
public:

struct AstarResult
{
  std::vector<int> route;
  float distance;
};

  explicit AstarRoute(){
    // for(int i=0;i<nodelist.size();i++)
    // {
    //   nodelist_.push_back(AstarNode(nodelist[i]));
    // }
  }
  void Init(Vec_MyNode& nodelist);
  AstarResult Route(int s_id,int e_id);
private:
  void InitHvaluebyEndid(const int e_id);

  
  AstarResult RouteByEndid(int e_id);
  //if route is returned , need to init nodelists' values;
  void InitNodelist();
  
  void SetValuesById(const int id, const int p_id,const int e_id);

  float GetHvalue(AstarNode& node, const int e_id);
  AstarNode* GetNodeById(const int id);
  float GetFvalue(const int id);
  std::vector<int> GetNeiborsbyId(const int id);
private:
  //std::vector<std::vector<int>> map_;
  Vec_AstarNode nodelist_;
};
