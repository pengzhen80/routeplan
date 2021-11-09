#include<vector>
#include<car.h>
#include<unordered_set>

class RoutePlan
{
public:
  inline bool checkCarExist(int car_id){return car_ids_.count(car_id)>0? true:false;}
  bool InitCar(int car_id);
  Car GetCarById(int car_id);
  bool CheckRouteComflict(int car_id);
  //void UpdateRoute(int car_id);
  //void UpdateUsedTags(std::vector<int> path);
private:
bool CheckVecComflict(std::vector<int> path1,std::vector<int> path2);
private:
std::vector<Car> cars_;
std::unordered_set<int> car_ids_;
//std::unordered_set<int> used_tags_;
};
