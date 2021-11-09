#include "map.h"
#include<iostream>
#include<unordered_set>

std::vector<int> Get_neighbors(int id, int size)
{
    std::vector<int> vec_result;

    int x_index = (id-1)%size;
    int y_index = (id-1)/size;
    if(x_index >0)
    {
        vec_result.push_back(id-1);
    }
    if(x_index<size-1)
    {
        vec_result.push_back(id+1);
    }
    if(y_index >0)
    {
        vec_result.push_back(id-size);
    }
    if(y_index<size-1)
    {
        vec_result.push_back(id+size);
    }

    //print neigbors
    // std::cout<<"neigbors is ";
    // for(int i:vec_result)
    // {
    //     std::cout<<i<<",";
    // }
    // std::cout<<std::endl;

    return vec_result;
}

std::vector<int> Get_neighbors_lock(int id, int size,std::unordered_set<int> lock_tags)
{
    std::vector<int> vec_result;

    int x_index = (id-1)%size;
    int y_index = (id-1)/size;
    if(x_index >0&&lock_tags.count(id-1)==0)
    {
        vec_result.push_back(id-1);
    }
    if(x_index<size-1&&lock_tags.count(id+1)==0)
    {
        vec_result.push_back(id+1);
    }
    if(y_index >0&&lock_tags.count(id-size)==0)
    {
        vec_result.push_back(id-size);
    }
    if(y_index<size-1&&lock_tags.count(id+size)==0)
    {
        vec_result.push_back(id+size);
    }

    //print neigbors
    // std::cout<<id <<"'s neigbors is ";
    // for(int i:vec_result)
    // {
    //     std::cout<<i<<",";
    // }
    // std::cout<<std::endl;

    return vec_result;
}

Position Get_pos(int id, int size)
{
    Position pos;
    pos.z = 0.0;

    if (id % size == 0)
    {
        pos.x = size - 0.5;
        pos.y = id/size - 0.5;
    }
    else
    {
        pos.x = id%size - 0.5;
        pos.y = id/size + 0.5;
    }

    //print position
    //std::cout<<"pos is "<<pos.x<<" "<<pos.y<<std::endl;
    return pos;
}

Vec_MyNode Make_map(int size)
{
    Vec_MyNode map;
    for (int i = 0; i < size*size; i++)
    {
        MyNode node;
        node.id = i + 1;
        node.pos = Get_pos(node.id, size);
        node.neighbors = Get_neighbors(node.id, size);
        map.push_back(node);
    }
    return map;
}

Vec_MyNode Make_map_locks(int size, std::unordered_set<int> lock_tags)
{
    Vec_MyNode map;
    for (int i = 0; i < size*size; i++)
    {
        MyNode node;
        node.id = i + 1;
        node.pos = Get_pos(node.id, size);
        node.neighbors = Get_neighbors_lock(node.id, size,lock_tags);
        map.push_back(node);
    }
    return map;
}

Vec_MyNode Update_XML_map_locks(Vec_MyNode map,std::unordered_set<int> lock_tags)
{
    //debug
    //std::cout<<"update map"<<std::endl;
    Vec_MyNode result;
    for(int i=0;i<map.size();i++)
    {
        MyNode node;

        //check id
        int tag_id = map[i].id;
        node.id = tag_id;
        // if(lock_tags.count(tag_id)>0)
        // {
        //     continue;
        // }

        //check neighbors
        for(int j=0;j<map[i].neighbors.size();j++)
        {
            if (lock_tags.count(map[i].neighbors[j])>0)
            {
                continue;
            }
            else
            {
                node.neighbors.push_back(map[i].neighbors[j]);
            }
        }

        node.pos = map[i].pos;

        result.push_back(node);
    }

    //debug 
    // std::cout<<"map size is " <<result.size()<<std::endl;
    // for(int i=0;i<result.size();i++)
    // {
    //     std::cout<<result[i].id<<":";
    //     for(int j=0;j<result[i].neighbors.size();j++)
    //     {
    //         std::cout<<result[i].neighbors[j]<<",";
    //     }
    //     std::cout<<std::endl;
    // }
    return result;
}