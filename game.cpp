#include <iostream>
#include "game.h"

using namespace std;

int game(int maxnum);

int main()
{
    srand(time(NULL));
    int maxnum = 20;
    cout << "ohjelma kaynnistettu" << endl;
    Game peli(maxnum);
    peli.play();
    peli.printGameResult();
    return 0;
}
void Game::play()

{
    int numero = -1;



    while(numero != randomNumber){
        cout << "anna numero" << endl;
        cin >> numero;
        if (randomNumber == numero){
            cout << "oikea vastaus!" << endl;

        }
        else if(randomNumber < numero){
            cout << "arvaus liian suuri" << endl;
            arvaukset++;
        }
        else if(randomNumber > numero){
            cout << "arvaus liian pieni" << endl;
            arvaukset++;
        }
    }

}
void Game::printGameResult() {
    cout << "oikea numero oli: " << randomNumber << endl;
    cout << "arvauksien maara: " << arvaukset << endl;
}
Game::~Game(){
    cout << "peli TUHTOTU" << endl;
}
Game::Game(int maxNum) {
    maxNumber=maxNum;
    arvaukset = 0;
    randomNumber = (rand() % maxNumber) + 1;
}

