#include <iostream>
#include <string>
#include <stdlib.h>
#include "Menu.hpp"
#include "product.hpp"
#include "piece.hpp"
#include "inbulk.hpp"
#include "fstream"

using namespace std;

void Menu::execute()
{
    bool isRunning = true;
    fstream file;
    file.open("naplo.txt", ios::app);
    if (!checkNaplo(file))
    {
        return;
    }
    file.close();
    while (isRunning)
    {
        string selectedItem;
        cout << "*******************************" << endl;
        cout << "Főmenü\n";
        cout << " 1 - Újabb árutípus felvétele." << endl;
        cout << " 2 - Adott mennyiségű árucikk bevitele a raktárba." << endl;
        cout << " 3 - Adott mennyiségű árucikk kivétele a raktárból." << endl;
        cout << " 4 - Jelenlegi árukészlet listázása." << endl;
        cout << " 5 - Kilépés." << endl;
        cout << " 6 - Naplófájl beolvasása." << endl;
        cout << " Kérem válasszon menüpontot és nyomjon egy entert.: ";
        cin >> selectedItem;
        cout << endl;

        char sel = selectedItem[0];

        switch (sel)
        {
        case '1':
            inputProductTpye();
            break;
        case '2':
            addProcuts();
            break;
        case '3':
            witdrawProducts();
            break;
        case '4':
            listProducts();
            break;
        case '5':
            isRunning = false;
            break;
        case '6':
            readNaplo(file);
            break;
        default:
            cout << "Ismeretlen kifejezés!" << endl;
            break;
        }
    }
}

void Menu::inputProductTpye()
{
    bool isNextInput = true;
    string code, name, manifacture, buffer;
    int price, weight, storageAmount;
    fstream file;
    file.open("naplo.txt", ios::app);
    while (isNextInput)
    {
        cout << "Termék neve:" << endl;
        cin >> name;
        cout << "Termék gyártója:" << endl;
        cin >> manifacture;
        cout << "Termék raktári mennyisége:" << endl;
        cin >> buffer;
        storageAmount = atoi(buffer.c_str());
        cout << "Darabárú vagy Lédig? (d/l): ";
        cin >> buffer;
        if (buffer[0] == 'd')
        {
            cout << "Termék Kód(8 vagy 10 karakter): ";
            cin >> code;

            cout << "Ár: ";
            cin >> buffer;
            price = atoi(buffer.c_str());
            Piece *piece = new Piece(code, name, manifacture, storageAmount, price);
            storage_m[index_m] = piece;
            file << "[inputProductTpye]-> " << storage_m[index_m];
        }
        if (buffer[0] == 'l')
        {
            cout << "Termék Kód(10 karakter): ";
            cin >> code;
            cout << "Ár súlyegységenként: ";
            cin >> buffer;
            price = atoi(buffer.c_str());
            cout << "Súly(g): ";
            cin >> buffer;
            weight = atoi(buffer.c_str());
            Inbulk *inbulk = new Inbulk(code, name, manifacture, storageAmount, price, weight);
            while (!inbulk->validateCode(code))
                if (inbulk->validateCode(code))
                {
                    cout << "A megadott kód validálva." << endl;
                }
                else
                {
                    cout << "Termék Kód(10 karakter): ";
                    cin >> code;
                };
            storage_m[index_m] = inbulk;
            file << "[inputProductTpye]-> " << storage_m[index_m] << endl;
        }
        cout << storage_m[index_m] << endl;
        ++index_m;

        cout << "Következő termék? (i/n)" << endl;
        char c;
        cin >> c;
        isNextInput = (c == 'i') ? true : false;
        cout << endl;
    }
}

void Menu::listProducts()
{
    for (int i = 0; i < index_m; ++i)
    {
        cout << storage_m[i] << "Ár:" << storage_m[i]->calculatedPrice() << endl;
    }
}

void Menu::addProcuts()
{
    fstream file;
    file.open("naplo.txt", ios::app);
    bool isAdded = true;
    string code, buffer;
    int addedAmount, amount;
    while (isAdded)
    {
        cout << "Kérem adja meg a termék kódját:";
        cin >> code;
        cout << "Kérem adja meg a meg mennyivel bővítené a raktárkészletet:";
        cin >> buffer;
        addedAmount = atoi(buffer.c_str());
        for (int i = 0; i < index_m; ++i)
        {
            if (storage_m[i]->code() == code)
            {
                amount = storage_m[i]->storageAmount() + addedAmount;
                storage_m[i]->setStorageAmount(amount);
            }
            file << "[addProcuts]->" << storage_m[i] << endl;
            cout << storage_m[i] << endl;
        }
        cout << "Következő termék? (i/n)" << endl;
        char c;
        cin >> c;
        isAdded = (c == 'i') ? true : false;
        cout << endl;
    }
    file.close();
}

void Menu::witdrawProducts()
{
    bool isAdded = true;
    string code, buffer;
    int addedAmount, amount;
    fstream file;
    file.open("naplo.txt", ios::app);
    while (isAdded)
    {
        cout << "Kérem adja meg a termék kódját:";
        cin >> code;
        cout << "Kérem adja meg a meg mennyivel csökkentené a raktárkészletet:";
        cin >> buffer;
        addedAmount = atoi(buffer.c_str());
        for (int i = 0; i < index_m; ++i)
        {
            if (storage_m[i]->code() == code)
            {

                amount = storage_m[i]->storageAmount() - addedAmount;
                if (amount < 0)
                {
                    cout << "Ekkora mennyiséget nem vehet ki a raktárból! Jelenlegi mennyiség:" << storage_m[i]->storageAmount() << endl;
                    file << "[witdrawProducts]->"
                         << "Ekkora mennyiséget nem vehet ki a raktárból! Jelenlegi mennyiség:" << storage_m[i]->storageAmount() << endl;
                }
                else
                {
                    file << "[witdrawProducts]->" << storage_m[i] << endl;
                    storage_m[i]->setStorageAmount(amount);
                }
            }
            cout << storage_m[i] << endl;
        }
        cout << "Következő termék? (i/n)" << endl;
        char c;
        cin >> c;
        isAdded = (c == 'i') ? true : false;
        cout << endl;
    }
    file.close();
}

void Menu::readNaplo(fstream &file)
{
    file.open("naplo.txt", ios::in);
    string x;
    while (file >> x)
    {
        cout << x << endl;
    }
    file.close();
}

bool Menu::checkNaplo(fstream &file)
{
    if (!file)
    {
        cout << "Napló nem létezik!" << endl;
        return false;
    }
    else
    {
        cout << "Napló elérhető!" << endl;
        return true;
    }
}

Menu::~Menu()
{
    for (int i = 0; i < index_m; ++i)
    {
        delete (storage_m[i]);
    }
}
