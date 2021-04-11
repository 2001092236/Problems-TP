#ifndef PLAYERH
#define PLAYERH
#include "Player.h"
#endif


void Player_with_army::clean_army(Army* army) {
    army->clean_all_army();
}

Player_with_army::Player_with_army() {
    Fact[0] = new AttackerFactory();
    Fact[1] = new ProducerFactory();
    Fact[2] = new SaferFactory();
    resources = Constants::PlayerInitResources;
}

bool Player_with_army::add_unit_to_army(Constants::UnitType type, int num_army) {
    if (!Fact[type]->can_create(resources)) {
        return false;
    }
    ///add unit to concrete army
    armies[num_army]->add_unit(Fact[type]->create_unit(resources));
    return true;
}

void Player_with_army::create_empty_army() {
    armies.push_back(new Army());
}

bool Player_with_army::attack(int my_num, Player_with_army& other, int other_num) {
    if (my_num < 0 || my_num >= int(armies.size()) || other_num < 0\
                        || other_num >= int(other.armies.size()))
        return false;
    armies[my_num]->attack(*other.armies[other_num]);
    clean_army(armies[my_num]);
    clean_army(other.armies[other_num]);
    return true;
}

bool Player_with_army::move(int my_num, int dx, int dy) {
    if (my_num < 0 || my_num >= int(armies.size()))
        return false;
    armies[my_num]->move(dx, dy);
    return true;
}

void Player_with_army::print_army(std::string str) const {
    std::cout << "@@@@@@@@@@@@ " << str << " @@@@@@@@@@@\n";
    for (int j = 0; j < armies.size(); ++j) {
        armies[j]->print_army(j);
    }
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

void Player_with_army::print_player(std::string str) const {
    std::cout << str << ":\n";
    std::cout << "resources: " << resources << "\n";
    std::cout << "Armies: \n";
    print_army(str);
}

void Player_with_army::step() {
    int res = 0;
    for (int j = 0; j < armies.size(); ++j) {
        res += armies[j]->step();
    }
    resources += res;
}
