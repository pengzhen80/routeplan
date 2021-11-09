#include "jobmanagement.h"

// one area
void JobManagement::MapManager::InitMap(std::vector<MyNode> vec_map)
{
    map_.tags.clear();
    map_.tags_id_index.clear();

    Map_Area area;
    area.area_id = 1;

    std::vector<std::vector<int>> vec_home;
    std::unordered_set<int> set_tag_wait;
    std::unordered_map<int, int> map_waitId_waitIndex;

    for (int i = 0; i < vec_map.size(); i++)
    {
        Map_Tag tag;
        tag.tag_id = vec_map[i].id;
        tag.x = vec_map[i].pos.x;
        tag.y = vec_map[i].pos.y;

        if (vec_map[i].type == 1)
        {

            area.customer_tags.target_tags.insert(vec_map[i].id);
            tag.type = TAG_TYPE::TAG_TYPE_CUSTOMER;
        }

        if (vec_map[i].type == 3)
        {
            std::vector<int> home;
            home.push_back(vec_map[i].id);
            vec_home.push_back(home);
            map_waitId_waitIndex.insert(std::make_pair(vec_map[i].id, i));
            tag.type = TAG_TYPE::TAG_TYPE_HOME;
        }

        if (vec_map[i].type == 2)
        {
            map_waitId_waitIndex.insert(std::make_pair(vec_map[i].id, i));
            tag.type = TAG_TYPE::TAG_TYPE_HOME;
        }

        map_.tags.push_back(tag);
        map_.tags_id_index.insert(std::make_pair(tag.tag_id, map_.tags.size() - 1));
    }

    //init area
    map_.areas.push_back(area);
    map_.areas_id_index.insert(std::make_pair(area.area_id, map_.areas.size() - 1));

    //init home
    std::unordered_map<int, int> map_waitId_waitId;
    for (std::unordered_map<int, int>::iterator it = map_waitId_waitIndex.begin(); it != map_waitId_waitIndex.end(); it++)
    {
        int wait_id = it->first;
        int wait_index = it->second;

        for (int i = 0; i < vec_map[wait_index].neighbors.size(); i++)
        {
            int neighbor_id = vec_map[wait_index].neighbors[i];
            if (map_waitId_waitIndex.count(neighbor_id) > 0)
            {
                map_waitId_waitId.insert(std::make_pair(neighbor_id, wait_id));
            }
        }
    }

    for (int i = 0; i < vec_home.size(); i++)
    {
        int wait_id = vec_home[i][0];

        while (map_waitId_waitId.count(wait_id) > 0)
        {
            vec_home[i].push_back(map_waitId_waitId[wait_id]);
            wait_id = map_waitId_waitId[wait_id];
        }
    }

    set_homes(vec_home);
}

void JobManagement::MapManager::GetHomeTag_ByPos(int pos)
{
}

