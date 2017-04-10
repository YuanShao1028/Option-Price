//
//  tool.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/7.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "tool.hpp"

double Comb(long n, long m)
{
    if(m == 0 || n == m) return 1;
    long tmp = n - m;
    long sb = ((m <= tmp) ? m : tmp);
    double f = 1;
    double f1 = 0;
    for(double i = 1; i <= sb; ++i)
    {
        f1 = f * (n - i + 1) / (i);
        f = f1;
    }
    return f1;
}

double phi(double n, double m, float p)
{
    double sum = 0;
    for(int i = 0; i <= n; ++i)
    {
        // cout <<i<<"   "<<Comb(m, i)<<"   "<<powf(p, m - i) * powf( 1 - p, i)<<endl;
        sum += Comb(m, i) * powf(p, m - i) * powf( 1 - p, i);
    }
    return sum;
}

double cdf(double x)
{
    double result = 0;
    result = 0.5 * (1 + erf(x / sqrt(2)));
    return result;
}

