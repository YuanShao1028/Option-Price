//
//  analytical.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/7.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef analytical_hpp
#define analytical_hpp
#include <stdio.h>
#include <vector>
#include <iostream>
#include "tool.hpp"
using namespace std;
float analytical(double T,
                 double Vol,
                 long steps,
                 double spot,
                 double strike,
                 double r,
                 double d,
                 int IsCall);




#endif /* analytical_hpp */
