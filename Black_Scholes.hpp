//
//  Black_Scholes.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/7.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef Black_Scholes_hpp
#define Black_Scholes_hpp

#include <stdio.h>
#include <cmath>
#include "tool.hpp"
#include <math.h>
#include <iostream>
using namespace std;

#endif /* Black_Scholes_hpp */

class Black_Scholes
{
private:
    //double Spot;
    double r;
    double d;
    double Vol;
    double expire;
    double strike;
    int IsCall;
public:
    Black_Scholes(double r_, double d_, double Vol_,double expire_,double strike_,int IsCall_);
    double get_price(double t, double spot);
    
    
};