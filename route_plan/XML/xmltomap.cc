#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <regex>
#include "xmltomap.h"

using namespace tinyxml2;

#define NODEAPP "cCarDrivingNodesApp"
#define NODEMANAGER "cCarDrivingNodeManager"
#define NODEMANAGERNODE "cCarDrivingNode"
#define PATHMANAGER "cCarDrivingPathManager"
#define PATHMANAGERPATH "cCarDrivingPath"
#define PATHMANAGERPATHTIME "cCurveWithTime"
#define PATHMANAGERPATHTIMEDATA "Data"

//make a map with xml file BGTest.xml
Map ReadValueFromXML(const char *XmlPath)
{
    Map map;
    Vec_node vec_nodes;
    Vec_path vec_paths;

    XMLDocument doc;
    XMLError error;

    /* 開啟文件 */
    error = doc.LoadFile(XmlPath);
    if (error == XML_ERROR_FILE_NOT_FOUND)
        printf("open xml failed\n");

    XMLElement *root = doc.RootElement();
    //printf("Root - Name: %s \r\n\r\n", root->Name());
    if (!strcmp(root->Name(), NODEAPP))
    {
        Resolution resol;
        resol.bg = root->Attribute("BGResolution");
        resol.realworld = root->Attribute("RealWorldResolution");
        map.resol = resol;
    }

    XMLElement *manager = root->FirstChildElement();
    while (manager)
    {

        //printf("Node - Name: %s \r\n", manager->Name());
        if (!strcmp(manager->Name(), NODEMANAGER))
        {
            //take the attribute of nodemanager
            int num = atoi(manager->Attribute("Count"));
            XMLElement *ele_node = manager->FirstChildElement();
            for (int i = 0; i < num; i++)
            {
                //store node values
                cCarDrivingNode node;
                node.name = std::string(ele_node->Attribute("Name"));
                node.nodetype = std::string(ele_node->Attribute("NodeType"));
                node.speed = std::string(ele_node->Attribute("Speed"));
                node.pos = std::string(ele_node->Attribute("Pos"));
                node.rfid = std::string(ele_node->Attribute("RFID"));
                node.relativenode = std::string(ele_node->Attribute("RelativeNode"));

                const XMLAttribute *attr_node = ele_node->FirstAttribute();
                //std::cout<<attr_node->Name()<<" : "<<attr_node->Value()<<"\n";

                vec_nodes.push_back(node);

                ele_node = ele_node->NextSiblingElement();
            }
        }
        // store paths
        if (!strcmp(manager->Name(), PATHMANAGER))
        {
            int num = atoi(manager->Attribute("Count"));
            XMLElement *ele_path = manager->FirstChildElement();
            for (int i = 0; i < num; i++)
            {
                //store path values
                cCarDrivingPath path;
                path.name = std::string(ele_path->Attribute("Name"));
                path.startnode = std::string(ele_path->Attribute("StartNode"));
                path.endnode = std::string(ele_path->Attribute("EndNode"));
                path.nodetype = std::string(ele_path->Attribute("NodeType"));
                path.speed = std::string(ele_path->Attribute("Speed"));

                //time value
                XMLElement *ele_time = ele_path->FirstChildElement();
                cCurveWithTime time;
                time.name = std::string(ele_time->Attribute("Name"));
                time.count = std::string(ele_time->Attribute("Count"));
                time.lod = std::string(ele_time->Attribute("LOD"));

                //Data value
                XMLElement *ele_data = ele_time->FirstChildElement();
                Data data;
                data.pos = std::string(ele_data->Attribute("Pos"));
                data.time = std::string(ele_data->Attribute("Time"));

                time.data = data;
                path.time = time;

                vec_paths.push_back(path);

                ele_path = ele_path->NextSiblingElement();
            }
        }

        manager = manager->NextSiblingElement();
    }

    map.vec_node = vec_nodes;
    map.vec_path = vec_paths;
    return map;
}

