
#ifndef MONGODBMANAGER
#define MONGODBMANAGER

#include <cstdint>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <mutex>
#include<thread>
#include<unistd.h>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include "dbmanagement_common.h"

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using dbmanagement_common::Goods_Info;
using dbmanagement_common::Order_Data;
using dbmanagement_common::Order;

class MongodbManager
{
public:
    static MongodbManager *GetInstance();
    //void operator=(const MongodbManager &) = delete;
    //  explicit MongodbManager()
    // {
    //     mongocxx::instance instance{};
    // }


    bool Init();
    bool OpenDB(std::string db_name);
    bool OpenCollection(std::string coll_name);
    bool Insert(Order order);
    bool Multi_Insert();
    bool Delete_by_filter();
    bool Multi_Delete();
    Order Find_by_filter(int order_num);
    bool Multi_Find();
    bool Update();
    bool Multi_Update();

protected:
    explicit MongodbManager()
    {
        mongocxx::instance instance{};
    }

private:
    Order Trans_Json_To_Order(bsoncxx::document::view view);
    bool rool_back();
private:
    static MongodbManager *instance_;
    static std::mutex mutex_instance_;
private:
    mongocxx::client *ptr_client_;
    mongocxx::database db_;
    mongocxx::collection coll_;
};

#endif