//pos is a tag in a home, return a home fillingtag , else return -1
int JobManagement::MapManager::GetHomeFillingTag_ByPos(int pos)
{
    for (int i_area = 0; i_area < map_.areas.size(); i_area++)
    {
        if (map_.areas[i_area].tags_id_index.count(pos) > 0)
        {
            for (int i_home = 0; i_home < map_.areas[i_area].homes.size(); i_home < 0)
            {
                if (i_home<map_.areas[i_area].homes[i_home].home_tags.count(pos)> 0)
                {
                    if (i_home < map_.areas[i_area].homes[i_home].type == MAP_HOME_TYPE_FILLING)
                    {
                        return i_home < map_.areas[i_area].homes[i_home].info.fillhome_info.filling_tag;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            return -1;
        }
    }
    return -1;
}

void JobManagement::MapManager::BackHome_Add(int filling_tag)
{
    for (int i_area = 0; i_area < map_.areas.size(); i_area)
    {
        for (int i_home = 0; i_home < map_.areas[i_area].homes.size(); i_home++)
        {
            if (map_.areas[i_area].homes[i_home].info.fillhome_info.filling_tag == filling_tag)
            {
                map_.areas[i_area].homes[i_home].info.fillhome_info.pre_count++;
            }
        }
    }
}

void JobManagement::MapManager::ArrivecHome_Subtraction(int filling_tag)
{
    for (int i_area = 0; i_area < map_.areas.size(); i_area)
    {
        for (int i_home = 0; i_home < map_.areas[i_area].homes.size(); i_home++)
        {
            if (map_.areas[i_area].homes[i_home].info.fillhome_info.filling_tag == filling_tag)
            {
                map_.areas[i_area].homes[i_home].info.fillhome_info.pre_count--;
            }
        }
    }
}

//choose a home tag's size >= pre_count and the max of (tag's size - pre_count) ,choose the filling tag
int JobManagement::MapManager::Choose_BackHome_FillingTag(int pos)
{
    int max_dif_home_tagsize_fillingcount = -1;
    int result_filling_tag = -1;
    double min_dis = 0;

    for (int i_area = 0; i_area < map_.areas.size(); i_area)
    {
        for (int i_home = 0; i_home < map_.areas[i_area].homes.size(); i_home++)
        {
            int home_tagsize = map_.areas[i_area].homes[i_home].home_tags.size();
            int fillingcount = map_.areas[i_area].homes[i_home].info.fillhome_info.pre_count;
            int filling_tag = map_.areas[i_area].homes[i_home].info.fillhome_info.filling_tag;

            int dif_home_tagsize_fillingcount = home_tagsize - fillingcount;
            if (dif_home_tagsize_fillingcount > max_dif_home_tagsize_fillingcount)
            {
                min_dis = dis_tag(pos, filling_tag);
                result_filling_tag = filling_tag;
            }
            else if (dif_home_tagsize_fillingcount == max_dif_home_tagsize_fillingcount)
            {
                double dis = dis_tag(pos, filling_tag);
                if (min_dis > dis)
                {
                    min_dis = dis;
                    result_filling_tag = filling_tag;
                }
            }
        }
    }
    return result_filling_tag;
}

void JobManagement::MapManager::set_areas()
{
}
void JobManagement::MapManager::set_homes(std::vector<std::vector<int>> vec_vec_tag)
{
    map_.areas[0].homes.clear();
    map_.areas[0].homes_id_index.clear();

    for (int i = 0; i < vec_vec_tag.size(); i++)
    {
        Map_Home home;
        home.area_id = 1;
        home.home_id = i;
        //fill_tag and filling home
        home.type = MAP_HOME_TYPE_FILLING;
        home.info.fillhome_info.filling_tag = vec_vec_tag[i][0];

        for (int j = 0; j < vec_vec_tag[i].size(); j++)
        {
            home.home_tags.insert(vec_vec_tag[i][j]);
        }
        map_.areas[0].homes.push_back(home);
        map_.areas[0].homes_id_index.insert(std::make_pair(home.home_id, map_.areas[0].homes.size() - 1));
    }
}
void JobManagement::MapManager::set_customers()
{
}

double JobManagement::MapManager::dis_tag(int f_tag_id, int s_tag_id)
{
    Map_Tag ftag = map_.tags[map_.tags_id_index[f_tag_id]];
    Map_Tag stag = map_.tags[map_.tags_id_index[s_tag_id]];

    double x = ftag.x - stag.x > 0 ? ftag.x - stag.x : stag.x - ftag.x;
    double y = ftag.y - stag.y > 0 ? ftag.y - stag.y : stag.y - ftag.y;

    return x + y;
}

void JobManagement::CarManager::InitCar(std::vector<Car> cars)
{
    cars_.clear();

    std::cout<< " JobManagement::CarManager::InitCar: ";
    for (int i = 0; i < cars.size(); i++)
    {
        cars_.push_back(cars[i]);
        cars_id_index_.insert(std::make_pair(cars[i].car_id, cars_.size() - 1));

         std::cout<<cars[i].car_id<<" ";
    }
    std::cout<<std::endl;
}

JobMangement_Common::CAR_JOBSTATE JobManagement::CarManager::Get_car_jobstate(int car_id)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in get car jobstate\n";
        return CAR_JOBSTATE::CAR_JOBSTATE_IDLE;
    }
    return cars_[cars_id_index_[car_id]].job_state;
}

int JobManagement::CarManager::Get_car_pos(int car_id)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in get car jobstate\n";
        return -1;
    }
    return cars_[cars_id_index_[car_id]].pos;
}

