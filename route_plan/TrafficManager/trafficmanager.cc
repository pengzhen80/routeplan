#include "trafficmanager.h"
#include <iostream>
#include <unordered_set>
#include <unistd.h>

void print_tags(std::vector<int> tags, int line)
{
    //std::cout<<std::endl;
    for (int tag : tags)
    {
        if (tag > 100)
        {
            std::cout << "line is " << line;
            std::cout << std::endl;
            return;
        }
    }
}

void TrafficManager::ask_car_path(int car_id)
{
    int car_index = car_ids_indexs_[car_id];

    release_lock_tags(cars_[car_index].lock_tags);

    if (cars_[car_index].total_path.size() == 0)
    {
        std::vector<int> lock_tags;
        //lock_tags.push_back(cars_[car_index].target_tag);
        lock_tags.push_back(cars_[car_index].position_tag);

        update_lock_tags(lock_tags);

        cars_[car_index].lock_tags.clear();
        cars_[car_index].lock_tags = lock_tags;
        //update positon
        cars_[car_index].position_tag = cars_[car_index].target_tag;

        return;
    }

    cars_[car_index].position_tag = cars_[car_index].next_path[0];

    mutex_check_congestion_.lock();
    // bool congestion = CheckPathComflict(cars_[car_index].next_path);
    std::vector<int> path_cango = CheckPathCango(cars_[car_index].next_path);
    // if (!congestion && check_path_position(cars_[car_index].next_path, cars_[car_index].car_id))
    //if (path_cango.size() > 0 && check_path_position(path_cango, cars_[car_index].car_id))
    //這裏請求路徑的車子，很多位置已經更新了，如果在這裏判斷是否可以踩路徑，變成了判斷之前的位置（之後或許應該先更新所有返回的車子的位置之後再判斷路徑；
    if (path_cango.size() > 0)
    {
        //update_lock_tags(cars_[car_index].next_path);
        // mutex_check_congestion_.unlock();

        // car_cango cango;
        // cango.car_id = cars_[car_index].car_id;
        // cango.path = cars_[car_index].next_path;
        // mutex_que_cango_.lock();
        // que_cango_.push(cango);
        // mutex_que_cango_.unlock();
        // update_car_paths(cars_[car_index].car_id);
        // update_car_locktags(cango.car_id, cango.path);

        update_lock_tags(path_cango);
        mutex_check_congestion_.unlock();

        car_cango cango;
        cango.car_id = cars_[car_index].car_id;
        cango.path = path_cango;
        mutex_que_cango_.lock();
        que_cango_.push(cango);
        mutex_que_cango_.unlock();
        update_car_paths_bypath(cars_[car_index].car_id, path_cango);
        update_car_locktags(cango.car_id, cango.path);
    }
    else
    {
        mutex_check_congestion_.unlock();

        cars_[car_index].lock_tags.clear();
        cars_[car_index].lock_tags.push_back(cars_[car_index].position_tag);

        std::vector<int> vec_locktags;
        vec_locktags.push_back(cars_[car_index].position_tag);
        update_lock_tags(vec_locktags);

        std::vector<int> vec_wait;
        vec_wait.push_back(cars_[car_index].car_id);
        vec_wait.push_back(0);

        mutex_vec_wait_.lock();
        vec_wait_.push_back(vec_wait);
        mutex_vec_wait_.unlock();
        //debug
        //std::cout << "car " << cars_[car_index].car_id << " into wait\n";
    }
}

