#include "route_planner.h"
#include<iostream>
#include<unordered_set>

bool RoutePlan::InitCar(int car_id)
{
    if (car_ids_.count(car_id) == 0)
    {
        Car car(car_id);
        car_ids_.insert(car_id);
        cars_.push_back(car);
        return true;
    }
    std::cout<<"id exist\n";
    return false;
}
//not safe : can sort the car and use two sort
Car RoutePlan::GetCarById(int car_id)
{
    if(car_ids_.count(car_id)>0)
    {
        for(int i=0;i<cars_.size();i++)
        {
            if(cars_[i].get_id() == car_id)
                    return cars_[i];
        }
    }
    std::cout<<"car not found\n";
    return Car(-1);
}
//check if car's route conflict with others
bool RoutePlan::CheckRouteComflict(int car_id)
{
    std::vector<int> car_route = GetCarById(car_id).get_current_path();

    for(int i=0;i<cars_.size();i++)
    {
        if(CheckVecComflict(car_route,cars_[i].get_current_path()))
        {
            return true;
        }
    }
    return false;
}

bool RoutePlan::CheckVecComflict(std::vector<int> path1,std::vector<int> path2)
{
    std::unordered_set<int> set_path;
    for(int i=0;i<path1.size();i++)
    {
        set_path.insert(path1[i]);
    }

    for(int i=0;i<path2.size();i++)
    {
        if(set_path.count(path2[i])>0)
        {
            return true;
        }
    }
    return false;
}

// void RoutePlan::UpdateRoute(int car_id)
// {
//     //no need
// }
