//
//  Black_Scholes.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/7.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "Black_Scholes.hpp"


Black_Scholes::Black_Scholes(double r_, double d_, double Vol_,double expire_,double strike_, int IsCall_): r(r_), d(d_), Vol(Vol_),
                            expire(expire_), strike(strike_), IsCall(IsCall_)
{
    
    
}
double Black_Scholes::get_price(double t, double spot)
{
    double price = 0;
    double d1 = (log(spot / strike) + (r + Vol * Vol * 0.5 - d) * (expire - t)) / (Vol * (sqrt(expire - t)));
    double d2 = d1 - Vol * (sqrt(expire - t));

    if(IsCall)
        price = spot * exp(-d * (expire - t)) * cdf(d1) - strike * exp(-r * (expire - t)) * cdf(d2);
    else
    price = strike * exp(-r * (expire - t)) * cdf(-d2) - spot * exp(-d * (expire - t)) * cdf(-d1);
    
    return price;
    
}