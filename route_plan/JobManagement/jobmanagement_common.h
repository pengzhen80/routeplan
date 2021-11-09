
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#ifndef JOBMANAGEMENT_COMMON
#define JOBMANAGEMENT_COMMON

namespace JobMangement_Common
{
    //define order
    enum ORDERACTION
    {
        ORDERACTION_ACT = 0,
        ORDERACTION_CANCEL,
    };
    enum ORDERRESULT
    {
        ORDERRESULT_SUCCESS = 0,
        ORDERRESULT_FAILURE,
        ORDERRESULT_DEFAULT,
    };

    struct Goods_Info
    {
        std::string name;
    };
    struct Order_Data
    {
        Goods_Info goods_info;
        int goods_pos;
        int target_pos;
        int car_id = -1;
    };

    struct Order_For_JobManagement
    {
        int number;
        Order_Data data;
        ORDERACTION action;
    };
    //define car objects' state
    enum CAR_LED_STATE
    {
        CAR_LED_STATE_OFF = 0,
        CAR_LED_STATE_ON_CHARGE,
        CAR_LED_STATE_ON_JOB,
        CAR_LED_STATE_ERROR,
        CAR_LED_STATE_DEFAULT,
    };
    struct Car_Led
    {
        CAR_LED_STATE state = CAR_LED_STATE_OFF;
    };
    enum CAR_LID_STATE
    {
        CAR_LID_STATE_OPEN = 0,
        CAR_LID_STATE_CLOSE,
        CAR_LID_STATE_DEFAULT,
    };
    struct Car_Lid
    {
        CAR_LID_STATE state = CAR_LID_STATE_OPEN;
    };

    enum CAR_LIDLIGHT_STATE
    {
        CAR_LIDLIGHT_STATE_OFF = 0,
        CAR_LIDLIGHT_STATE_ON,
        CAR_LIDLIGHT_STATE_DEFAULT,
    };

    struct Car_LidLight
    {
        CAR_LIDLIGHT_STATE state = CAR_LIDLIGHT_STATE_OFF;
    };

    enum CAR_FOODSENSOR_STATE
    {
        CAR_FOODSENSOR_STATE_OPEN = 0,
        CAR_FOODSENSOR_STATE_CLOSE,
        CAR_FOODSENSOR_STATE_DEFAULT,
    };
    struct Car_FoodSensor
    {
        CAR_FOODSENSOR_STATE state = CAR_FOODSENSOR_STATE_OPEN;
    };

    enum CAR_LCD_STATE
    {
        CAR_LCD_STATE_DEFAULT = 0,
        CAR_LCD_STATE_ERROR,
        CAR_LCD_STATE_JOB,
        CAR_LCD_STATE_CHARGE,
    };
    struct Car_Lcd
    {
        CAR_LCD_STATE state = CAR_LCD_STATE_DEFAULT;
        std::string sentence;
    };

    enum CAR_SOUND_STATE
    {
        CAR_SOUND_STATE_DEFAULT = 0,
        CAR_SOUND_TAKEFOOD,
        CAR_SOUND_STATE_WARNING_DONTTAKEFOOD,
        CAR_SOUND_STATE_WAITFORTRANSPORT,
    };
    struct Car_Sound
    {
        CAR_SOUND_STATE state = CAR_SOUND_STATE_DEFAULT;
    };


    //define car job state
    enum CAR_JOBSTATE
    {
        CAR_JOBSTATE_IDLE = 0,
        CAR_JOBSTATE_CHARGE,
        CAR_JOBSTATE_DELIVERY,
        CAR_JOBSTATE_RECEPTION,
        CAR_JOBSTATE_BACKHOME,
    };


    //define car objects state
    struct Car_Objects_State
    {
        CAR_LED_STATE led_state;
        CAR_LID_STATE lid_state;
        CAR_LIDLIGHT_STATE lidlight_state;
        CAR_FOODSENSOR_STATE foodsensor_state;
        CAR_LCD_STATE lcd_state;
        Car_Lcd lcd_info;
        CAR_SOUND_STATE sound_state;
    };


    //settings should be in StateMachine
    // struct Car_Objects_Led_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_LED_STATE> settings;
    // };
    // struct Car_Objects_Lid_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_LID_STATE> settings;
    // };
    // struct Car_Objects_Lidlight_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_LIDLIGHT_STATE> settings;
    // };
    // struct Car_Objects_FoodSensor_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_FOODSENSOR_STATE> settings;
    // };
    // struct Car_Objects_Lcd_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_LCD_STATE> settings;
    // };
    // struct Car_Objects_Sound_Settings
    // {
    //     //todo
    //     std::unordered_map<CAR_JOBSTATE,CAR_SOUND_STATE> settings;
    // };