void JobManagement::CarManager::Update_car_position(int car_id, int pos)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in Update_car_position\n";
        return;
    }

    cars_[cars_id_index_[car_id]].pos = pos;
}

void JobManagement::CarManager::Update_car_state(int car_id, Car_Objects_State car_objects_state)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in Update_car_state\n";
        return;
    }

    cars_[cars_id_index_[car_id]].objects_state = car_objects_state;
}

JobMangement_Common::Job JobManagement::CarManager::Get_car_curjob(int car_id)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in get car curjob\n";
        Job job;
        job.type = JOB_TYPE_IDLE;
        job.weight = JOB_WEIGHT_LOW;
        return job;
    }

    if(cars_[cars_id_index_[car_id]].joblist.empty())
    {
        JobMangement_Common::Job job;
        job.weight = JOB_WEIGHT_LOWEST;
        return job;
    }
    return cars_[cars_id_index_[car_id]].joblist.front();
}

JobMangement_Common::Job JobManagement::CarManager::Pop_car_curjob(int car_id)
{
    Job job;
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in Pop_car_curjob\n";

        job.type = JOB_TYPE_IDLE;
        job.weight = JOB_WEIGHT_LOW;
        return job;
    }

    try
    {
        job = cars_[cars_id_index_[car_id]].joblist.front();
        cars_[cars_id_index_[car_id]].joblist.erase(cars_[cars_id_index_[car_id]].joblist.begin());
    }
    catch (const std::exception &e)
    {
        std::cout << "car has no job\n";
        std::cerr << e.what() << '\n';
    }

    return job;
}

void JobManagement::CarManager::Push_to_car_joblist(int car_id, Job job)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in push to car joblist\n";
        return;
    }
    cars_[cars_id_index_[car_id]].joblist.push_back(job);
}
void JobManagement::CarManager::Car_cancel_job(int car_id, int order_num)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in car cancel job\n";
        return;
    }
    int index = cars_id_index_[car_id];
    for (int i = 0; i < cars_[index].joblist.size(); i++)
    {
        if (JOB_TYPE::JOB_TYPE_DELIVERY == cars_[index].joblist[i].type)
        {
            if (order_num == cars_[index].joblist[i].info.job_info.number)
            {
                cars_[index].joblist.erase(cars_[index].joblist.begin() + i);
                return;
            }
        }
    }
}

void JobManagement::CarManager::Set_car_jobstate(int car_id, CAR_JOBSTATE car_job_state)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in Set_car_jobstate\n";
        return;
    }

    int index = cars_id_index_[car_id];
    cars_[index].job_state = car_job_state;
}

void JobManagement::CarManager::Update_car_curjob_state(int car_id, JOB_STATE job_state)
{
    if (cars_id_index_.count(car_id) == 0)
    {
        std::cout << " cannot find car in Update_car_curjob_state\n";
        return;
    }

    int index = cars_id_index_[car_id];
    try
    {
        cars_[index].joblist[0].state = job_state;
    }
    catch (const std::exception &e)
    {
        std::cout << " cannot find job in Update_car_curjob_state\n";
        std::cerr << e.what() << '\n';
    }
}

JobManagement::JobManagement* JobManagement::JobManagement::instance_ = nullptr;
std::mutex JobManagement::JobManagement::mutex_instance_; 

JobManagement::JobManagement* JobManagement::JobManagement::Instance()
{
    std::lock_guard<std::mutex> lock(mutex_instance_);
    if(instance_ == nullptr)
    {
        instance_ = new JobManagement();
    }
    return instance_;
}

//initmap
void JobManagement::JobManagement::InitMap(std::vector<MyNode> map)
{
    map_manager_.InitMap(map);
}
//initcar
void JobManagement::JobManagement::InitCar(std::vector<Car> cars)
{
    car_manager_.InitCar(cars);
}

