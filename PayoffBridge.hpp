//
//  PayoffBridge.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/3/3.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef PayoffBridge_hpp
#define PayoffBridge_hpp

#include <stdio.h>
#include "PayOff.hpp"


class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator ()(Spot);
}






#endif /* PayoffBridge_hpp */
