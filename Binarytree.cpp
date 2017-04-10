//
//  Binarytree.cpp
//  Options Pricing
//
//  Created by Shaoyuan on 17/4/6.
//  Copyright © 2017年 Shaoyuan. All rights reserved.
//

#include "Binarytree.hpp"



BinaryTree::BinaryTree(double Spot_, double r_, double d_, double Vol_, long steps_, double T_, PayOff &payoff_):Spot(Spot_), r(r_), d(d_), Vol(Vol_), steps(steps_), T(T_), payoff(payoff_)
{
    discount = exp(-r * (T / steps));
    ascend = exp(Vol * sqrt(T / steps));
    descend = exp(-Vol * sqrt(T / steps));
    ascending_prob = (exp((r - d) * (T / steps)) - descend) / (ascend - descend);
}

void BinaryTree::print_var()
{
    cout<<"discount : "<<discount<<endl;
    cout<<"ascend : "<<ascend<<endl;
    cout<<"descend : "<<descend<<endl;
    cout<<"prob : "<<ascending_prob<<endl;
    
    
}

void BinaryTree::set_payoff(PayOff &payoff_)
{
    
    payoff = payoff_;
}


void BinaryTree::forward_naive()
{
    leaves.resize(steps + 1);
    double init = log(Spot);
    for(long i = 0; i <= steps; ++i)
    {
        
        leaves[i].resize(i + 1);
        double cur = (i * T) / steps;
        double drift = (r - d - 0.5 * 0.5 * Vol) * cur;
        double cur_spot = init + drift;
        double changed = Vol * sqrt(T / steps);
        long k = 0;
        for(long j = -i; j <= i; j += 2, ++k )
        {
            leaves[i][k].first = exp(cur_spot + j * changed);
        }
    }
    
}


void BinaryTree::forward()
{
    leaves.resize(steps + 1);
    double init = log(Spot);
    for(long i = 0; i <= steps; ++i)
    {
        
        leaves[i].resize(i + 1);
        //double cur = (i * T) / steps;
        //double drift = (r - d - 0.5 * 0.5 * Vol) * cur;
        //double cur_spot = init + drift;
        double changed = log(ascend);
        long k = 0;
        for(long j = -i; j <= i; j += 2, ++k )
        {
            leaves[i][k].first = exp(init+ j * changed);
        }
    }
    
}


void BinaryTree::backward_naive()
{
    
    for(int i = 0; i < leaves[steps].size(); i++)
    {
       // cout<<"spot"<<leaves[steps][i].first<<endl;
        leaves[steps][i].second = payoff(leaves[steps][i].first);
        
    }
    for(long i = steps - 1; i >= 0; --i)
    {
        for(int k = 0; k <= i; ++k)
        {
            leaves[i][k].second = (discount * 0.5) * (leaves[i + 1][k].second + leaves[i + 1][k + 1].second);
        }
    }
    
}


void BinaryTree::backward()
{

    for(int i = 0; i < leaves[steps].size(); i++)
    {
       // cout<<"spot"<<leaves[steps][i].first<<endl;
        leaves[steps][i].second = payoff(leaves[steps][i].first);
    }
    for(long i = steps - 1; i >= 0; --i)
    {
        for(int k = 0; k <= i; ++k)
        {
            leaves[i][k].second = (discount) * (leaves[i + 1][k+1].second * ascending_prob + leaves[i + 1][k].second * (1 - ascending_prob));
        }
    }
    
}

double BinaryTree::getPrice()
{
    return leaves[0][0].second;
}

void print_vector(vector<pair<double,double>> &vec,bool fst)
{
    if(fst)
    {
    for(auto p : vec)
    {
        cout<<p.first<<" ";
    }
    }
    else
    {
    for(auto p : vec)
    {
        cout<<p.second<<" ";
    }
    }
    cout<<endl;
}

void BinaryTree::print_leaves(bool fst)
{
    for(int i = 0; i < leaves.size(); ++i)
    {
        cout << i<<endl;
        cout<<"sizei "<<leaves[i].size()<<endl;
        print_vector(leaves[i],fst);
        /*for(int j = 0; j < leaves[i].size(); ++i)
        {
            
            cout<<leaves[i][j].first<<" ";
        }
        cout<<endl;*/
    }
   // cout<<leaves[0][0].first;
  
   // cout<<leaves[11][0].first-leaves[10][0].first<<" "<<leaves[12][0].first-leaves[11][0].first<<" "<<leaves[12][0].first;
}

double BinaryTree::get_discount()
{
    return discount;
    
}