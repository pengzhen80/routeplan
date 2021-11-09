#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

#include "jobmanagement_common.h"
#ifndef JOBMANAGEMENT
#define JOBMANAGEMENT

namespace JobManagement
{
    using namespace JobMangement_Common;
    class MapManager
    {
        public:
            void InitMap(std::vector<JobMangement_Common::MyNode> map);
            void GetHomeTag_ByPos(int pos);
            int GetHomeFillingTag_ByPos(int pos);
            void BackHome_Add(int filling_tag);
            void ArrivecHome_Subtraction(int filling_tag);
            int Choose_BackHome_FillingTag(int pos);
        private:
            void set_areas();
            void set_homes(std::vector<std::vector<int>> vec_vec_tag);
            void set_customers();
        private:
            double dis_tag(int f_tag_id, int s_tag_id);
        private:
        JobMangement_Common::Map map_;
    };

    class CarManager
    {
        public:
            void InitCar(std::vector<JobMangement_Common::Car> cars);
            CAR_JOBSTATE Get_car_jobstate(int car_id);
            Job Get_car_curjob(int car_id);
            Job Pop_car_curjob(int car_id);
            void Push_to_car_joblist(int car_id,Job job);
            void Car_cancel_job(int car_id,int order_num);
            void Set_car_jobstate(int car_id,CAR_JOBSTATE car_job_state);
            void Update_car_curjob_state(int car_id,JOB_STATE job_state);
            int Get_car_pos(int car_id);
            void Update_car_position(int car_id,int pos);
            void Update_car_state(int car_id,Car_Objects_State car_objects_state);
        private:
            //todo: after update car state: should check car state, then init o statejob
            virtual bool check_car_state(Car_Objects_State car_objects_state){}
            virtual Job init_job_statejob(int car_id){}
        private:
        std::vector<JobMangement_Common::Car> cars_;
        std::unordered_map<int,int> cars_id_index_;
    };

    class JobManagement
    {
        protected://singalton pattern
            explicit JobManagement()
            {
            }
        public:
            static JobManagement* Instance();
        public:
            //service for OrderMangement
            void Set_order_state(int order_number,JobMangement_Common::ORDERRESULT result);
            //service for StateMachine
            virtual void Ask_Job_Charge(int car_id){}
        public:
            //for test
            void DefaultInitCar();
            //initmap
            void InitMap(std::vector<JobMangement_Common::MyNode> map);
            //initcar
            void InitCar(std::vector<Car> cars);
            //service for StateMachine
            void UpdateCarPos(int car_id,int pos);
            void UpdateCarState(int car_id, Car_Objects_State car_objects_state);
            //client of StateMachine
            virtual void Update_car_path(int car_id,std::vector<Path_Tag_Motion_Job> path){}
            virtual void Ask_Cars_BatteryInfo(){}
        public:
            void Act_Order(JobMangement_Common::Order_For_JobManagement order);
            void Cancel_Order(JobMangement_Common::Order_For_JobManagement order);
            void StateJob(int car_id,Job statejob);
            void Job_BackHome(int car_id,int pos);
            void Car_Ask_Default_Job(int car_id,int pos);
            void JobFilling(int car_id,int pos);
        private:
        int choose_car(int pos);
        void map_order(int order_number,int car_id);
        int get_carId_byOrderNumber(int ordernumber);
        bool compare_job(JOB_WEIGHT weitht_f, JOB_WEIGHT weight_s);
        int choose_back_pos(int pos);
        //act job
        void act_job_orderjob(int car_id,int pos);
        void act_job_backhome(int car_id,int pos);
        void act_job_filling(int car_id,int pos);
        void act_job_statejob(int car_id);
        std::vector<Path_Tag_For_Job> ask_next_path(Path_Ask_Traffic path_ask);
        void set_path_task(int car_id,std::vector<Path_Tag_For_Job> path);
        void car_act_curjob(int car_id, int pos);

        //car job
        void set_car_curjob_finished(int car_id);

        //order
        void finish_order(int order_number);

        private:
        //order
        std::vector<JobMangement_Common::Order_For_JobManagement> orderlists_;
        std::unordered_map<int,int> orderNumber_orderIndex_;
        std::unordered_map<int,int> orderNumber_carId_;

        //car
        CarManager car_manager_;

        //map
        MapManager map_manager_;
    private:
        //singalton pattern
        static JobManagement* instance_;
        static std::mutex mutex_instance_; 
    };
};
#endif