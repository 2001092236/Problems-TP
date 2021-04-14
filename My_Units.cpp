#ifndef MY_UNITSH
#define MY_UNITSH
#include "My_Units.h"
#endif

Attacker::Attacker(int x, int y) : Unit(x, y, 10,\
                    5, Constants::UnitType::Attacker) {}

int Attacker::get_unit_resource() const {
    return 0;
}


Safer::Safer(int x, int y): Unit(x, y, 15,\
                2, Constants::UnitType::Safer) {}
int Safer::get_unit_resource() const {
    return 0;
}


Producer::Producer(int x, int y): \
        Unit(x, y, 6, 0,\
            Constants::UnitType::Producer), produce(2) {}
int Producer::get_unit_resource() const {
    return produce;
}