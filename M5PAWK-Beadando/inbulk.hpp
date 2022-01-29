#pragma once
#ifndef _INBULK_HPP_
#define _INBULK_HPP_


#include <string>
#include "product.hpp"
using namespace std;

class Inbulk:public Product
{
public:
    Inbulk(string code,string name,string manifacture,int storageAmount,int pricepergramm,int weight);
    void setPricePerGramm(int price){pricepergramm_m = price;}
    int pricepergramm(){return pricepergramm_m;}
    void setWeight(int weight){weight_m = weight;}
    int weight(){return weight_m;}
    int calculatedPrice();
    bool validateCode(string code);
protected:
    int pricepergramm_m;
    int weight_m;
};

#endif // _INBULK_HPP_