    // struct Car_Objects_Settings
    // {
    //     Car_Objects_Led_Settings led_settings;
    //     Car_Objects_Lid_Settings lid_settings;
    //     Car_Objects_Lidlight_Settings lidlight_settings;
    //     Car_Objects_FoodSensor_Settings foodsensor_settings;
    //     Car_Objects_Lcd_Settings lcd_settings;
    //     Car_Objects_Sound_Settings sound_settings;
    // };



    //define job type
    enum JOB_TYPE
    {
        JOB_TYPE_CHARGE = 0,
        JOB_TYPE_DELIVERY,
        JOB_TYPE_RECEPTION,
        JOB_TYPE_BACKHOME,
        JOB_TYPE_IDLE,
        JOB_TYPE_FILLING,
    };

    struct Job_Info_Filling
    {
        int target;
    };

    //define job state
    enum JOB_STATE
    {
        JOB_STATE_UNINIT = 0,
        JOB_STATE_INIT,
        JOB_STATE_ACT,
        JOB_STATE_FINISH,
    };

    //define job weight
    enum JOB_WEIGHT
    {
        JOB_WEIGHT_LOWEST = 0, // for idle
        JOB_WEIGHT_LOW,
        JOB_WEIGHT_NORMAL,
        JOB_WEIGHT_HIGH,
    };
    //define backhome job info
    struct Job_Info_BackHome
    {
        int tag_id;
    };
    //define job info
    struct Job_Info
    {
        Order_For_JobManagement job_info;
        Job_Info_BackHome backhome_info;
        Job_Info_Filling filling_info;
    };

    //define job
    struct Job
    {
        JOB_TYPE type;
        Job_Info info;
        JOB_STATE state = JOB_STATE_UNINIT;
        JOB_WEIGHT weight = JOB_WEIGHT_LOWEST;
        bool operator>(const Job &job)
        {
            return this->weight > job.weight;
        }
    };

    //define car
    struct Car
    {
        int car_id;
        int pos;
        CAR_JOBSTATE job_state = CAR_JOBSTATE_IDLE;
        std::vector<Job> joblist;
        Car_Objects_State objects_state;
    };

    //define map
    enum TAG_TYPE
    {
        TAG_TYPE_CUSTOMER = 0,
        TAG_TYPE_HOME,
        TAG_TYPE_NORMAL,
        TAG_TYPE_CHARGE,
    };

    struct Map_Tag
    {
        int tag_id;
        TAG_TYPE type = TAG_TYPE_NORMAL;
        double x;
        double y;
    };

    struct Map_Customer_Tags
    {
        std::unordered_set<int> goods_tags;
        std::unordered_set<int> target_tags;
        int area_id;
    };

    enum MAP_HOME_TYPE
    {
        MAP_HOME_TYPE_DEFAULT = 0,
        MAP_HOME_TYPE_FILLING = 1,
    };
    struct Map_FillHome_Info
    {
        int filling_tag = -1;
        int pre_count = 0;
    };
    struct Map_Home_Info
    {
        Map_FillHome_Info fillhome_info;
    };
    struct Map_Home
    {
        std::unordered_set<int> home_tags;
        int home_id;
        int area_id;
        MAP_HOME_TYPE type = MAP_HOME_TYPE_FILLING;
        Map_Home_Info info;
    };

    struct Map_Area
    {
        int area_id;
        std::vector<Map_Home> homes;
        std::unordered_map<int, int> homes_id_index;
        Map_Customer_Tags customer_tags;

        std::vector<Map_Tag> tags;
        std::unordered_map<int, int> tags_id_index;
    };

    struct Map
    {
        std::vector<Map_Area> areas;
        std::unordered_map<int, int> areas_id_index;
        //tag maybe not need, but now how to devide map into areas? so just as one area to init and test
        std::vector<Map_Tag> tags;
        std::unordered_map<int, int> tags_id_index;
    };

    // map in MapManagement
    struct Position
    {
        float x;
        float y;
        float z;
    };

    struct MyNode
    {
        int id;
        int type;
        Position pos;
        std::vector<int> neighbors;
    };

    //ask path to TrafficManagement
    struct Path_Ask_Traffic
    {
        int car_id;
        int position;
        int target;
    };

    //path from TrafficManagement
    struct Path_BetweenTag_Motion_Section
    {
        int distance_or_radius;
        int max_velocity;
        int angle;
    };

    struct Path_BetweenTag_Motion
    {
        int from_tag;
        int to_tag;
        Path_BetweenTag_Motion_Section sections[4];
    };

    //path for JobManagement
    struct Path_Tag_For_Job
    {
        int tag;
        Path_BetweenTag_Motion motion;
    };

    struct Path_Tag_Motion_Job
    {
        int tag;
        Path_BetweenTag_Motion motion;
        Car_Objects_State car_objects_state;
    };
};

#endif