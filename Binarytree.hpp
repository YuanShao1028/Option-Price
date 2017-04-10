//
//  Binarytree.hpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/6.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#ifndef Binarytree_hpp
#define Binarytree_hpp

#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "PayOff.hpp"
using namespace std;

class BinaryTree
{
private:
    double Spot;
    double r;
    double d;
    double Vol;
    long steps;
    double T;
    vector<vector<pair<double,double>>> leaves;
    double discount;
    double ascend;
    double descend;
    double ascending_prob;
    PayOff &payoff;

public:

    BinaryTree(double Spot_, double r_, double d_, double Vol_, long steps_, double T_, PayOff &payoff);
    void forward_naive();
    void backward_naive();
    void set_payoff(PayOff &payoff_);
    void forward();
    void backward();
    double getPrice();
    void print_leaves(bool fst);
    double get_discount();
    void print_var();
    
    

};


#endif /* Binarytree_hpp */

