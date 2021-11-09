#include "configurationmanager.h"

void ConfigurationManager::Init(std::vector<int> cars_id,std::vector<int> tags_id)
{
    //todo
    Configuration_Car car;
    car.car_useful = cars_id;
    car.car_num = cars_id.size();

    car_manager_->Init(car);

    Configuration_Map map;
    map.customer_tags = tags_id;

    map_manager_->Init(map);
}
int ConfigurationManager::GetCarNum()
{
    return car_manager_->GetCarNum();
}
std::vector<int> ConfigurationManager::GetCar_Useful()
{
    return car_manager_->GetCarUseful();
}
std::vector<int> ConfigurationManager::GetCustomerTags()
{
    return map_manager_->Get_CustomerTags();
}