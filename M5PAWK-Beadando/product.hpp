#pragma once
#ifndef _PRODUCT_HPP_
#define _PRODUCT_HPP_
#include <string>
#include <iostream>
using namespace std;

class Product{
public:
    Product(string code,string name,string manifacture,int storageAmount);
    virtual ~Product(){}
    void setCode(string code){code_m=code;}
    void setName(string name){name_m = name;}
    void setManifacture(string manifacture){manifacture_m = manifacture;}
    void setStorageAmount(int storageAmount){storageAmount_m = storageAmount;}
    string code(){return code_m;}
    string name(){return name_m;}
    string manifacture(){return manifacture_m;}
    int storageAmount(){return storageAmount_m;}
    void print();
    virtual int calculatedPrice() =0;
    virtual bool validateCode(string code) =0;
protected:
    string code_m;
    string name_m;
    string manifacture_m;
    int storageAmount_m;
};

ostream& operator<< (ostream&, Product* p);
#endif // _PRODUCT_HPP_
