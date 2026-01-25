#include <iostream>
#include "chef.h"
using namespace std;


chef::chef(string name) : chefName(name)
{
    cout << "chef " << chefName << " on valmis kokkaamaan" << endl;
}
chef::~chef()
{
    cout << "chef " << chefName << " destruktor" << endl;
}
int chef::makeSalad(int aines)
{
    cout << "cheffi" << chefName << "tekee" << 5/aines << "annosta" << endl;
    return 5/aines;
}
int chef::makeSoup(int aines)
{
    cout << "cheffi" << chefName << "tekee" << 3/aines << "annosta" << endl;
    return 3/aines;

}