//split string by ","  to floats
std::vector<float> MakePosition(std::string str_pos)
{
    std::vector<float> vec_result;

    std::regex re(",");
    std::vector<std::string> vec_str(std::sregex_token_iterator(str_pos.begin(), str_pos.end(), re, -1),
                                     std::sregex_token_iterator());

    //check the split
    for (int i = 0; i < vec_str.size(); i++)
    {
        //std::cout<<vec_str[i]<<std::endl;
        vec_result.push_back(std::stof(vec_str[i]));
    }

    return vec_result;
}

//split string by "," to ints
std::vector<int> MakeNeighbors(std::string str_neighbors)
{
    std::vector<int> vec_result;

    std::regex re(",");
    std::vector<std::string> vec_str(std::sregex_token_iterator(str_neighbors.begin(), str_neighbors.end(), re, -1),
                                     std::sregex_token_iterator());

    //check the split
    for (int i = 0; i < vec_str.size(); i++)
    {
        //std::cout<<vec_str[i]<<std::endl;
        vec_result.push_back(std::stof(vec_str[i]));
    }

    return vec_result;
}

//currently just need node infos, path infos need to do
Vec_MyNode
XmlMapToMyMap(Map map)
{
    //deal with nodes
    Vec_MyNode vec_result;

    for (int i = 0; i < map.vec_node.size(); i++)
    {
        MyNode node;
        node.id = std::stoi(map.vec_node[i].name);
        //node.type = std::stoi(map.vec_node[i].nodetype);

        //make realworld position
        std::vector<float> vec_bg = MakePosition(map.resol.bg);
        std::vector<float> vec_realworld = MakePosition(map.resol.realworld);
        float rate_x = vec_realworld[0] / vec_bg[0];
        float rate_y = vec_realworld[1] / vec_bg[1];

        std::vector<float> vec_pos = MakePosition(map.vec_node[i].pos);
        Position pos;
        pos.x = vec_pos[0] * rate_x;
        pos.y = vec_pos[1] * rate_y;
        pos.z = vec_pos[2];
        node.pos = pos;
//make pixel position
#if 0
        std::vector<float> vec_pos = MakePosition(map.vec_node[i].pos);
        Position pos;
        pos.x = vec_pos[0];
        pos.y = vec_pos[1];
        pos.z = vec_pos[2];
        node.pos = pos;
#endif

        //make neighbors
        node.neighbors = MakeNeighbors(map.vec_node[i].relativenode);

        vec_result.push_back(node);
    }

    return vec_result;
}

std::vector<MyTypeNode> XmlMapToMyMap_Type(Map map)
{
    //deal with nodes
    std::vector<MyTypeNode> vec_result;

    for (int i = 0; i < map.vec_node.size(); i++)
    {
        MyTypeNode node;
        node.id = std::stoi(map.vec_node[i].name);
        node.type = std::stoi(map.vec_node[i].nodetype);

        //make realworld position
        std::vector<float> vec_bg = MakePosition(map.resol.bg);
        std::vector<float> vec_realworld = MakePosition(map.resol.realworld);
        float rate_x = vec_realworld[0] / vec_bg[0];
        float rate_y = vec_realworld[1] / vec_bg[1];

        std::vector<float> vec_pos = MakePosition(map.vec_node[i].pos);
        Position pos;
        pos.x = vec_pos[0] * rate_x;
        pos.y = vec_pos[1] * rate_y;
        pos.z = vec_pos[2];
        node.pos = pos;
//make pixel position
#if 0
        std::vector<float> vec_pos = MakePosition(map.vec_node[i].pos);
        Position pos;
        pos.x = vec_pos[0];
        pos.y = vec_pos[1];
        pos.z = vec_pos[2];
        node.pos = pos;
#endif

        //make neighbors
        node.neighbors = MakeNeighbors(map.vec_node[i].relativenode);

        vec_result.push_back(node);
    }

    return vec_result;   
}

std::vector<int> GetCustomers(Map map)
{
    std::vector<int> result;

    for (int i = 0; i < map.vec_node.size(); i++)
    {

        int type = std::stoi(map.vec_node[i].nodetype);
        if (1 == type)
        {
            int id = std::stoi(map.vec_node[i].name);
            result.push_back(id);
        }
    }

    return result;
}