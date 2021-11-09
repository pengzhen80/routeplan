#include "car.h"

// std::vector<int> Car::get_next_tags()
// {
//     std::vector<int> result;
//     for(int i=0;i<route_.size()&&i<3;i++)
//     {
//         result.push_back(route_[i]);
//     }
//     return result;
// }

void Car::update_route(std::vector<int> route)
{
    route_.clear();
    for (int i : route)
    {
        route_.push_back(route[i]);
    }
}

int Car::get_id()
{
    return car_id_;
}

void Car::set_current_path()
{
    current_path_.clear();
    int size = route_.size();
    int i = 0;
    for (; i < 3 && size; i++)
    {
        current_path_.push_back(route_[i]);
    }
    //update left route
    if (i < 3)
    {
        route_.clear();
    }
    else
    {
        std::vector<int> vec;
        for (int i = 3; i < size; i++)
        {
            vec.push_back(route_[i]);
        }
        update_route(vec);
    }
}

std::vector<int> Car::get_current_path()
{
    return current_path_;
}

bool Car::getstandby()
{
    return standby_;
}
void Car::setstandby(bool flag)
{
    standby_ = flag;
}