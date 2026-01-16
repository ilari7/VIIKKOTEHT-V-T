#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int maxNum);
    void play();
    ~Game();
    void printGameResult();

private:
    int maxNumber;
    int randomNumber;
    int arvaukset;


};

#endif // GAME_H
