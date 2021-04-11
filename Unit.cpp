#include <iostream>
#ifndef UNITH
#define UNITH
#include "Unit.h"
#endif

Unit::Unit(int x, int y, int health, int force, Constants::UnitType type): \
    x(x), y(y), health(health), force(force), type(type), \
        alive(true), last_action(Constants::Actions::NO) {}



void Unit::move(int dx, int dy) {
    if (last_action != Constants::Actions::NO) {
        throw ("You Already do something by this Unit!!!");
    }
    last_action = Constants::Actions::MOVE;
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
    last_action = Constants::Actions::NO;
    return 0;
}

void Unit::attack(Unit& other) {
    if (last_action != Constants::Actions::NO) {
        throw("You Already do something by this Unit!!!");
    }
    attack(other);
    last_action = Constants::Actions::ATTACK;
}

void Unit::print_unit(int number) const {
    if (number == -1)
        std::cout << "----- " << Constants::UnitTypeStr[get_unit_type()] << "   ";
    else
        std::cout << "----- #" << number << " " << Constants::UnitTypeStr[get_unit_type()] << "   ";

    if (alive)
        std::cout << " LIVE ";
    else
        std::cout << " DEAD ";
    std::cout << " -----\n";

    std::cout << "---   Health: " << health << " Force: " << force << " ---\n";
    std::cout << "------------------------------\n";
}