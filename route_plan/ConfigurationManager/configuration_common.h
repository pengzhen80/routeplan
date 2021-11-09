#include<vector>

#ifndef CONFIGURATION_COMMON
#define CONFIGURATION_COMMON

struct Configuration_Car
{
    int car_num;
    std::vector<int> car_useful;
};

struct Configuration_Map
{
    std::vector<int> customer_tags;
};

#endif
