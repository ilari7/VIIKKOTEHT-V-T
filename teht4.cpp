#include <iostream>
#include <string>


using namespace std;
class Pankkitili{
protected:
    string omistaja;
    double saldo = 0;
public:
    Pankkitili(string);
    double getBalance();
    bool deposit(double);
    bool withdraw(double);

};
class Luottotili : Pankkitili{
protected:
    double luottoRaja = 0;

public:
    Luottotili(string, double);
    bool deposit(double);
    bool withdraw(double);
};
class Asiakas{
private:
    string nimi;
    Pankkitili(kayttotili);
    Luottotili(luottotili);
public:
    Asiakas(string, double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
};

int main(){
    cout << "jou" << endl;
}
