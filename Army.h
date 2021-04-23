#ifndef ARMYHf
#define ARMYHf

#include <vector>
#include "My_Units.cpp"

class Army {
    void remove_unit(std::vector<Unit*>&, int);
    void remove_unit(Constants::UnitType, int);

    void clear_army(std::vector<Unit*>&);
    void clear_army(Constants::UnitType);
    Constants::Actions last_action;
public:
    std::vector<Unit*> units[Constants::N_TYPES];

    void clear_all_army();

    Army();

    Army(const std::vector<Unit*>&);

    void add_unit(Unit*);

    int step();

    void attack(Army&);

    void merge(Army&);

    int get_number(Constants::UnitType) const;

    void move(int, int);
};
#endif