void JobManagement::JobManagement::DefaultInitCar()
{   
    std::vector<Car> cars;
    for(int i=1;i<5;i++)
    {
       Car car;
       car.car_id = i;
       car.pos = i;
       car.job_state = CAR_JOBSTATE_IDLE;
       car.joblist.clear();

       cars.push_back(car);
    }

    InitCar(cars);   
}
//init act order(delivery/reception) job
void JobManagement::JobManagement::Act_Order(Order_For_JobManagement order)
{
    int car_id;
    Job job;

    std::cout <<"JobManagement::JobManagement::Act_Order: car_id is"<<order.data.car_id<<std::endl;    
    //get carid
    if (order.data.car_id >= 0)
    {
        car_id = order.data.car_id;
        std::cout<<" order has car \n";
    }
    else
    {
        car_id = choose_car(order.data.target_pos);
    }
    //store order
    map_order(order.number, car_id);

    //make job
    job.type = JOB_TYPE_DELIVERY;
    job.state = JOB_STATE_INIT;
    job.weight = JOB_WEIGHT_NORMAL;
    job.info.job_info.number = order.number;
    job.info.job_info.action = ORDERACTION_ACT;
    job.info.job_info.data.car_id = car_id;
    job.info.job_info.data.target_pos = order.data.target_pos;
    job.info.job_info.data.goods_pos = order.data.goods_pos;
    job.info.job_info.data.goods_info.name = order.data.goods_info.name;
    //attach job to car
    //CAR_JOBSTATE jobstate = car_manager_.Get_car_jobstate(car_id);
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    if (compare_job(job.weight, car_cur_job.weight))
    {
        car_manager_.Push_to_car_joblist(car_id, job);
        act_job_orderjob(car_id, car_manager_.Get_car_pos(car_id));
    }
    else
    {
        car_manager_.Push_to_car_joblist(car_id, job);
    }

    //push a back job
    Job job_backhome;
    job_backhome.type = JOB_TYPE_BACKHOME;
    job_backhome.state = JOB_STATE_UNINIT;
    job_backhome.weight = JOB_WEIGHT_NORMAL;
    car_manager_.Push_to_car_joblist(car_id, job_backhome);

    //push a filling
    // Job job_filling;
    // job_filling.type = JOB_TYPE_FILLING;
    // job_filling.state = JOB_STATE_UNINIT;
    // job_filling.weight = JOB_WEIGHT_LOW;
    // car_manager_.Push_to_car_joblist(car_id, job_filling);
}
//init cancel order job
void JobManagement::JobManagement::Cancel_Order(Order_For_JobManagement order)
{
    int car_id = get_carId_byOrderNumber(order.number);
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);

    if (car_cur_job.type == JOB_TYPE_DELIVERY)
    {
        if (order.number == car_cur_job.info.job_info.number)
        {
            car_manager_.Car_cancel_job(car_id, order.number);
        }
    }
}
//init statejob
void JobManagement::JobManagement::StateJob(int car_id, Job statejob)
{
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    if (compare_job(statejob.weight, car_cur_job.weight))
    {
        car_manager_.Push_to_car_joblist(car_id, statejob);
        act_job_statejob(car_id);
    }
    else
    {
        car_manager_.Push_to_car_joblist(car_id, statejob);
    }
}
//init backhome job
void JobManagement::JobManagement::Job_BackHome(int car_id, int pos)
{
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    if (compare_job(JOB_WEIGHT_NORMAL, car_cur_job.weight))
    {
        int back_tag_id = choose_back_pos(pos);
        Job job;
        job.type = JOB_TYPE_BACKHOME;
        job.state = JOB_STATE_INIT;
        job.weight = JOB_WEIGHT_NORMAL;
        job.info.backhome_info.tag_id = back_tag_id;

        car_manager_.Push_to_car_joblist(car_id, job);
        act_job_backhome(car_id, pos);

        map_manager_.BackHome_Add(back_tag_id);
    }
    else
    {
        Job job;
        job.type = JOB_TYPE_BACKHOME;
        job.state = JOB_STATE_UNINIT;
        job.weight = JOB_WEIGHT_NORMAL;
        car_manager_.Push_to_car_joblist(car_id, job);
    }

    //filling job is after backhome
    // Job job_filling;
    // job_filling.type = JOB_TYPE_FILLING;
    // job_filling.state = JOB_STATE_UNINIT;
    // job_filling.weight = JOB_WEIGHT_LOW;
    // car_manager_.Push_to_car_joblist(car_id, job_filling);
}

