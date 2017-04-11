//
//  Process_File.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/11.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef Process_File_hpp
#define Process_File_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <stdlib.h>
using namespace std;

void trim(string &s);

pair<string,string> split_pair(char* s, const char *delim);

unordered_map<string,string> read_configuration(string filename);

void print_map(unordered_map<string,string> map);

bool get_double(unordered_map<string,string> map, double &target, string key);

bool get_int(unordered_map<string,string> map, int &target, string key);

bool get_long(unordered_map<string,string> map, long &target, string key);








#endif /* Process_File_hpp */
