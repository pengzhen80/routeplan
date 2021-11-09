#include<vector>
#include"common.h"
#include<unordered_map>
#include<unordered_set>
#include<iostream>

#define ERRORNUM -1.0
#define WEIGHT 10
#define MAPMAXSIZE 1000

#ifndef ASTARNODE
#define ASTARNODE
struct AstarNode {
	MyNode node;
	int parent_id = -1;
	float g = -1.0, h = -1.0, f = -1.0;
	bool operator<(const AstarNode& n) const {
		return f < n.f;
	}
	AstarNode(MyNode n) :node(n) {}
};

typedef std::vector<AstarNode> Vec_AstarNode;
#endif

#ifndef COASTARNODE
#define COASTARNODE
struct CoAstar_Parent
{
	int tag_id = -1;
	int t = 0;
};

struct CoAstarNode
{
	MyNode node;
	int t;
	CoAstar_Parent parent;

	float g = -1.0, h = -1.0, f = -1.0;
	bool operator<(const AstarNode& n) const {
		return f < n.f;
	}
	CoAstarNode(MyNode n) :node(n) {}
	CoAstarNode() {}
};

typedef std::vector<CoAstarNode> Vec_CoAstarNode;
#endif

class CooperativeAstar
{
public:
	struct Node_Space_Time
	{
		int tag_id;
		int t;
	};
	struct Node_Path_Ask
	{
		int car_id;
		int position;
		int target;
	};
	typedef std::vector<Node_Path_Ask> Vec_Path_Ask;


	struct AstarResult
	{
		std::vector<int> route;
		float distance;
	};

	enum ENUM_ACTION
	{
		ACTION_DIST = 0,
		ACTION_WAIT,
		ACTION_MOVE,
		ACTION_EAST,
		ACTION_SOUTH,
		ACTION_WEST,
		ACTION_NORTH,
	};
	struct  Node_CoPath
	{
		int t;
		int tag_id;
		ENUM_ACTION action = ACTION_WEST;
	};
	typedef	std::vector<Node_CoPath> Vec_CoPath;

  struct CoAstarResult
  {
    int car_id;
    int position;
    int target;
    Vec_CoPath path;
  };

	typedef std::vector<AstarResult> Vec_AstarResult;
	typedef std::vector<CoAstarResult>  Vec_CoAstarResult;

	struct Reservation_Table
	{
		std::unordered_map<int, int> carId_vecPathIndex;
		//std::vector<std::vector<int>> vec_path;
		std::vector<Vec_CoPath> vec_path;
		std::unordered_set<int> set_covered;
	};

public:

	explicit CooperativeAstar() {
		d_ = 50;
	};
	void Init(Vec_MyNode& nodelist);
	std::vector<AstarNode> ConvertMap(Vec_MyNode nodelist);
	AstarResult Route(int s_id, int e_id);
	Vec_CoAstarResult Co_Route(Vec_Path_Ask vec_path_ask);
protected:
	void InitConodelist(Vec_MyNode map);

	AstarResult RouteByEndid(int e_id);
	Vec_CoPath RouteByEndid_Time(int e_id,int t);
	void InitNodelist();

	void SetValuesById(const int id, const int p_id, const int e_id);
	void SetValuesByCoNode(const CoAstarNode tag, const CoAstarNode parent, const int e_id);

	float GetHvalue(AstarNode& node, const int e_id);
	AstarNode* GetNodeById(const int id);
	CoAstarNode* GetCoNodeByIdTime(const int id, const int t);
	float GetFvalue(const int id);
	float GetFvalue_Time(const int id, const int t);
	std::vector<int> GetNeiborsbyId(const int id);
	AstarResult Route_MultiUnits(int s_id, int e_id, std::unordered_set<int> set_tag_covered);
	Vec_CoPath Route_TimeSpace(int s_id, int e_id, int cur_t);
	std::vector<int> GetNeiborsbyId_MultiUnits(const int id, std::unordered_set<int> set_tag_covered);
	std::vector<Node_Space_Time> GetNeiborsbyId_SpaceTime(const int id, const int t);
	void ClearParent(int cur_t);
	float DistanceOfNode(MyNode n1, MyNode n2);
private:
	//std::vector<std::vector<int>> map_;
	Vec_AstarNode nodelist_;
	std::vector<Vec_CoAstarNode> co_nodelist_;
	std::unordered_set<int> set_exist_node_id_; // to check wrong nodes in neighbors

	int d_;
	Reservation_Table reservation_table_;
};

//class CooperativeAstar : protected AstarRoute
//{
//public:
//	struct Node_Path_Ask
//	{
//		int car_id;
//		int position;
//		int target;
//	};
//	typedef std::vector<Node_Path_Ask> Vec_Path_Ask;
//	struct Node_CAstar_Result
//	{
//		int car_id;
//
//	};
//	struct SpaceTime_Map
//	{
//		Vec_AstarNode space_map;
//		int t;
//	};
//
//	enum ENUM_ACTION
//	{
//		ACTION_DIST = 0,
//		ACTION_WAIT ,
//		ACTION_EAST,
//		ACTION_SOUTH,
//		ACTION_WEST,
//		ACTION_NORTH,
//	};
//	struct Node_Route_State
//	{
//		int tag_id;
//		ENUM_ACTION action = ACTION_WAIT;
//	};
//	typedef std::vector<Node_Route_State> Vec_Route_State;
//	struct Reservation_Table
//	{
//		std::unordered_map<int, int> set_intersection_cell;
//		std::vector<SpaceTime_Map> space_time_map;
//	};
//public:
//	void InitSpaceTime_Map(int d, Vec_MyNode& nodelist);
//	std::vector<Node_Route_State> PathPlan(Vec_Path_Ask vec_ask);
//private:
//	Vec_Route_State ReverseRoute(int position, int target,int t);
//private:
//	Reservation_Table reservation_table_;
//	Vec_AstarNode space_map_;
//	//std::unordered_map
//};