void JobManagement::JobManagement::JobFilling(int car_id, int pos)
{
    int home_fillingtag = map_manager_.GetHomeFillingTag_ByPos(pos);
    if (pos == home_fillingtag)
    {
        car_act_curjob(car_id, pos);
    }
    else
    {
        Job job;
        job.type = JOB_TYPE_FILLING;
        job.state = JOB_STATE_UNINIT;
        job.weight = JOB_WEIGHT_LOW;
        car_manager_.Push_to_car_joblist(car_id, job);
    }
}

void JobManagement::JobManagement::Car_Ask_Default_Job(int car_id, int pos)
{
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    if (car_cur_job.state == JOB_STATE_ACT)
    {
        int target_tag;
        if (car_cur_job.type == JOB_TYPE_DELIVERY || car_cur_job.type == JOB_TYPE_RECEPTION)
        {
            target_tag = car_cur_job.info.job_info.data.target_pos;
        }
        else if (car_cur_job.type == JOB_TYPE_BACKHOME)
        {
            target_tag = car_cur_job.info.backhome_info.tag_id;
        }
        if (pos == target_tag)
        {
            set_car_curjob_finished(car_id);
            //check car jobstate
            CAR_JOBSTATE car_job_state = car_manager_.Get_car_jobstate(car_id);
            if (car_job_state == CAR_JOBSTATE_IDLE)
            {
                car_manager_.Set_car_jobstate(car_id, CAR_JOBSTATE_IDLE);
            }
            else
            {
                car_act_curjob(car_id, pos);
            }
        }
        else
        {
            car_act_curjob(car_id, pos);
        }
    }
}

void JobManagement::JobManagement::UpdateCarPos(int car_id, int pos)
{
    car_manager_.Update_car_position(car_id, pos);
    Car_Ask_Default_Job(car_id, pos);
}

void JobManagement::JobManagement::UpdateCarState(int car_id, Car_Objects_State car_objects_state)
{
    car_manager_.Update_car_state(car_id, car_objects_state);
}

//choose car in this area whose joblist'size is smallest?
int JobManagement::JobManagement::choose_car(int pos)
{
    //to do
}
void JobManagement::JobManagement::map_order(int order_number, int car_id)
{
    orderNumber_carId_.insert(std::make_pair(order_number, car_id));
}
int JobManagement::JobManagement::get_carId_byOrderNumber(int ordernumber)
{
    int result = -1;
    try
    {
        result = orderNumber_carId_[ordernumber];
    }
    catch (const std::exception &e)
    {
        std::cout << "no such order number\n";
        std::cerr << e.what() << '\n';
    }
    return result;
}
bool JobManagement::JobManagement::compare_job(JOB_WEIGHT weight_f, JOB_WEIGHT weight_s)
{
    return weight_f > weight_s;
}
int JobManagement::JobManagement::choose_back_pos(int pos)
{
    //choose a home tag's size >= pre_count and the max of (tag's size - pre_count) ,choose the filling tag
    return map_manager_.Choose_BackHome_FillingTag(pos);
}
//act job
void JobManagement::JobManagement::act_job_orderjob(int car_id, int pos)
{
    int target = -1;
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);

    try
    {
        target = car_cur_job.info.job_info.data.target_pos;
    }
    catch (const std::exception &e)
    {
        std::cout << "error in act_job_orderjob \n";
        std::cerr << e.what() << '\n';
    }

    car_manager_.Update_car_curjob_state(car_id, JOB_STATE_ACT);

    Path_Ask_Traffic path_ask;
    path_ask.car_id = car_id;
    path_ask.position = pos;
    path_ask.target = target;

    std::vector<Path_Tag_For_Job> path_motion = ask_next_path(path_ask);
    set_path_task(car_id, path_motion);
}
void JobManagement::JobManagement::act_job_backhome(int car_id, int pos)
{
    //if job uninit
    int back_tag_id = -1;

    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    if (car_cur_job.state == JOB_STATE_UNINIT)
    {
        back_tag_id = choose_back_pos(pos);
        car_cur_job.state == JOB_STATE_INIT;
        car_manager_.Update_car_curjob_state(car_id, JOB_STATE_INIT);
    }
    else
    {
        back_tag_id = car_cur_job.info.backhome_info.tag_id;
    }
    car_manager_.Update_car_curjob_state(car_id, JOB_STATE_ACT);

    Path_Ask_Traffic path_ask;
    path_ask.car_id = car_id;
    path_ask.position = pos;
    path_ask.target = back_tag_id;
    std::vector<Path_Tag_For_Job> vec_path = ask_next_path(path_ask);
    set_path_task(car_id, vec_path);
}

