#ifndef ARMYH
#define ARMYH
#include "Army.h"
#endif


void Army::remove_unit(std::vector<Unit*>& v, int pos) {
    std::swap(v[pos], v.back());
    v.pop_back();
}

void Army::remove_unit(Constants::UnitType typeArmy, int pos) {
    remove_unit(units[typeArmy], pos);
}

void Army::clear_army(std::vector<Unit*>& v) {
    int sz = v.size();
    for (int i = sz - 1; i >= 0; --i) {
        if (!v[i]->alive)
            remove_unit(v, i);
    }
}

void Army::clear_army(Constants::UnitType typeArmy) {
    clear_army(units[typeArmy]);
}

void Army::clear_all_army() {
    for (int i = 0; i < Constants::N_TYPES; ++i) {
        clear_army(static_cast<Constants::UnitType>(i));
    }
}

Army::Army(): last_action(Constants::Actions::No) {}

Army::Army(const std::vector<Unit*>& v): Army() {
    for (int i = 0; i < int(v.size()); ++i) {
        units[v[i]->get_unit_type()].push_back(v[i]);
    }
}

void Army::add_unit(Unit* u) {
    units[u->get_unit_type()].push_back(u);
}

int Army::step() {
    int res = 0;
    for (int i = 0; i < Constants::N_TYPES; ++i) {
        for (int j = 0; j < units[i].size(); ++j) {
            res += units[i][j]->step();
        }
    }
    Constants::Actions lst = last_action;
    last_action = Constants::Actions::No;
    if (lst == Constants::Actions::Attack)
        return 0;
    return res;
}

void Army::print_army(int number) const {
    std::cout << "@@@@@@@@@@@@ ARMY#" << number << " @@@@@@@@@@@\n";
    for (int i = 0; i < Constants::N_TYPES; ++i) {
        for (int j = 0; j < units[i].size(); ++j) {
            units[i][j]->print_unit();
        }
    }
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

void Army::attack(Army& other) {
    if (last_action!= Constants::Actions::No) {
        throw("You Already do something by this Army!!!");
    }
    last_action = Constants::Actions::Attack;
    std::vector<Unit*>& attackers = units[Constants::UnitType::Attacker];
    std::vector<Unit*>& safers = units[Constants::UnitType::Safer];
    std::vector<Unit*>& producers = units[Constants::UnitType::Producer];

    std::vector<Unit*>& oattackers = other.units[Constants::UnitType::Attacker];
    std::vector<Unit*>& osafers = other.units[Constants::UnitType::Safer];
    std::vector<Unit*>& oproducers = other.units[Constants::UnitType::Producer];

    int i = 0;
    ///Attackers -> other.Safers
    for (; i < int(attackers.size()); ++i) {
        if (osafers.size() == 0)
            break;
        int id = rand() % osafers.size();
        attackers[i]->attack(*osafers[id]);
        if (!osafers[id]->alive)
            remove_unit(osafers, id);
    }

    ///remain Attackers -> other.Attackers | other.Producers
    for (; i < int(attackers.size()); ++i) {
        int remain = oattackers.size() + oproducers.size();
        if (remain == 0)
            break;
        int id = rand() % remain;

        if (id < int(oattackers.size())) {
            attackers[i]->attack(*oattackers[id]);
            if (!oattackers[id]->alive)
                remove_unit(oattackers, id);
        } else {
            id -= oattackers.size();
            attackers[i]->attack(*oproducers[id]);
            if (!oproducers[id]->alive)
                remove_unit(oproducers, id);
        }
    }

    ///END Attackers attack
    clear_army(attackers);

    ///Safer -> other.Safers
    i = 0;
    for (; i < int(safers.size()); ++i) {
        if (osafers.size() == 0)
            break;
        int id = rand() % osafers.size();
        safers[i]->attack(*osafers[id]);
        if (!osafers[id]->alive)
            remove_unit(osafers, id);
    }



    ///remain Safers -> other.Attackers | other.Producers
    for (; i < int(safers.size()); ++i) {
        int remain = oattackers.size() + oproducers.size();
        if (remain == 0)
            break;
        int id = rand() % remain;

        if (id < int(oattackers.size())) {
            safers[i]->attack(*oattackers[id]);
            if (!oattackers[id]->alive)
                remove_unit(oattackers, id);
        } else {
            id -= oattackers.size();
            safers[i]->attack(*oproducers[id]);
            if (!oproducers[id]->alive)
                remove_unit(oproducers, id);
        }
    }

    ///END Safers attack
    clear_army(safers);
}

void Army::move(int dx, int dy) {
    if (last_action!= Constants::Actions::No) {
        throw("You Already do something by this Army!!!");
    }

    last_action = Constants::Actions::Move;

    for (int i = 0; i < Constants::N_TYPES; ++i) {
        for (int j = 0; j < int(units[i].size()); ++j) {
            units[i][j]->move(dx, dy);
        }
    }
}
