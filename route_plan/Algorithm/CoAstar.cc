#include <stack>
#include <unordered_set>
#include "CoAstar.h"

float CooperativeAstar::DistanceOfNode(MyNode n1, MyNode n2)
{
	float x = (n1.pos.x - n2.pos.x) > 0 ? (n1.pos.x - n2.pos.x) : (n2.pos.x - n1.pos.x);
	float y = (n1.pos.y - n2.pos.y) > 0 ? (n1.pos.y - n2.pos.y) : (n2.pos.y - n1.pos.y);
	float z = (n1.pos.z - n2.pos.z) > 0 ? (n1.pos.z - n2.pos.z) : (n2.pos.z - n1.pos.z);
	return x + y + z;
}

// set values by id and e_id
void CooperativeAstar::SetValuesById(const int id, const int p_id, const int e_id)
{
	for (int i = 0; i < nodelist_.size(); i++)
	{
		if (id == nodelist_[i].node.id)
		{
			AstarNode *p_node = GetNodeById(p_id);
			if (nodelist_[i].parent_id > 0)
			{
				float new_g_value = DistanceOfNode(nodelist_[i].node, p_node->node) + p_node->g;
				if (new_g_value < nodelist_[i].g)
				{
					nodelist_[i].g = new_g_value;
					nodelist_[i].f = nodelist_[i].g + nodelist_[i].h;
					nodelist_[i].parent_id = p_id;
				}
			}
			else
			{
				nodelist_[i].parent_id = p_id;
				//set g,h,f value
				nodelist_[i].g = DistanceOfNode(nodelist_[i].node, p_node->node);
				nodelist_[i].h = DistanceOfNode(nodelist_[i].node, GetNodeById(e_id)->node);
				nodelist_[i].f = nodelist_[i].g + nodelist_[i].h;
			}
			break;
		}
	}
}

void CooperativeAstar::SetValuesByCoNode(const CoAstarNode tag, const CoAstarNode parent, const int e_id)
{
	int t = tag.t;
	int id = tag.node.id;
	for (int i = 0; i < co_nodelist_[t].size(); i++)
	{
		if (id == co_nodelist_[t][i].node.id)
		{
			CoAstarNode *p_node = GetCoNodeByIdTime(parent.node.id, parent.t);
			if (co_nodelist_[t][i].parent.tag_id>0)
			{
				float new_g_value = DistanceOfNode(co_nodelist_[t][i].node, p_node->node) + p_node->g;
				if (new_g_value < co_nodelist_[t][i].g)
				{
					co_nodelist_[t][i].g = new_g_value;
					co_nodelist_[t][i].f = co_nodelist_[t][i].g + co_nodelist_[t][i].h;
					co_nodelist_[t][i].parent.tag_id = p_node->node.id;
					co_nodelist_[t][i].parent.t = p_node->t;
				}
			}
			else
			{
				co_nodelist_[t][i].parent.tag_id = parent.node.id;
				co_nodelist_[t][i].parent.t = parent.t;
				//set g,h,f value
				co_nodelist_[t][i].g = DistanceOfNode(co_nodelist_[t][i].node, p_node->node);
				co_nodelist_[t][i].h = DistanceOfNode(co_nodelist_[t][i].node, GetNodeById(e_id)->node);
				co_nodelist_[t][i].f = nodelist_[i].g + co_nodelist_[t][i].h;
			}
			break;
		}
	}
}

void CooperativeAstar::InitNodelist()
{
	for (int i = 0; i < nodelist_.size(); i++)
	{
		nodelist_[i].f = -1.0;
		nodelist_[i].g = -1.0;
		nodelist_[i].h = -1.0;
		nodelist_[i].parent_id = -1;
	}
}