void JobManagement::JobManagement::act_job_filling(int car_id, int pos)
{
    int home_fillingtag = map_manager_.GetHomeFillingTag_ByPos(pos);
    if (pos == home_fillingtag)
    {
        car_manager_.Pop_car_curjob(car_id);
        car_act_curjob(car_id, pos);
    }
    else
    {
        //if job uninit
        int filling_tag_id = -1;

        Job car_cur_job = car_manager_.Get_car_curjob(car_id);
        if (car_cur_job.state == JOB_STATE_UNINIT)
        {
            filling_tag_id = map_manager_.GetHomeFillingTag_ByPos(pos);
            if (-1 == filling_tag_id) // if filling_tag_id is not a home tag then delete this job
            {
                car_manager_.Pop_car_curjob(car_id);
                return;
            }
            car_cur_job.state == JOB_STATE_INIT;
            car_manager_.Update_car_curjob_state(car_id, JOB_STATE_INIT);
        }
        else
        {
            filling_tag_id = car_cur_job.info.filling_info.target;
        }
        car_manager_.Update_car_curjob_state(car_id, JOB_STATE_ACT);

        Path_Ask_Traffic path_ask;
        path_ask.car_id = car_id;
        path_ask.position = pos;
        path_ask.target = filling_tag_id;
        std::vector<Path_Tag_For_Job> vec_path = ask_next_path(path_ask);
        set_path_task(car_id, vec_path);
    }
}
void JobManagement::JobManagement::act_job_statejob(int car_id)
{
    //todo
}
std::vector<JobMangement_Common::Path_Tag_For_Job> JobManagement::JobManagement::ask_next_path(JobMangement_Common::Path_Ask_Traffic path_ask)
{
    std::vector<JobMangement_Common::Path_Tag_For_Job> path;
    return path;
    //todo
}
void JobManagement::JobManagement::set_path_task(int car_id, std::vector<JobMangement_Common::Path_Tag_For_Job> path)
{
    std::vector<Path_Tag_Motion_Job> vec_path_tag_motion;
    Path_Tag_Motion_Job path_tag_motion_job;

    Car_Objects_State car_objects_state;
    Job job = car_manager_.Get_car_curjob(car_id);
    //every tag has a objects state
    for (int i_path = 0; i_path < path.size(); i_path++)
    {
        switch (job.type)
        {
        case JOB_TYPE_CHARGE:
        {
            car_objects_state.led_state = CAR_LED_STATE_ON_CHARGE;
            car_objects_state.foodsensor_state = CAR_FOODSENSOR_STATE_DEFAULT;
            car_objects_state.lcd_state = CAR_LCD_STATE_CHARGE;
            car_objects_state.lid_state = CAR_LID_STATE_DEFAULT;
            car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_OFF;
            car_objects_state.sound_state = CAR_SOUND_STATE_DEFAULT;
            break;
        }
        case JOB_TYPE_DELIVERY:
        {
            car_objects_state.led_state = CAR_LED_STATE_ON_JOB;
            car_objects_state.foodsensor_state = CAR_FOODSENSOR_STATE_OPEN;
            car_objects_state.lcd_state = CAR_LCD_STATE_JOB;
            car_objects_state.lcd_info.sentence = job.info.job_info.data.goods_info.name;
            if (job.info.job_info.data.target_pos == path[i_path].tag)
            {
                car_objects_state.lid_state = CAR_LID_STATE_OPEN;
                car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_ON;
                car_objects_state.sound_state = CAR_SOUND_TAKEFOOD;
            }
            else
            {
                car_objects_state.lid_state = CAR_LID_STATE_DEFAULT;
                car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_OFF;
                car_objects_state.sound_state = CAR_SOUND_STATE_DEFAULT;
            }
            break;
        }
        case JOB_TYPE_BACKHOME:
        case JOB_TYPE_FILLING:
        case JOB_TYPE_IDLE:
        {
            car_objects_state.led_state = CAR_LED_STATE_ON_JOB;
            car_objects_state.foodsensor_state = CAR_FOODSENSOR_STATE_OPEN;
            car_objects_state.lcd_state = CAR_LCD_STATE_DEFAULT;
            car_objects_state.lid_state = CAR_LID_STATE_DEFAULT;
            car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_OFF;
            car_objects_state.sound_state = CAR_SOUND_STATE_DEFAULT;
            break;
        }
        case JOB_TYPE_RECEPTION:
        {
            car_objects_state.led_state = CAR_LED_STATE_ON_JOB;
            car_objects_state.foodsensor_state = CAR_FOODSENSOR_STATE_OPEN;
            car_objects_state.lcd_state = CAR_LCD_STATE_JOB;
            car_objects_state.lcd_info.sentence = job.info.job_info.data.goods_info.name;
            if (job.info.job_info.data.target_pos == path[i_path].tag)
            {
                car_objects_state.lid_state = CAR_LID_STATE_OPEN;
                car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_ON;
                car_objects_state.sound_state = CAR_SOUND_TAKEFOOD;
            }
            else
            {
                car_objects_state.lid_state = CAR_LID_STATE_DEFAULT;
                car_objects_state.lidlight_state = CAR_LIDLIGHT_STATE_OFF;
                car_objects_state.sound_state = CAR_SOUND_STATE_DEFAULT;
            }
            break;
        }

        default:
            break;
        }
        path_tag_motion_job.motion = path[i_path].motion;
        path_tag_motion_job.car_objects_state = car_objects_state;
        path_tag_motion_job.tag = path[i_path].tag;
        vec_path_tag_motion.push_back(path_tag_motion_job);
    }
    Update_car_path(car_id, vec_path_tag_motion);
}

