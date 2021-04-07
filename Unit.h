#ifndef CONSTANTS
#define CONSTANTS
#include "Constants.cpp"
#endif

class Unit {
protected:
    Unit(int, int, int, int, Constants::UnitType);
    int x, y;
    int health;
    int force;
    Constants::UnitType type;
public:
    bool alive;
    bool can_do;

    virtual void move(int, int);

    Constants::UnitType get_unit_type() const;

    virtual int get_unit_resource() const;

    virtual void cause_damage(int);

    virtual void attack(Unit&);

    virtual void attack_in_army(Unit&);

    virtual void print_unit() const;
};