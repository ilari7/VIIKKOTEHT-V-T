#include <iostream>
#include <string>


using namespace std;
class Pankkitili
{
protected:
    string omistaja;
    double saldo = 0;
public:
    Pankkitili(string nimi)
    {
        omistaja = nimi;
        cout << "pankkitili luotu omistajalle:" << omistaja << endl;
        }
    double getBalance()
        {
        return saldo;
    }
    virtual bool deposit(double maara)
    {
        if(maara>0)
        {
            saldo += maara;
            cout << "depotettu tilille" << maara << endl;
            return true;
        }
        else
        {
            cout << "fail" << endl;
            return false;
        }
    }
    virtual bool withdraw(double maara)
    {
        if (maara>0 && maara <= saldo)
        {
            saldo -= maara;
            cout << "nosterttu" << maara << "tililta" << endl;
            return true;
        }
        else{
            cout << "fail" << endl;
            return false;
        }

    }

};
class Luottotili : public Pankkitili
{
protected:
    double luottoRaja = 0;

public:
    Luottotili(string nimi, double raja) : Pankkitili(nimi)
    {

        luottoRaja=raja;
        cout << "luottotili luotu" << endl;

    }
    bool deposit(double maara) override
    {
        if(maara>0)
        {
            saldo += maara;
            cout << "depotettu luottotilille" << maara << endl;
            return true;
        }
        else
        {
            cout << "nosto epaonnistui" << endl;
            return false;
        }
    }
        bool withdraw(double maara) override
        {
        if (maara<=(saldo+luottoRaja) && maara > 0)
            {
            saldo -= maara;
            cout << "nosterttu" << maara << "luottotililta" << endl;
            return true;
        }
        else
        {
            cout << "fail" << endl;
            return false;


        }
        }

};
class Asiakas
{
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
public:
    Asiakas(string jyrki, double luottoRaja): nimi(jyrki), kayttotili(jyrki), luottotili(jyrki, luottoRaja){
        cout << "asiakas luotu" << endl;
    }
    string getNimi()
    {
        return nimi;
    }
    void showSaldo()
    {
        cout << "kayttotilin saldo: " << kayttotili.getBalance() << endl;
        cout << "kayttotilin saldo: " << luottotili.getBalance() << endl;
    }
    bool talletus(double maara)
    {
        return kayttotili.deposit(maara);
    }
    bool nosto(double maara)
    {
        return kayttotili.withdraw(maara);
    }
    bool luotonMaksu(double maara)
    {
        return luottotili.deposit(maara);
    }
    bool luotonNosto(double maara)
    {
        return luottotili.withdraw(maara);
    }
    bool tiliSiirto(double maara, Asiakas &eri)
    {
        if (kayttotili.withdraw(maara))
        {
            return eri.talletus(maara);
        }
        return false;
    }

};

int main(){
    Asiakas asiakas1("dude", 9200);

    asiakas1.talletus(250);
    asiakas1.luotonNosto(150);
    asiakas1.showSaldo();

    Asiakas asiakas2("nissinen", 1000);

    asiakas2.showSaldo();
    asiakas1.tiliSiirto(50, asiakas2);
    asiakas1.showSaldo();
    asiakas2.showSaldo();



}