//set car job finish and if is an order, tell order to finish and tell ordermanagement
void JobManagement::JobManagement::set_car_curjob_finished(int car_id)
{
    Job car_cur_job = car_manager_.Pop_car_curjob(car_id);
    car_cur_job.state = JOB_STATE_FINISH;
    int pos = car_manager_.Get_car_pos(car_id);

    switch (car_cur_job.type)
    {
    case JOB_TYPE_DELIVERY:
    case JOB_TYPE_RECEPTION:
    {
        int ordernumber = car_cur_job.info.job_info.number;
        finish_order(ordernumber);
        break;
    }
    case JOB_TYPE_BACKHOME:
    {
        map_manager_.ArrivecHome_Subtraction(pos);
        break;
    }
    default:
        break;
    }
}

void JobManagement::JobManagement::finish_order(int order_number)
{

    int orderindex = orderNumber_orderIndex_[order_number];
    orderNumber_orderIndex_.erase(order_number);

    //need to test
    orderlists_.erase(orderlists_.begin() + orderindex);
    for (int i = orderindex; i < orderlists_.size(); i++)
    {
        orderNumber_orderIndex_[orderlists_[i].number] = i;
    }

    Set_order_state(order_number, ORDERRESULT_SUCCESS);
}

void JobManagement::JobManagement::Set_order_state(int order_number, ORDERRESULT result)
{
    //todo OrderMangement client
}

void JobManagement::JobManagement::car_act_curjob(int car_id, int pos)
{
    Job car_cur_job = car_manager_.Get_car_curjob(car_id);
    switch (car_cur_job.type)
    {
    case JOB_TYPE_DELIVERY || JOB_TYPE_RECEPTION:
        act_job_orderjob(car_id, pos);
        break;
    case JOB_TYPE_BACKHOME:
        act_job_backhome(car_id, pos);
        break;
    case JOB_TYPE_FILLING:
        act_job_filling(car_id, pos);
        break;
    case JOB_TYPE_CHARGE:
        act_job_statejob(car_id);
    default:
        break;
    }
}