CooperativeAstar::AstarResult CooperativeAstar::RouteByEndid(int e_id)
{
	AstarResult result;

	std::stack<int> s_result;
	std::vector<int> vec_result;
	int id = e_id;

	while (GetNodeById(id)->parent_id > 0)
	{
		s_result.push(id);
		id = GetNodeById(id)->parent_id;
	}
	s_result.push(id);

	while (!s_result.empty())
	{
		vec_result.push_back(s_result.top());
		s_result.pop();
	}
	result.route = vec_result;

	float distance = 0.0;
	for (int i = 0; i < vec_result.size() - 1; i++)
	{
		distance += DistanceOfNode(GetNodeById(vec_result[i])->node, GetNodeById(vec_result[i + 1])->node);
	}
	result.distance = distance;

	InitNodelist();
	return result;
}

CooperativeAstar::Vec_CoPath CooperativeAstar::RouteByEndid_Time(int e_id, int t)
{
	Vec_CoPath result;

	std::stack<int> s_result;
	std::vector<int> vec_result;
	int id = e_id;

	while (GetCoNodeByIdTime(id,t)->parent.tag_id > 0)
	{
		s_result.push(id);
		id = GetCoNodeByIdTime(id, t)->parent.tag_id;
	}
	s_result.push(id);

	while (!s_result.empty())
	{
		vec_result.push_back(s_result.top());
		s_result.pop();
	}
	for (int i = 0; i < vec_result.size(); i++)
	{
		Node_CoPath co_node;
		co_node.tag_id = vec_result[i];
		result.push_back(co_node);
	}

	//float distance = 0.0;
	//for (int i = 0; i < vec_result.size() - 1; i++)
	//{
	//	distance += distanceofnode(getnodebyid(vec_result[i])->node, getnodebyid(vec_result[i + 1])->node);
	//}
	//result.distance = distance;

	//initnodelist();
	return result;
}

//get node by id
AstarNode *CooperativeAstar::GetNodeById(const int id)
{
	for (int i = 0; i < nodelist_.size(); i++)
	{
		if (id == nodelist_[i].node.id)
		{
			return &nodelist_[i];
		}
	}
	return nullptr;
}

CoAstarNode* CooperativeAstar::GetCoNodeByIdTime(const int id, const int t)
{
	for (int i = 0; i < co_nodelist_[t].size(); i++)
	{
		if (id == co_nodelist_[t][i].node.id)
		{
			return &co_nodelist_[t][i];
		}
	}
	return nullptr;
}

//h value is distance = |node.x-end.x| + |node.y-end.y|
//need to do: used "+" ,so if the number is very big ,maybe need some protection
float CooperativeAstar::GetHvalue(AstarNode &node, const int e_id)
{
	if (node.h > 0.0)
	{
		return node.h;
	}
	//get end node
	AstarNode *e_node = GetNodeById(e_id);
	if (!e_node)
	{
		return ERRORNUM;
	}

	float x = (node.node.pos.x - e_node->node.pos.x) > 0.000000 ? (node.node.pos.x - e_node->node.pos.x) : (e_node->node.pos.x - node.node.pos.x);
	float y = (node.node.pos.y - e_node->node.pos.y) > 0.000000 ? (node.node.pos.y - e_node->node.pos.y) : (e_node->node.pos.y - node.node.pos.y);
	node.h = x + y;
	return node.h;
}

// get F value by id
float CooperativeAstar::GetFvalue(const int id)
{
	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		return ERRORNUM;
	}

	return node->f;
}
float CooperativeAstar::GetFvalue_Time(const int id, const int t)
{
	CoAstarNode *node = GetCoNodeByIdTime(id,t);
	if (!node)
	{
		return ERRORNUM;
	}

	return node->f;
}

std::vector<int> CooperativeAstar::GetNeiborsbyId(const int id)
{
	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		std::vector<int> vec;
		return vec;
	}
	return node->node.neighbors;
}

std::vector<int> CooperativeAstar::GetNeiborsbyId_MultiUnits(const int id, std::unordered_set<int> set_tag_covered)
{
	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		std::vector<int> vec;
		return vec;
	}
	std::vector<int> vec_result;
	for (int i = 0; i < node->node.neighbors.size(); i++)
	{
		if (set_tag_covered.count(node->node.neighbors[i]) == 0)
		{
			vec_result.push_back(node->node.neighbors[i]);
		}
	}
	return vec_result;
}

