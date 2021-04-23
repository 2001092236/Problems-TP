#ifndef PLAYER_H
#define PLAYER_H
#include "Factory.cpp"
#include "Army.cpp"
#include <vector>
#include <string>

class Player {
public:
    int resources;
    std::vector<Army*> armies;
    UnitFactory* Fact[Constants::N_TYPES];


    Player();

    void create_empty_army();

    void clear_army(Army*);

    bool add_unit_to_army(Constants::UnitType, int = 0);

    bool attack(int, Player&, int);

    bool move(int, int = 0, int = 0);

    void merge_armies(int, int);

    void step();
};
#endif