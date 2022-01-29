#pragma once
#ifndef _INBULK_CPP_
#define _INBULK_CPP_

#include "inbulk.hpp"

Inbulk::Inbulk(string code,string name,string manifacture,int storageAmount,int pricepergramm,int weight): Product(code,name,manifacture,storageAmount), pricepergramm_m(pricepergramm),weight_m(weight){};
bool Inbulk::validateCode(string code){
    if(code.size() == 10)
    {
        return true;
    }
    return false;
}

int Inbulk::calculatedPrice()
{
    return pricepergramm_m * weight_m;
}

#endif // _INBULK_CPP_
