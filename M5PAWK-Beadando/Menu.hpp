#pragma once

#include <array>
#include <string>
#include "product.hpp"

using namespace std;

class Menu{
public:
    Menu(): index_m(0){}
    ~Menu();
    void execute();
    void inputProductTpye();
    void addProcuts();
    void witdrawProducts();
    void listProducts();
    bool checkNaplo(fstream& file);
    void readNaplo(fstream& file);
private:
    int index_m;
    std::array<Product*, 100> storage_m;
};
