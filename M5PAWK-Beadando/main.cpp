#include <iostream>

using namespace std;

class Termek{
private:
    string nev;
    string gyarto;
    float mennyiseg;
public:
    Termek(string nev, string gyarto, float mennyiseg){
        this.nev = nev;
        this.gyarto = gyarto;
        this.mennyiseg = messnyiseg;
    }
};

class DarabAru:Termek{
private:
    string vonalkod;
    float ar;
public:
    DarabAru(string vonalkod, float ar){
        this.vonalkod = vonalkod;
        this.ar = ar;
    }
};

class Ledig: Termek{
private:
    string vonalkod;
    float ar;
    float sulyegyseg; // A súlyegység grammban értendõ
public:
    Ledig(string vonalkod, float ar, float sulyegyseg){
        this.vonalkod = vonalkod;
        this.ar = ar;
        this.sulyegyseg = sulyegyseg;
    }
    float egysegar(){
        return
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
