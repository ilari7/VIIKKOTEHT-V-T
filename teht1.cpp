#include <iostream>

using namespace std;
int game(int maxnum);

int main()
{
    int maxnum;
    cout << "ANNA MAKSIMINUMERO" << endl;
    cin >> maxnum;
    if (maxnum==0){
        return 0;
    }
    else if(maxnum < 1){
        cout << "NEGATIIVINEN NUMERO" << endl;
        return 0;
    }
    else{
    int x = game(maxnum);
    cout << "ARVAUSTEN MAARA" << x << endl;
    }
}
int game(int maxnum)

{
    int randomi = rand() % maxnum + 1;
    int numero = -1;
    int arvaukset = 0;


    while(numero != randomi){
        cout << "anna numero" << endl;
        cin >> numero;
        if (randomi == numero){
            cout << "oikea vastaus!" << endl;

        }
        else if(randomi < numero){
            cout << "arvaus liian suuri" << endl;
            arvaukset++;
        }
        else if(randomi > numero){
            cout << "arvaus liian pieni" << endl;
            arvaukset++;
        }
    }
    return arvaukset;

}
