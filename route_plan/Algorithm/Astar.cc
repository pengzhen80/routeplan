#include <stack>
#include <unordered_set>
#include "Astar.h"

float DistanceOfNode(MyNode n1, MyNode n2)
{
	float x = (n1.pos.x - n2.pos.x) > 0 ? (n1.pos.x - n2.pos.x) : (n2.pos.x - n1.pos.x);
	float y = (n1.pos.y - n2.pos.y) > 0 ? (n1.pos.y - n2.pos.y) : (n2.pos.y - n1.pos.y);
	float z = (n1.pos.z - n2.pos.z) > 0 ? (n1.pos.z - n2.pos.z) : (n2.pos.z - n1.pos.z);
	return x + y + z;
}

// set values by id and e_id
void AstarRoute::SetValuesById(const int id, const int p_id, const int e_id)
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

void AstarRoute::InitNodelist()
{
	for (int i = 0; i < nodelist_.size(); i++)
	{
		nodelist_[i].f = -1.0;
		nodelist_[i].g = -1.0;
		nodelist_[i].h = -1.0;
		nodelist_[i].parent_id = -1;
	}
}

AstarRoute::AstarResult AstarRoute::RouteByEndid(int e_id)
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

//get node by id
AstarNode *AstarRoute::GetNodeById(const int id)
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

//h value is distance = |node.x-end.x| + |node.y-end.y|
//need to do: used "+" ,so if the number is very big ,maybe need some protection
float AstarRoute::GetHvalue(AstarNode &node, const int e_id)
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
float AstarRoute::GetFvalue(const int id)
{
	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		return ERRORNUM;
	}

	return node->f;
}

std::vector<int> AstarRoute::GetNeiborsbyId(const int id)
{
	AstarNode *node = GetNodeById(id);
	if (!node)
	{
		std::vector<int> vec;
		return vec;
	}
	return node->node.neighbors;
}

AstarRoute::AstarResult AstarRoute::Route(const int s_id, const int e_id)
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

void AstarRoute::Init(Vec_MyNode &nodelist)
{
	nodelist_.clear();
	for (int i = 0; i < nodelist.size(); i++)
	{
		nodelist_.push_back(AstarNode(nodelist[i]));
	}
}