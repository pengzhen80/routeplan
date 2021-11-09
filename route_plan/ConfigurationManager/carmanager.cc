#include "carmanager.h"

void CarManager::Init(Configuration_Car cars)
{
    cars_ = cars;
}
int CarManager::GetCarNum()
{
    return cars_.car_num;
}
std::vector<int> CarManager::GetCarUseful()
{
    return cars_.car_useful;
}