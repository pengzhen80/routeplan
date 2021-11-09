
#include"configuration_common.h"

#ifndef CARMANAGER
#define CARMANAGER

class CarManager
{
public:
    void Init(Configuration_Car cars);
    int GetCarNum();
    std::vector<int> GetCarUseful();

private:
 Configuration_Car cars_;
};

#endif