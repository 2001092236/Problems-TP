#include <iostream>
#ifndef UNITH
#define UNITH
#include "Unit.h"
#endif


Unit::Unit(int x, int y, int health, int force, Constants::UnitType type): \
    x(x), y(y), health(health), force(force), type(type), alive(true), can_do(true) {}


void Unit::move(int dx, int dy) {
    if (!can_do) {
        throw ("You Already do something by this Unit!!!");
    }
    can_do = false;
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

void Unit::attack(Unit& other) {
    if (!alive)
        return;
    other.cause_damage(force);
    if (other.alive)
        cause_damage(other.force * 0.75);
}

void Unit::attack_in_army(Unit& other) {
    if (!can_do) {
        throw("You Already do something by this Unit!!!");
    }
    attack(other);
    can_do = false;
}

void Unit::print_unit() const {

    std::cout << "----- " << Constants::UnitTypeStr[get_unit_type()] << "   ";
    if (alive)
        std::cout << " LIVE ";
    else
        std::cout << " DEAD ";
    std::cout << " -----\n";

    std::cout << "---   Health: " << health << " Force: " << force << " ---\n";
    std::cout << "------------------------------\n";
}