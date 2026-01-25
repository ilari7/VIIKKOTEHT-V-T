#include <iostream>
#include "italycheff.h"
using namespace std;


italychef::italychef(string chefName) : chef(chefName), password("pizza") {
}
italychef::~italychef(){
    cout << "cheffi" << chefName << "lahtee himaa" << endl;
}

bool italychef::askSecret(string sala, int flour, int water){
    if (sala==password){
    cout << "cheffi " << chefName << " sai reseptin!" << endl;
        makePizza(flour,water);
    return true;
    }
    else {
        cout << "vaara salasana" << endl;
        return false;
    }
}
int italychef::makePizza(int flour, int water){
    int pizzat = 0;
    while (flour > 5 && water > 5){
        flour-=5;
        water-=5;
        pizzat++;
    }
    cout << "chef" << chefName << "tekee" << pizzat << "pizzaa" << endl;
    return pizzat;
}
