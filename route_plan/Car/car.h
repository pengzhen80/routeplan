#include<vector>

class Car
{
#define DEFAULTSPEED 100

public:
struct Info
{
    double speed; // in simulator, it is 100ms per tag
};
public:
    explicit Car(int id):car_id_(id){
        info_.speed = DEFAULTSPEED;
    }
    //std::vector<int> get_next_tags();
    void update_route(std::vector<int> route);
    int get_id();
    void set_current_path();
    std::vector<int> get_current_path();//car's runing path
    bool getstandby();
    void setstandby(bool flag);
    inline static double getspeead() {
        return DEFAULTSPEED;
    }
    //todo check_car_id();   
private:
    std::vector<int> route_;
    std::vector<int> current_path_;
    int car_id_;
    bool standby_; //todo enum standby state
    //int current_tag_;
    //todo: speed and acc
    Info info_;
};