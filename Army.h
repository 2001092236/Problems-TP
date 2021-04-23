#ifndef MY_UNITS
#define MY_UNITS
#include "My_Units.cpp"
#endif
#include <vector>

class Army {
    void remove_unit(std::vector<Unit*>&, int);
    void remove_unit(Constants::UnitType, int);

    void clear_army(std::vector<Unit*>&);
    void clear_army(Constants::UnitType);
    Constants::Actions last_action;
    std::vector<Unit*> units[Constants::N_TYPES];
public:

    void clear_all_army();

    Army();

    Army(const std::vector<Unit*>&);

    void add_unit(Unit*);

    int step();

    void print_army(int) const;

    void attack(Army&);

    void move(int, int);
};
