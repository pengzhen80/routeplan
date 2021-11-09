#include <vector>

#include "configuration_common.h"

#ifndef MAPMANAGER
#define MAPMANAGER

class MapManager
{
public:
    void Init(Configuration_Map map);
    std::vector<int> Get_CustomerTags();

private:
    struct Configuration_Map map_;
};

#endif