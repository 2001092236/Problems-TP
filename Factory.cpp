#ifndef FACTORYH
#define FACTORYH
#include "Factory.h"
#endif

Unit* AttackerFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= Constants::Attacker_cost;
        t = new Attacker(x, y);
    }
    return t;
}

bool AttackerFactory::can_create(const int& resources) const {
    return resources >= Constants::Attacker_cost;
}


Unit* SaferFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= Constants::Safer_cost;
        t = new Safer(x, y);
    }
    return t;
}

bool SaferFactory::can_create(const int& resources) const {
    return resources >= Constants::Safer_cost;
}


Unit* ProducerFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= Constants::Producer_cost;
        t = new Producer(x, y);
    }
    return t;
}

bool ProducerFactory::can_create(const int& resources) const {
    return resources >= Constants::Producer_cost;
}