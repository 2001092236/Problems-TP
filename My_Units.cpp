#ifndef MY_UNITSH
#define MY_UNITSH
#include "My_Units.h"
#endif

Attacker::Attacker(int x, int y) : Unit(x, y, Constants::Attacker_health,\
                    Constants::Attacker_force, Constants::UnitType::Attacker) {}

int Attacker::get_unit_resource() const {
    return 0;
}


Safer::Safer(int x, int y): Unit(x, y, Constants::Safer_health,\
                Constants::Safer_force, Constants::UnitType::Safer) {}
int Safer::get_unit_resource() const {
    return 0;
}


Producer::Producer(int x, int y): \
        Unit(x, y, Constants::Producer_health, Constants::Producer_force,\
            Constants::UnitType::Producer), produce(Constants::Producer_produce) {}
int Producer::get_unit_resource() const {
    return produce;
}