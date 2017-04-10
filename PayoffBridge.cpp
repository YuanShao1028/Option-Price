//
//  PayoffBridge.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/3/3.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "PayoffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
    ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge()
{
    delete ThePayOffPtr;
}


PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
    if (this != &original)
    {
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}