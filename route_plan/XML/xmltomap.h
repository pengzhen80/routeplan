#include"common.h"
#include<vector>

Map ReadValueFromXML(const char *XmlPath);
std::vector<float> MakePosition(std::string str_pos);
std::vector<int> MakeNeighbors(std::string str_neighbors);
Vec_MyNode XmlMapToMyMap(Map map);
std::vector<MyTypeNode> XmlMapToMyMap_Type(Map map);
std::vector<int> GetCustomers(Map map);