void TrafficManager::update_car_path(traffic_car car_info)
{
    //if it is a new car_path
    int car_index = -1;
    if (car_ids_indexs_.count(car_info.car_id) == 0)
    {
        return;
    }
    else
    {
        if (car_info.total_path.size() == 0)
        {

            //update car
            car_index = car_ids_indexs_[car_info.car_id];
            cars_[car_index].position_tag = car_info.position_tag;
            cars_[car_index].target_tag = car_info.target_tag;

            release_lock_tags(cars_[car_index].lock_tags);
            cars_[car_index].lock_tags.clear();
            cars_[car_index].lock_tags.push_back(car_info.position_tag);

            update_lock_tags(cars_[car_index].lock_tags);

            //Update_Car_Uninit_Count(car_info.car_id);
            //no need
            //update lock
            // std::vector<int> vec_locktags;
            // vec_locktags.push_back(car_info.position_tag);

            // print_tags(vec_locktags,85);
            // update_lock_tags(vec_locktags);

            return;
        }

        car_index = car_ids_indexs_[car_info.car_id];
        cars_[car_index].total_path = car_info.total_path;

        //update next path
        cars_[car_index].next_path.clear();
        for (int i = 0; i < 3 && i < car_info.total_path.size(); i++)
        {
            cars_[car_index].next_path.push_back(car_info.total_path[i]);
        }
        //
        cars_[car_index].position_tag = car_info.position_tag;
        cars_[car_index].target_tag = car_info.target_tag;

        ask_car_path(car_info.car_id);
    }
}

// update total_path and next_path too
void TrafficManager::update_car_paths(int car_id)
{

    //update total path
    std::vector<int> total_path;
    total_path.clear();
    for (int i = 2; i < cars_[car_ids_indexs_[car_id]].total_path.size(); i++)
    {
        total_path.push_back(cars_[car_ids_indexs_[car_id]].total_path[i]);
    }
    cars_[car_ids_indexs_[car_id]].total_path.clear();
    cars_[car_ids_indexs_[car_id]].total_path = total_path;
    //update next path
    cars_[car_ids_indexs_[car_id]].next_path.clear();
    for (int i = 0; i < 3 && i < cars_[car_ids_indexs_[car_id]].total_path.size(); i++)
    {
        cars_[car_ids_indexs_[car_id]].next_path.push_back(cars_[car_ids_indexs_[car_id]].total_path[i]);
    }

    //update lock_tags:if total path size == 0 , need to lock end_id
    // if (total_path.size() == 0)
    // {
    //     cars_[car_ids_indexs_[car_id]].lock_tags.clear();

    //     lock_if_car_arrive(car_id);
    // }
}

void TrafficManager::update_car_paths_bypath(int car_id, std::vector<int> path)
{
    int size = path.size();

    if (size == 0 || size == 1)
    {
        return;
    }

    int pop_num = size - 1;
    std::vector<int>::iterator iter = cars_[car_ids_indexs_[car_id]].total_path.begin();
    while (pop_num)
    {
        cars_[car_ids_indexs_[car_id]].total_path.erase(iter);
        pop_num--;
    }

    cars_[car_ids_indexs_[car_id]].next_path.clear();
    for (int i = 0; i < 3 && i < cars_[car_ids_indexs_[car_id]].total_path.size(); i++)
    {
        cars_[car_ids_indexs_[car_id]].next_path.push_back(cars_[car_ids_indexs_[car_id]].total_path[i]);
    }
}

void TrafficManager::update_car_locktags(int car_id, std::vector<int> lock_tags)
{
    int car_index = car_ids_indexs_[car_id];
    // if(lock_tags.size()>1)
    // {
    //      lock_tags.erase(lock_tags.begin());
    // }
    cars_[car_index].lock_tags = lock_tags;
}

void TrafficManager::lock_if_car_arrive(int car_id)
{
    std::vector<int> lock_tags;
    lock_tags.push_back(cars_[car_ids_indexs_[car_id]].target_tag);

    print_tags(lock_tags, 146);

    update_lock_tags(lock_tags);
}

