#ifndef PLAYER_CPP
#define PLAYER_CPP


#include "Player.h"

void Player::clear_army(Army* army) {
    army->clear_all_army();
}

Player::Player() {
    Fact[Constants::UnitType::Attacker] = new AttackerFactory();
    Fact[Constants::UnitType::Producer] = new ProducerFactory();
    Fact[Constants::UnitType::Safer] = new SaferFactory();
    resources = 10;
}

bool Player::add_unit_to_army(Constants::UnitType type, int num_army) {
    if (!Fact[type]->can_create(resources)) {
        return false;
    }
    ///add unit to concrete army
    armies[num_army]->add_unit(Fact[type]->create_unit(resources));
    return true;
}

void Player::create_empty_army() {
    armies.push_back(new Army());
}

bool Player::attack(int my_num, Player& other, int other_num) {
    if (my_num < 0 || my_num >= int(armies.size()) || other_num < 0\
                        || other_num >= int(other.armies.size()))
        return false;
    armies[my_num]->attack(*other.armies[other_num]);
    clear_army(armies[my_num]);
    clear_army(other.armies[other_num]);
    return true;
}

bool Player::move(int my_num, int dx, int dy) {
    if (my_num < 0 || my_num >= int(armies.size()))
        return false;
    armies[my_num]->move(dx, dy);
    return true;
}

void Player::merge_armies(int n1, int n2) {
    if (n1 < 0 || n1 >= armies.size() || n2 < 0 || n2 >= armies.size())
        throw "Bad numbers of armies";
    std::swap(armies[n2], armies.back());
    armies[n1]->merge(*armies[n2]);
    armies.pop_back();
}

void Player::step() {
    int res = 0;
    for (int j = 0; j < armies.size(); ++j) {
        res += armies[j]->step();
    }
    resources += res;
}
#endif
