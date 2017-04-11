//
//  Process_File.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/11.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "Process_File.hpp"

void trim(string &s)
{
    
    if( !s.empty() )
    {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
    
}


pair<string,string> split_pair(char* s, const char *delim)
{
    string p;
    string q;
    p = strtok(s,delim);
    trim(p);
    q = strtok(NULL,delim);
    trim(q);
    return make_pair(p, q);
}

unordered_map<string,string> read_configuration(string filename)
{
    unordered_map<string, string> map;
    ifstream in(filename);
    string s;
    while(getline(in,s))
    {
        char* c = new char[50];
        strcpy(c, s.c_str());
        map.insert(split_pair(c, ":"));
    }
    return map;
}
void print_map(unordered_map<string,string> map)
{
    for(auto i = map.begin(); i != map.end(); ++i)
        cout<<i->first<<"   "<<i->second<<endl;
}

bool get_double(unordered_map<string,string> map, double &target, string key)
{
    if(map.find(key) != map.end())
    {
        target = atof(map[key].c_str());
        return true;
    }
    return false;
}

bool get_int(unordered_map<string,string> map, int &target, string key)
{
    if(map.find(key) != map.end())
    {
        target = atoi(map[key].c_str());
        return true;
    }
    return false;
    
}

bool get_long(unordered_map<string,string> map, long &target, string key)
{
    if(map.find(key) != map.end())
    {
        target = atol(map[key].c_str());
        return true;
    }
    return false;
    
}