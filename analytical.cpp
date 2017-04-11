//
//  analytical.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/7.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "analytical.hpp"
float analytical(double T,
                 double Vol,
                 long steps,
                 double spot,
                 double strike,
                 double r,
                 double d,
                 int IsCall)

{
    
    float result = 0;
    double rho = exp(r * (T / steps));
    double eta = exp(d * (T / steps));
    double up = exp(Vol * sqrt(T / steps));
    double down = exp(-Vol * sqrt(T / steps));
    double q = (rho / eta - down) / (up -down);
    double q1 = (up * q) * eta / rho ;

    int alpha = 0;
    
    
    vector<float>last_row(steps + 1,0);
    double price = spot * powf(up, steps);
    for(int i  = 0; i < last_row.size(); ++i)
    {
        last_row[i] = price;
        price *= powf(down, 2);
    }

    for(int i = 0; i < last_row.size(); ++i)
    {
        last_row[i] = last_row[i] - strike;
        last_row[i] = (last_row[i] < 0) ? 0 : last_row[i];
        if(last_row[i] > 0)
        alpha = i;

    }

    result = (spot / powf(eta, steps)) * phi(alpha, steps, q1) - (strike / powf(rho, steps)) * phi(alpha, steps, q);
    return result;
    
    
}