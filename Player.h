#ifndef FACTORY
#define FACTORY
#include "Factory.cpp"
#endif

#ifndef ARMY
#define ARMY
#include "Army.cpp"
#endif


#include <vector>
#include <string>

class Player {
    void print_army(std::string = "You") const;
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

    void print_player(std::string = "You") const;

    void step();
};
