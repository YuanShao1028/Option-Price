//
//  main.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/3/3.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <stdlib.h>
#include "PayOff.hpp"
#include "PayoffBridge.hpp"
#include "Binarytree.hpp"
#include "tool.hpp"
#include "analytical.hpp"
#include "Black_Scholes.hpp"
#include "Process_File.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    
    unordered_map<string,string> map = read_configuration("configuration.txt");
    double expire;
    double Vol;
    long steps;
    double spot;
    double strike;
    double r;
    double d;
    int IsCall;
    int Option_type;
    bool expire_used = get_double(map, expire, "expire");
    bool Vol_used = get_double(map, Vol, "Vol");
    bool steps_used = get_long(map, steps, "steps");
    bool spot_used = get_double(map,spot,"spot");
    bool strike_used = get_double(map,strike,"strike");
    bool r_used = get_double(map,r,"r");
    bool d_used = get_double(map,d,"d");
    bool IsCall_used = get_int(map, IsCall, "IsCall"); // Call : 1 Put : 0
    bool Option_type_used = get_int(map, Option_type, "Option_type"); // Euro : 0 America : 1
    print_map(map);
    PayOffPut payoffput = PayOffPut(strike);
    PayOffCall payoffcall = PayOffCall(strike);
    PayOff &payoff1 = payoffcall;
    PayOff &payoff2 = payoffput;
    BinaryTree* tree1;
    if(IsCall && !Option_type)  tree1 = new Europe_Tree(spot, r, d, Vol, steps, expire,payoff1);
    else if(IsCall && Option_type) tree1 = new America_Tree(spot, r, d, Vol, steps, expire,payoff1);
    else if(!IsCall && !Option_type) tree1 = new Europe_Tree(spot, r, d, Vol, steps, expire,payoff2);
    else  tree1 = new America_Tree(spot, r, d, Vol, steps, expire,payoff2);
    tree1->print_var();
    tree1->forward();
    tree1->backward();
    cout<<"price:"<<tree1->getPrice()<<endl;
    cout<<"End binary tree"<<endl;
    Black_Scholes bs = Black_Scholes(r, d, Vol, expire, strike, IsCall);
    float bs_price = bs.get_price(0, spot);
    cout<<"bs_price : "<<bs_price<<endl;
    return 0;
 
    
}
