#ifndef GAME_H
#define GAME_H
#include "Player.cpp"

using namespace std;


class Game {
public:
    vector<Player> players;
    Game();
    bool try_move(int);

    bool try_create(int);

    bool try_attack(int);

    bool try_merge(int);

    [[noreturn]] void start();
};
#endif
