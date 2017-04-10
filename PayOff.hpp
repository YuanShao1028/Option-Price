//
//  PayOff.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/3/3.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef PayOff_hpp
#define PayOff_hpp

#include <stdio.h>

class PayOff
{
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){};
    virtual PayOff* clone() const = 0;
private:
};

class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){};
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffPut : public PayOff
{
public:
    PayOffPut(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){};
    virtual PayOff* clone() const;
private:
    double Strike;
};

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_,
                        double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){};
    virtual PayOff* clone() const;
private:
    double LowerLevel;
    double UpperLevel;
};


#endif /* PayOff_hpp */