//
//  PayOff.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/3/3.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "PayOff.hpp"
#include "minmax.h"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator () (double Spot) const
{
    return max(Spot-Strike,0.0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

double PayOffPut::operator () (double Spot) const
{
    return max(Strike-Spot,0.0);
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{    
}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_,
                                         double UpperLevel_)
:   LowerLevel(LowerLevel_),
UpperLevel(UpperLevel_)
{ }

double PayOffDoubleDigital::operator()(double Spot) const
{
    if (Spot <= LowerLevel)
        return 0;
    if (Spot >= UpperLevel)
        return 0;
    return 1;
}

PayOff* PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(*this);
}
