#ifndef UNIT
#define UNIT
#include "Unit.cpp"
#endif


class Attacker: public Unit {
public:
    Attacker(int x = 0, int y = 0): Unit(x, y, Constants::Attacker_health, Constants::Attacker_force, Constants::UnitType::Attacker) {}
    int get_unit_resource() const override {
        return 0;
    }
};

class Safer: public Unit {
public:
    Safer(int x = 0, int y = 0): Unit(x, y, Constants::Safer_health, Constants::Safer_force, Constants::UnitType::Safer) {}
    int get_unit_resource() const override {
        return 0;
    }
};

class Producer: public Unit {
public:
    int produce;
    Producer(int x = 0, int y = 0): \
        Unit(x, y, Constants::Producer_health, Constants::Producer_force, Constants::UnitType::Producer),\
        produce(Constants::Producer_produce) {}
    int get_unit_resource() const override {
        return produce;
    }
};