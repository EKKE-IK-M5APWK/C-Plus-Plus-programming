#pragma once
#ifndef _PIECE_HPP_
#define _PIECE_HPP_

#include <string>
#include "product.hpp"
using namespace std;

class Piece: public Product
{
public:
    Piece(string code,string name,string manifacture,int storageAmount,int price);
    void setPrice(int price){price_m = price;}
    int price(){return price_m;}
    int calculatedPrice();
    bool validateCode(string code);
protected:
    int price_m;
};



#endif // _PIECE_HPP_