std::vector<CooperativeAstar::Node_Space_Time> CooperativeAstar::GetNeiborsbyId_SpaceTime(const int id, const int t)
{
	int map_size = MAPMAXSIZE;
	std::vector<Node_Space_Time> vec_result;

	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		vec_result.clear();
		return vec_result;
	}
	for (int i = 0; i < node->node.neighbors.size(); i++)
	{
		if (reservation_table_.set_covered.count(node->node.neighbors[i] + t * map_size) == 0)
		{
			Node_Space_Time st_node;
			st_node.tag_id = node->node.neighbors[i];
			st_node.t = t;
			vec_result.push_back(st_node);
		}
	}
	return vec_result;
}


CooperativeAstar::AstarResult CooperativeAstar::Route(const int s_id, const int e_id)
{
	if (s_id == e_id)
	{
		AstarResult result;
		result.route.push_back(s_id);
		return result;
	}
	std::vector<int> open_ids;
	std::unordered_set<int> close_ids;
	for (int i = 0; i < nodelist_.size(); i++)
	{
		if (s_id == nodelist_[i].node.id)
		{
			open_ids.push_back(s_id);
			break;
		}
	}

	while (open_ids.size() > 0)
	{
		// find the smallest f in openlist
		int minf_id = open_ids[0];
		int minf_index = 0;
		int length = open_ids.size();
		for (int i = 1; i < length; i++)
		{
			if (GetFvalue(open_ids[i]) < GetFvalue(minf_id))
			{
				minf_id = open_ids[i];
				minf_index = i;
			}
		}
		//push the neighbors to openlist and define the values and drop the cur_node to closelist
		//drop the cur node
		int tmp = open_ids[minf_index];
		open_ids[minf_index] = open_ids[length - 1];
		open_ids[length - 1] = open_ids[minf_index];
		open_ids.pop_back();
		//add to closelist;
		close_ids.insert(minf_id);
		//push neighbors and update values
		std::vector<int> vec_neis = GetNeiborsbyId(minf_id);
		for (int id : vec_neis)
		{
			if (id == e_id)
			{
				AstarNode *tmp = GetNodeById(id);
				tmp->parent_id = minf_id;
				return RouteByEndid(e_id);
			}
			if (close_ids.count(id) == 0)
			{
				open_ids.push_back(id);
				//set values by parent_id;
				SetValuesById(id, minf_id, e_id);
			}
		}
	}

	//if no path
	//return RouteByEndid(e_id);
	AstarResult result;
	result.route.clear();
	return result;
}

CooperativeAstar::AstarResult CooperativeAstar::Route_MultiUnits(int s_id, int e_id, std::unordered_set<int> set_tag_covered)
{
	AstarResult result;
	if (s_id == e_id)
	{
		result.route.push_back(s_id);
		return result;
	}
	std::vector<int> open_ids;
	std::unordered_set<int> close_ids;
	for (int i = 0; i < nodelist_.size(); i++)
	{
		if (s_id == nodelist_[i].node.id)
		{
			open_ids.push_back(s_id);
			break;
		}
	}

	if (set_tag_covered.count(e_id) > 0)
	{
		//set_tag_covered.erase(e_id);
		result.route.clear();
		return 	 result;
	}

	while (open_ids.size() > 0)
	{
		// find the smallest f in openlist
		int minf_id = open_ids[0];
		int minf_index = 0;
		int length = open_ids.size();
		for (int i = 1; i < length; i++)
		{
			if (GetFvalue(open_ids[i]) < GetFvalue(minf_id))
			{
				minf_id = open_ids[i];
				minf_index = i;
			}
		}
		//push the neighbors to openlist and define the values and drop the cur_node to closelist
		//drop the cur node
		int tmp = open_ids[minf_index];
		open_ids[minf_index] = open_ids[length - 1];
		open_ids[length - 1] = open_ids[minf_index];
		open_ids.pop_back();
		//add to closelist;
		close_ids.insert(minf_id);
		//push neighbors and update values
		std::vector<int> vec_neis = GetNeiborsbyId_MultiUnits(minf_id, set_tag_covered);
		for (int id : vec_neis)
		{
			if (id == e_id)
			{
				AstarNode *tmp = GetNodeById(id);
				tmp->parent_id = minf_id;
				return RouteByEndid(e_id);
			}
			if (close_ids.count(id) == 0)
			{
				open_ids.push_back(id);
				//set values by parent_id;
				SetValuesById(id, minf_id, e_id);
			}
		}
	}

	//if no path
	//return RouteByEndid(e_id);
	//AstarResult result;
	result.route.clear();
	return result;
}

