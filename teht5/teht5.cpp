#include <iostream>
#include <string>

using namespace std;

class Seuraaja
{
private:
    string nimi;
public:
    Seuraaja* next = nullptr;
    Seuraaja(string numer) : nimi(numer)
    {

    }
    void paivitys(string strin)
    {
    cout << nimi << " sai viestin" << strin << endl;
    }
    string getNimi()
    {
        return nimi;
    }

};


class Notifikaattori
{
private:
    Seuraaja* seuraaja=nullptr;
public:
    Notifikaattori()
    {
         cout << "luodaan notifikaattori" << endl;
    }
    void lisaa(Seuraaja* strin)
    {
    if(seuraaja != nullptr)
    {
    strin->next = seuraaja;
    }
    seuraaja=strin;
}
    void poista(Seuraaja* strin)
{
    if(seuraaja == strin)
    {
    seuraaja = seuraaja->next;
    return;
    }
    Seuraaja* current = seuraaja;
    while(current != nullptr && current->next != strin)
    {
    current = current->next;
    }
    if(current != nullptr)
    {
    current->next = strin->next;
    }
}



    void tulosta()
{
        Seuraaja* current = seuraaja;
        while(current != nullptr)
        {
        cout << current->getNimi() << endl;
        current = current->next;
        }
    }

    void postita(string strin)
    {
        Seuraaja* current = seuraaja;
        while(current != nullptr)
        {
        current->paivitys(strin);
        current = current->next;
        }
    }
};

int main()
{
    Notifikaattori n;
    cout << "luodaan seuraajat: " << endl;
    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();
    cout << "postataan eka viesti " << endl;
    n.postita(" tama on viesti 1");

    cout << " poistetaan B" << endl;
    n.poista(&b);
    cout << " jaljellat olevat: " << endl;
    n.tulosta();
    cout << " postataan toinenen viesti " << endl;
    n.postita(" tama on viesti 2");


    return 0;
}
