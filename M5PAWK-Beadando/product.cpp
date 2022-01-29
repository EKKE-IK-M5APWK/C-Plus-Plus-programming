#pragma once
#ifndef _PRODUCT_CPP_
#define _PRODUCT_CPP_

#include <iostream>
#include <string>
#include "product.hpp"

using namespace std;

Product::Product(string code,string name,string manifacture,int storageAmount): code_m(code), name_m(name), manifacture_m(manifacture), storageAmount_m(storageAmount){}

void Product::print()
{
    cout << code_m << " " << name_m << " " << manifacture_m << " " << storageAmount_m << endl;
}

ostream& operator<<(ostream& s, Product* p)
{
    s << "[" <<p->code() << "]" << " Név:" << p->name() << " Gyártó:" << p->manifacture() << " Raktár mennyiség(db):" << p->storageAmount() << " Ár:"<< p->calculatedPrice();
    return s;
}

#endif // _PRODUCT_CPP_
