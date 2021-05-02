#ifndef MY_UNITS_H
#define MY_UNITS_H

#include "Unit.cpp"

class Attacker: public Unit {
public:
    Attacker(int = 0, int = 0);
    int get_unit_resource() const override;

};

class Safer: public Unit {
public:
    Safer(int = 0, int = 0);
    int get_unit_resource() const override;
};

class Producer: public Unit {
public:
    int produce;
    Producer(int = 0, int = 0);
    int get_unit_resource() const override;
    int step() override;
};
#endif