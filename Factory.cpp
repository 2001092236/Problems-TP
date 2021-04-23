#ifndef FACTORY_CPP
#define FACTORY_CPP
#include "Factory.h"

Unit* AttackerFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= 3;
        t = new Attacker(x, y);
    }
    return t;
}

bool AttackerFactory::can_create(const int& resources) const {
    return resources >= 3;
}



Unit* SaferFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= 5;
        t = new Safer(x, y);
    }
    return t;
}

bool SaferFactory::can_create(const int& resources) const {
    return resources >= 5;
}


Unit* ProducerFactory::create_unit(int& resources, int x, int y) const {
    Unit* t = nullptr;
    if (can_create(resources)) {
        resources -= 6;
        t = new Producer(x, y);
    }
    return t;
}

bool ProducerFactory::can_create(const int& resources) const {
    return resources >= 6;
}
#endif