void CooperativeAstar::ClearParent(int cur_t)
{
	for (int i = 0; i < co_nodelist_[cur_t].size(); i++)
	{
		co_nodelist_[cur_t][i].parent.tag_id = -1;
	}
}

CooperativeAstar::Vec_CoPath CooperativeAstar::Route_TimeSpace(int s_id, int e_id, int cur_t)
{
	int map_size = MAPMAXSIZE;
	Vec_CoPath result;
	if (s_id == e_id)
	{
		Node_CoPath node;
		node.tag_id = s_id;
		node.t = cur_t;
		node.action = ACTION_DIST;
		result.push_back(node);
		return result;
	}

	std::vector<int> open_ids;
	std::unordered_set<int> close_ids;
	for (int i = 0; i < co_nodelist_[cur_t].size(); i++)
	{
		if (s_id == co_nodelist_[cur_t][i].node.id)
		{
			open_ids.push_back(s_id+cur_t*map_size);
			break;
		}
	}

	ClearParent(cur_t);

	if (reservation_table_.set_covered.count(e_id + map_size * cur_t) > 0)
	{
		Node_CoPath node;
		node.tag_id = s_id;
		node.t = cur_t;
		node.action = ACTION_WAIT;
		result.push_back(node);
		return result;
	}

	while (open_ids.size() > 0)
	{
		// find the smallest f in openlist
		int minf_open_id = open_ids[0];
		int minf_open_index = 0;

		int minf_tag_id = -1;
		int minf_tag_t = 0;
		if (minf_open_id % map_size == 0)
		{
			minf_tag_id = map_size;
			minf_tag_t = minf_open_id / map_size - 1;
		}
		else
		{
			minf_tag_id = minf_open_id % map_size;
			minf_tag_t = minf_open_id / map_size;
		}
		
		int length = open_ids.size();
		for (int i = 1; i < length; i++)
		{
			int tmp_id = -1;
			int tmp_t = 0;
			if (open_ids[i] % map_size == 0)
			{
				tmp_id = map_size;
				tmp_t = open_ids[i] / map_size - 1;
			}
			else
			{
				tmp_id = open_ids[i] % map_size;
				tmp_t = open_ids[i] / map_size;
			}

			if (GetFvalue_Time(tmp_id, tmp_t) < GetFvalue_Time(minf_tag_id, minf_tag_t))
			{
				minf_open_id = open_ids[i];
				minf_open_index = i;
				if (minf_open_id % map_size == 0)
				{
					minf_tag_id = map_size;
					minf_tag_t = minf_open_id / map_size - 1;
				}
				else
				{
					minf_tag_id = minf_open_id % map_size;
					minf_tag_t = minf_open_id / map_size;
				}
			}
		}
		//push the neighbors to openlist and define the values and drop the cur_node to closelist
		//drop the cur node
		int tmp = open_ids[minf_open_index];
		open_ids[minf_open_index] = open_ids[length - 1];
		open_ids[length - 1] = open_ids[minf_open_index];
		open_ids.pop_back();
		//add to closelist;
		close_ids.insert(minf_open_id);
		if (close_ids.size() > map_size / 2)
		{
			break;
		}
		//push neighbors and update values
		std::vector<Node_Space_Time> vec_neis = GetNeiborsbyId_SpaceTime(minf_tag_id, minf_tag_t);
		for (Node_Space_Time tag : vec_neis)
		{
			if (tag.tag_id == e_id)
			{
				CoAstarNode *tmp = GetCoNodeByIdTime(tag.tag_id,tag.t);
				tmp->parent.tag_id = minf_tag_id;
				tmp->parent.t = minf_tag_t;
				Vec_CoPath co_result =  RouteByEndid_Time(tag.tag_id,tag.t);
				for (int i = 0; i < co_result.size() - 1; i++)
				{
					Node_CoPath node;
					node.tag_id = co_result[i].tag_id;
					node.t = cur_t + i;
					node.action = ACTION_MOVE;
					result.push_back(node);
				}
				Node_CoPath node;
				node.tag_id = co_result[co_result.size() - 1].tag_id;
				node.t = cur_t + co_result.size() - 1;
				node.action = ACTION_DIST;
				result.push_back(node);
				return result;
			}
			if (close_ids.count(tag.tag_id+map_size*tag.t) == 0)
			{
				if(set_exist_node_id_.count(tag.tag_id)==0)
				{
					continue;
				}
				open_ids.push_back(tag.tag_id+map_size*tag.t);
				//set values by parent_id;
				//SetValuesById(tag.tag_id, minf_id, e_id);
				CoAstarNode node;
				node.t = tag.t;
				node.node.id = tag.tag_id;

				CoAstarNode parent;
				parent.t = cur_t;
				parent.node.id = minf_tag_id;

				SetValuesByCoNode(node, parent, e_id);
			}
		}
	}
	result.clear();
	return result;
}


