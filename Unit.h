#ifndef UNIT_H
#define UNIT_H
#include "Constants.cpp"
#include <iostream>

class Unit {
protected:
    Unit(int, int, int, int, Constants::UnitType);

    int x, y;
    Constants::UnitType type;
    Constants::Actions last_action;

public:
    bool alive;

    virtual void move(int, int);

    Constants::UnitType get_unit_type() const;

    virtual int get_unit_resource() const;

    virtual void cause_damage(int);

    virtual int step();

    virtual void attack(Unit&);

    int force;
    int health;
};
#endif