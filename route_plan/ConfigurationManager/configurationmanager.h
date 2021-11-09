#include<vector>

#include "configuration_common.h"
#include "carmanager.h"
#include "mapmanager.h"

#ifndef CONFIGURATIONMANAGER
#define CONFIGURATIONMANAGER

class ConfigurationManager
{
public:
    void Init(std::vector<int> cars_id,std::vector<int> tags_id);
    int GetCarNum();
    std::vector<int> GetCar_Useful();
    std::vector<int> GetCustomerTags();
private:
    CarManager *car_manager_;
    MapManager *map_manager_;
};

#endif
