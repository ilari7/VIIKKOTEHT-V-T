#include <iostream>
#include "chef.h"
#include "italycheff.h"

using namespace std;

int main(){
    chef chef1("jake");
    chef1.makeSalad(5);
    chef1.makeSoup(3);

    italychef chef2("mario patonki");
    chef2.makeSalad(5);
    chef2.askSecret("pizza", 20, 20);
    chef2.askSecret("jyrki",20 ,20);
}