//check if car's route conflict with others
bool TrafficManager::CheckPathComflict(std::vector<int> path)
{
    for (int tag : path)
    {
        if (traffic_map_.locks_tag_count.count(tag) > 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<int> TrafficManager::CheckPathCango(std::vector<int> path)
{
    std::vector<int> result;
    result.clear();
    if (path.size() == 0)
    {
        return result;
    }
    for (int i = 0; i < path.size(); i++)
    {
        int tag = path[i];
        if (traffic_map_.locks_tag_count.count(tag) > 0)
        {
            if (traffic_map_.locks_tag_count[tag] > 0)
            {
                if (traffic_map_.locks_tag_state[tag] == LOCKSTATE_EXIT)
                {
                    result.push_back(tag);
                }
                else
                {
                    break;
                }
            }
            else
            {
                result.push_back(tag);
            }
        }
        else
        {
            result.push_back(tag);
        }
    }

    //debug
    // if (result.size() > 0)
    // {
    //     std::cout << "cango :";
    //     for (int i = 0; i < result.size(); i++)
    //     {
    //         std::cout <<result[i] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int size = result.size();
    mutex_traffic_map_.lock();
    for (int i = 0; i < size; i++)
    {
        if (size > 1)
        {
            switch (i)
            {
            case 0:
                traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_EXIT;
                break;
            case 1:
                traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_ENTER;
                break;
            case 2:
                traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_APPROACH;
                break;
            default:
                break;
            }
        }
        else
        {
            traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_STANDBY;
        }
    }
    mutex_traffic_map_.unlock();
    return result;
}

int TrafficManager::Get_CarId_ByPosition(int position)
{
    for (int i = 0; i < cars_.size(); i++)
    {
        if (cars_[i].position_tag == position)
        {
            return cars_[i].car_id;
        }
    }
    return 1000;
}

// bool TrafficManager::check_tag_congestion(int tag_id)
// {
//     return traffic_map_.locks_tag_count.count(tag_id) > 0? true:false;
// }

// path is ok = true, not ok = false;
bool TrafficManager::check_path_position(std::vector<int> path, int car_id)
{
    //get car position except checking car
    std::unordered_set<int> set_position;
    for (int i = 0; i < cars_.size(); i++)
    {
        if (cars_[i].car_id != car_id)
        {
            set_position.insert(cars_[i].position_tag);
        }
    }
    for (int tag : path)
    {
        if (set_position.count(tag) > 0)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> TrafficManager::get_path_by_carid(int car_id)
{
    if (car_ids_indexs_.count(car_id) > 0)
    {
        return cars_[car_ids_indexs_[car_id]].next_path;
    }
}

void TrafficManager::wait_to_go()
{
    std::vector<std::vector<int>> vec_temp;
    while (true)
    {
        usleep(100);

        vec_temp.clear();
        mutex_vec_wait_.lock();

        if (vec_wait_.size() > 0)
        {
            //debug
            //std::cout << "vec_wait is:";
            for (int i = 0; i < vec_wait_.size(); i++)
            {
                vec_temp.push_back(vec_wait_[i]);
                //std::cout << vec_wait_[i][0] << ",";
            }
            //std::cout << std::endl;
            vec_wait_.clear();
        }
        mutex_vec_wait_.unlock();

        if (vec_temp.size() > 0)
        {
            //use iterator
            //for (int i = 0; i < vec_wait_.size(); i++)
            //for (std::vector<std::vector<int>>::iterator iter = vec_wait_.begin(); iter != vec_wait_.end();)
            wait_total_time_ += 0.1*vec_temp.size();
            for (std::vector<std::vector<int>>::iterator iter = vec_temp.begin(); iter != vec_temp.end();)
            {

                //wait too long
                //count +1
                int car_id = (*iter)[0];
                cars_[car_ids_indexs_[car_id]].count_wait++;
//it's for wait count
#if 1
                int count = (*iter)[1];
                //vec_wait_[i][1]++;
                (*iter)[1]++;
                //if(vec_wait_[i][1] == 3000/200)
                if (count == (2000 / 100))
                {
                    //debug
                    //std::cout<<"car "<<vec_wait_[i][0]<<" wait count is "<<vec_wait_[i][1]<<std::endl;
                    //std::cout << "car " << car_id << " wait count is " << count << std::endl;
                    //uninit_car(vec_wait_[i][0]);
                    uninit_car(car_id);
                    iter = vec_temp.erase(iter);
                    wait_toolong_count_++;
                    std::cout<<"car id is "<<car_id<<",wait too long count is "<<wait_toolong_count_<<std::endl;
                    continue;
                    //break;
                }
#endif

                //get next path
                //std::vector<int> path = get_path_by_carid(vec_wait_[i][0]);
                std::vector<int> path = get_path_by_carid(car_id);
                //debug
                //std::cout<<"wait car id is: "<<iter->first<<std::endl;
                //std::vector<int> path = get_path_by_carid(iter->first);

                // if (path.size() <= 1)
                // {
                //     //iter = vec_wait_.erase(iter);
                //     iter = vec_temp.erase(iter);
                //     continue;
                // }

                release_lock_tags(cars_[car_ids_indexs_[car_id]].lock_tags);

                //debug
                mutex_check_congestion_.lock();
                //if (!CheckPathComflict(path) && check_path_position(path, car_id))
                std::vector<int> path_cango = CheckPathCango(path);
                if (path_cango.size() > 0 && check_path_position(path_cango, car_id))
                //if (path_cango.size() > 0)
                {

                    update_lock_tags(path_cango);
                    mutex_check_congestion_.unlock();
                    car_cango cango;
                    cango.car_id = car_id;
                    cango.path = path_cango;
                    mutex_que_cango_.lock();
                    que_cango_.push(cango);
                    mutex_que_cango_.unlock();
                    cars_[car_ids_indexs_[car_id]].lock_tags = path_cango;
                    update_car_paths_bypath(cango.car_id, path_cango);
                    iter = vec_temp.erase(iter);
                }
                else
                {
                    update_lock_tags(cars_[car_ids_indexs_[car_id]].lock_tags);
                    mutex_check_congestion_.unlock();

                    iter++;
                }
            }
            if (vec_temp.size() > 0)
            {
                mutex_vec_wait_.lock();

                for (int i = 0; i < vec_temp.size(); i++)
                {
                    vec_wait_.push_back(vec_temp[i]);
                }
                vec_temp.clear();
                mutex_vec_wait_.unlock();
            }
        }
    }
}

bool TrafficManager::HasCarGo()
{
    //mutex_que_cango_.lock();
    if (que_cango_.size() > 0)
    {
        //mutex_que_cango_.unlock();
        return true;
    }
    return false;
}

std::queue<TrafficManager::car_cango> TrafficManager::GetCarGo()
{
    std::queue<car_cango> result;
    mutex_que_cango_.lock();
    while (que_cango_.size())
    {
        result.push(que_cango_.front());
        //update_lock_tags(que_cango_.front().path);

        //update lock tags by car
        // std::vector<int> lock_tags_by_car;
        // for (int i = 0; i < que_cango_.front().path.size(); i++)
        // {
        //     lock_tags_by_car.push_back(que_cango_.front().path[i]);
        // }
        // cars_[car_ids_indexs_[que_cango_.front().car_id]].lock_tags = lock_tags_by_car;

        //update_car_locktags(que_cango_.front().car_id,que_cango_.front().path);

        if (que_cango_.front().path.size() > 0)
        {
            cars_[car_ids_indexs_[que_cango_.front().car_id]].speed = 200;
        }

        que_cango_.pop();
    }
    mutex_que_cango_.unlock();

    return result;
}

void TrafficManager::update_lock_tags(std::vector<int> path)
{
    mutex_traffic_map_.lock();
    int size = path.size();
    if (size > 1)
    {
        if (traffic_map_.locks_tag_state.count(path[0]) > 0)
        {
            traffic_map_.locks_tag_state[path[0]] = LOCKSTATE_EXIT;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (traffic_map_.locks_tag_count.count(path[i]) > 0)
        {
            traffic_map_.locks_tag_count[path[i]]++;
            if (size > 1)
            {
                switch (i)
                {
                // case 0:
                //     traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_EXIT;
                //     break;
                case 1:
                    traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_ENTER;
                    break;
                case 2:
                    traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_APPROACH;
                    break;
                default:
                    break;
                }
            }
            else
            {
                traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_STANDBY;
            }
            //debug
            // if (traffic_map_.locks_tag_count[path[i]] > 1)
            // {
            //     std::cout << "tag lock is too large\n";
            // }
        }
        else
        {
            traffic_map_.locks_tag_count[path[i]] = 1;
            if (size > 1)
            {
                switch (i)
                {
                // case 0:
                //     traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_EXIT;
                //     break;
                case 1:
                    traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_ENTER;
                    break;
                case 2:
                    traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_APPROACH;
                    break;
                default:
                    break;
                }
            }
            else
            {
                traffic_map_.locks_tag_state[path[i]] = LOCKSTATE_STANDBY;
            }
            //traffic_map_.locks_tag_count.insert(std::make_pair(tag,1));
            //traffic_map_.locks_tag_state[tag]
        }
    }
    mutex_traffic_map_.unlock();
}

void TrafficManager::release_lock_tags(std::vector<int> tags)
{
    mutex_traffic_map_.lock();
    for (int tag : tags)
    {
        if (traffic_map_.locks_tag_count.count(tag) > 0)
        {
            traffic_map_.locks_tag_count[tag]--;
            if (0 == traffic_map_.locks_tag_count[tag])
            {
                traffic_map_.locks_tag_count.erase(tag);
            }
        }
        //todo
        // else
        // {
        //     std::cout << "no such tag locked\n";
        // }
    }
    mutex_traffic_map_.unlock();
}

//todo : should update
void TrafficManager::InitCars(int car_num)
{
    //clear wait
    mutex_vec_wait_.lock();
    //map_wait_.clear();
    vec_wait_.clear();
    mutex_vec_wait_.unlock();
    //release nodes
    for (int i = 0; i < cars_.size(); i++)
    {
        release_lock_tags(cars_[i].lock_tags);
    }
    cars_.clear();
    for (int i = 1; i <= car_num; i++)
    {
        traffic_car car;
        car.car_id = i;
        car.lock_tags.push_back(i);
        car.count_wait = 0;

        //print_tags(car.lock_tags,342);
        update_lock_tags(car.lock_tags);

        cars_.push_back(car);
        car_ids_indexs_.insert(std::make_pair(i, cars_.size() - 1));
    }
}

 void TrafficManager::InitCars_NumPos(std::vector<traffic_car> vec_car_info)
 {
     //clear wait
    mutex_vec_wait_.lock();
    //map_wait_.clear();
    vec_wait_.clear();
    mutex_vec_wait_.unlock();

    int car_num = vec_car_info.size();

    //release nodes
    for (int i = 0; i < cars_.size(); i++)
    {
        release_lock_tags(cars_[i].lock_tags);
    }
    cars_.clear();

    for (int i = 1; i <= car_num; i++)
    {
        traffic_car car;
        car.car_id = vec_car_info[i].car_id;
        car.lock_tags.push_back(vec_car_info[i].position_tag);
        car.count_wait = 0;
        car.position_tag = vec_car_info[i].position_tag;
        car.total_path.clear();

        //print_tags(car.lock_tags,342);
        update_lock_tags(car.lock_tags);

        cars_.push_back(car);
        car_ids_indexs_.insert(std::make_pair(vec_car_info[i].car_id, cars_.size() - 1));
    }
 }

std::unordered_set<int> TrafficManager::lock_tags()
{
    std::vector<int> lock_tags;
    for (auto iter = traffic_map_.locks_tag_count.begin(); iter != traffic_map_.locks_tag_count.end(); ++iter)
    {
        lock_tags.push_back(iter->first);
    }

    std::unordered_set<int> set_tags;
    for (int i = 0; i < lock_tags.size(); i++)
    {
        if (set_tags.count(lock_tags[i]) == 0)
        {
            set_tags.insert(lock_tags[i]);
        }
    }
    return set_tags;
}

//todo
//  TrafficManager::traffic_car TrafficManager::InitCar(int locktag)
//  {

//  }

bool TrafficManager::CheckCarPathInit(int car_id, int end_id)
{
    int car_index = car_ids_indexs_[car_id];
    if (cars_[car_index].car_id == car_id && cars_[car_index].target_tag == end_id && cars_[car_index].total_path.size() > 0)
    {
        return true;
    }
    return false;
}

void TrafficManager::uninit_car(int car_id)
{
    int car_index = car_ids_indexs_[car_id];

    cars_[car_index].total_path.clear();
    cars_[car_index].next_path.clear();

    //move_to_neighbor(car_id);
    //release_lock_tags(cars_[car_index].lock_tags);
    //cars_[car_index].lock_tags.clear();
    //cars_[car_index].lock_tags.push_back(cars_[car_index].position_tag);
    //update_lock_tags(cars_[car_index].lock_tags);

    //debug
    //std::cout << "car " << car_id << "uninited\n";
}

int TrafficManager::Get_neighbors_lock(int id, int size, int direction)
{
    std::vector<int> vec_result;

    int x_index = (id - 1) % size;
    int y_index = (id - 1) / size;

    if (direction == 0)
    {
        if (x_index > 0)
        {
            vec_result.push_back(id - 1);
        }
        if (x_index < size - 1)
        {
            vec_result.push_back(id + 1);
        }
    }
    else if (direction == 1)
    {
        if (y_index > 0)
        {
            vec_result.push_back(id - size);
        }
        if (y_index < size - 1)
        {
            vec_result.push_back(id + size);
        }
    }

    mutex_traffic_map_.lock();
    for (int i = 0; i < vec_result.size(); i++)
    {
        if (traffic_map_.locks_tag_count.count(vec_result[i]) == 0)
        {
            mutex_traffic_map_.unlock();
            return vec_result[i];
        }
    }
    return 0;
}

//this is for chessboard only, if wait too long ,then move to neighbor tag
bool TrafficManager::move_to_neighbor(int car_id, int direction)
{
    int car_index = car_ids_indexs_[car_id];
    int position = cars_[car_index].position_tag;

    int tag_cango = Get_neighbors_lock(position, 10, direction);
    if (tag_cango > 0)
    {
        cars_[car_index].total_path.clear();
        cars_[car_index].next_path.clear();

        cars_[car_index].total_path.push_back(position);
        cars_[car_index].total_path.push_back(tag_cango);

        cars_[car_index].next_path.push_back(position);
        cars_[car_index].next_path.push_back(tag_cango);

        //debug
        std::cout << "car " << car_id << " at " << position << " move to " << tag_cango << std::endl;
        ask_car_path(car_id);
        return true;
    }
    return false;
}

bool TrafficManager::CheckCarPathUninit(int car_id)
{
    return cars_[car_ids_indexs_[car_id]].total_path.size() == 0 ? true : false;
}

int TrafficManager::Get_UninitCar_Target(int car_id)
{
    if (CheckCarPathUninit(car_id))
    {
        return cars_[car_ids_indexs_[car_id]].target_tag;
    }
    return -1;
}

TrafficManager::traffic_car TrafficManager::Make_Traffic_car(int car_id, int position, int target)
{
    traffic_car car;
    car.car_id = car_id;
    car.position_tag = position;
    car.target_tag = target;
    return car;
};

//todo
void TrafficManager::Deal_Task(order_car car_task)
{
    int car_id = car_task.car_id;
    int car_index = car_ids_indexs_[car_id];

    if (car_task.target == -1)
    {
        if (cars_[car_index].total_path.size() > 0)
        {
            ask_car_path(car_id);
        }
    }
    else
    {
        if (cars_[car_index].target_tag != car_task.target)
        {
            //todo get new total_path
            //update_car_paths(...)
        }
    }
}

void TrafficManager::Update_Car_Uninit_Count(int car_id)
{
    // int car_index = car_ids_indexs_[car_id];

    // cars_[car_index].uninit_count++;
    // if (cars_[car_index].uninit_count >= 15)
    // {
    //     move_to_neighbor(car_id);
    //     cars_[car_index].uninit_count = 0;
    // }
}