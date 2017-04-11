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
    bool expire_used = get_double(map, expire, "expire");
    bool Vol_used = get_double(map, Vol, "Vol");
    bool steps_used = get_long(map, steps, "steps");
    bool spot_used = get_double(map,spot,"spot");
    bool strike_used = get_double(map,strike,"strike");
    bool r_used = get_double(map,r,"r");
    bool d_used = get_double(map,d,"d");
    bool IsCall_used = get_int(map, IsCall, "IsCall");
    
    print_map(map);
    
    
    PayOffPut payoffput = PayOffPut(strike);
    PayOffCall payoffcall = PayOffCall(strike);
    PayOff &payoff1 = payoffcall;
    PayOff &payoff2 = payoffput;
    vector<double> result;
    
    if(IsCall)
    {
        
        BinaryTree* tree = new Europe_Tree(spot, r, d, Vol, steps, expire,payoff1);
        tree->print_var();
        tree->forward();
       // tree.print_leaves(true);
        tree->backward();
       // tree.print_leaves(false);
        cout<<"spot : "<<spot<<"  price : "<<tree->getPrice()<<endl;
            result.push_back(tree->getPrice());
        
        
        }
    else{
        BinaryTree* tree = new America_Tree(spot, r, d, Vol, steps, expire,payoff2);
        tree->print_var();
        tree->forward();
        tree->print_leaves(true);
        tree->backward();
        tree->print_leaves(false);
        cout<<"price:"<<tree->getPrice()<<endl;
    }
    
    
    cout<<"End binary tree"<<endl;
    cout<<"begin analytics"<<endl;
    float res = analytical(expire,Vol,steps,spot,strike,r,d,IsCall);
    cout<<"analytics price : "<<res<<endl;
    
    Black_Scholes bs = Black_Scholes(r, d, Vol, expire, strike, IsCall);
    float bs_price = bs.get_price(0, spot);
    cout<<"bs_price : "<<bs_price;
    
    
    
   // cout<<"cdf : "<<cdf(1.96)<<endl;
    

    return 0;
    
    
}
