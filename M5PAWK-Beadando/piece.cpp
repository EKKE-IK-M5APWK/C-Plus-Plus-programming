#pragma once
#ifndef _PIECE_CPP_
#define _PIECE_CPP_

#include "piece.hpp"


Piece::Piece(string code,string name,string manifacture,int storageAmount,int price): Product(code,name,manifacture,storageAmount), price_m(price){};
bool Piece::validateCode(string code){
    if(code.size() ==13 || code.size() == 8)
    {
        return true;
    }
    return false;
}

int Piece::calculatedPrice()
{
    return price_m;
}
#endif // _PIECE_CPP_
