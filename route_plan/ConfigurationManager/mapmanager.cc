#include "mapmanager.h"

void MapManager::Init(Configuration_Map map)
{
    map_ = map;
}
std::vector<int> MapManager::Get_CustomerTags()
{
    return map_.customer_tags;
}