void CooperativeAstar::Init(Vec_MyNode &nodelist)
{
	nodelist_.clear();
	for (int i = 0; i < nodelist.size(); i++)
	{
		nodelist_.push_back(AstarNode(nodelist[i]));
		set_exist_node_id_.insert(nodelist[i].id);
	}

	co_nodelist_.clear();
	InitConodelist(nodelist);
}

void CooperativeAstar::InitConodelist(Vec_MyNode map)
{
	for (int i = 0; i < d_; i++)
	{
		Vec_CoAstarNode vec_costarnode;
		for (int j = 0; j < map.size(); j++)
		{
			CoAstarNode node(map[j]);
			node.t = i;
			vec_costarnode.push_back(node);
		}
		co_nodelist_.push_back(vec_costarnode);
	}

}

std::vector<AstarNode> CooperativeAstar::ConvertMap(Vec_MyNode nodelist)
{
	std::vector<AstarNode> vec_result;
	for (int i = 0; i < nodelist.size(); i++)
	{
		vec_result.push_back(AstarNode(nodelist[i]));
	}
	return vec_result;
}

CooperativeAstar::Vec_CoAstarResult CooperativeAstar::Co_Route(Vec_Path_Ask vec_path_ask)
{
	int map_size = MAPMAXSIZE;

	reservation_table_.carId_vecPathIndex.clear();
	reservation_table_.vec_path.clear();
	reservation_table_.set_covered.clear();

	std::vector<int> vec_index_left;
	std::vector<int> tmp_index_left;

	for (int t = 0; t < d_&&t<vec_path_ask.size(); t++)
	{
		tmp_index_left.clear();
		if (t == 0)
		{
			for (int i = 0; i < vec_path_ask.size(); i++)
			{
				vec_index_left.push_back(i);
				reservation_table_.set_covered.insert(vec_path_ask[i].position + t * map_size);
			}

			tmp_index_left = vec_index_left;
			vec_index_left.clear();
		}
		else
		{
			tmp_index_left = vec_index_left;
			vec_index_left.clear();
		}

		for (int i = 0; i < tmp_index_left.size(); i++)
		{
			int index = tmp_index_left[i];
			int car_id = vec_path_ask[index].car_id;
			int position = vec_path_ask[index].position;
			int target = vec_path_ask[index].target;

			Vec_CoPath path = Route_TimeSpace(position, target, t);
			if (path.size() > 0)
			{
				if (reservation_table_.carId_vecPathIndex.count(car_id) > 0)
				{
					int path_index = reservation_table_.carId_vecPathIndex[car_id];
					//debug : first time use 
					reservation_table_.vec_path[path_index].insert(reservation_table_.vec_path[path_index].end(), path.begin(), path.end());
				}
				else
				{
					reservation_table_.vec_path.push_back(path);
					reservation_table_.carId_vecPathIndex.insert(std::make_pair(car_id, reservation_table_.vec_path.size() - 1));
				}

				for (int j = 1; j < path.size(); j++)
				{
					reservation_table_.set_covered.insert(path[j].tag_id + map_size * (t+j));
				}
			}
			else
			{
				reservation_table_.set_covered.insert(position + map_size * (t + 1));
				if (reservation_table_.carId_vecPathIndex.count(car_id) > 0)
				{
					int path_index = reservation_table_.carId_vecPathIndex[car_id];
					//debug : first time use 
					Node_CoPath node_copath;
					node_copath.action = ACTION_WAIT;
					node_copath.t = t;
					node_copath.tag_id = position;

					reservation_table_.vec_path[path_index].push_back(node_copath);
					vec_index_left.push_back(index);
				}
				else
				{
					Node_CoPath node_copath;
					node_copath.action = ACTION_WAIT;
					node_copath.t = t;
					node_copath.tag_id = position;

					Vec_CoPath tmp_path;
					tmp_path.push_back(node_copath);
					reservation_table_.vec_path.push_back(tmp_path);
					reservation_table_.carId_vecPathIndex.insert(std::make_pair(car_id, reservation_table_.vec_path.size() - 1));
					vec_index_left.push_back(index);
				}
			}
		}
		// if(vec_index_left.size() == tmp_index_left.size())
		// {
		// 	break;
		// }
	}
	 Vec_CoAstarResult vec_result;
	// for (int i = 0; i < reservation_table_.vec_path.size(); i++)
	// {
	// 	Vec_CoPath co_path;
	// 	co_path = reservation_table_.vec_path[i];
	// 	vec_result.push_back(co_path);
	// }

	for(int i=0;i<vec_path_ask.size();i++)
	{
		CoAstarResult result;
		result.car_id = vec_path_ask[i].car_id;
		result.position = vec_path_ask[i].position;
		result.target = vec_path_ask[i].target;

		result.path = reservation_table_.vec_path[reservation_table_.carId_vecPathIndex[result.car_id]];
		vec_result.push_back(result);
	}

	return vec_result;
}

//CooperativeAstar::Vec_Route_State CooperativeAstar:: ReverseRoute(int position, int target, int t)
//{
//	Vec_Route_State vec_route_state;
//	if (target == position)
//	{
//		Node_Route_State route_state;
//		route_state.tag_id = position;
//		route_state.action = ENUM_ACTION::ACTION_DIST;
//		vec_route_state.push_back(route_state);
//		return vec_route_state;
//	}
//	return vec_route_state;
////
//}

//void CooperativeAstar::InitSpaceTime_Map(int d, Vec_MyNode& nodelist)
//{
//	for (int i = 0; i < d; i++)
//	{
//		SpaceTime_Map st_map;
//		st_map.t = i;
//		st_map.space_map = ConvertMap(nodelist);
//		reservation_table_.space_time_map.push_back(st_map);
//	}
//}

//std::vector<CooperativeAstar::Node_Route_State> CooperativeAstar::PathPlan(Vec_Path_Ask vec_ask)
//{
//	for (int i = 0; i < vec_ask.size(); i++)
//	{
//		int t = i;
//
//		
//	}
//}