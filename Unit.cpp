#ifndef UNIT_CPP
#define UNIT_CPP

#include <iostream>
#include "Unit.h"

Unit::Unit(int x, int y, int health, int force, Constants::UnitType type): \
    x(x), y(y), health(health), force(force), type(type), \
        alive(true), last_action(Constants::Actions::No) {}



void Unit::move(int dx, int dy) {
    if (last_action != Constants::Actions::No) {
        throw ("You Already do something by this Unit!!!");
    }
    last_action = Constants::Actions::Move;
    x += dx;
    y += dy;
}

Constants::UnitType Unit::get_unit_type() const {
    return type;
}

int Unit::get_unit_resource() const {
    return 0;
}

void Unit::cause_damage(int dmg) {
    if (!alive)
        return;
    health -= dmg;
    if (health <= 0) {
        alive = false;
        health = 0;
    }
}

int Unit::step() {
    last_action = Constants::Actions::No;
    return 0;
}


void Unit::attack(Unit& other) {
    if (last_action != Constants::Actions::No) {
        throw("You Already do something by this Unit!!!");
    }
    other.cause_damage(force);
    if (other.alive)
        cause_damage(other.force * 0.75);
    last_action = Constants::Actions::Attack;
}
#endif