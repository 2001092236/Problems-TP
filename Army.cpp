#ifndef MY_UNITS
#define MY_UNITS
#include "My_Units.cpp"
#endif

class Army {
    void remove_unit(std::vector<Unit*>& v, int pos) {
        std::swap(v[pos], v.back());
        v.pop_back();
    }

    void clean_army(std::vector<Unit*>& v) {
        int sz = v.size();
        for (int i = sz - 1; i >= 0; --i) {
            if (!v[i]->alive)
                remove_unit(v, i);
        }
    }

    Constants::ArmyAction last_action;
    std::vector<Unit*> units[Constants::N_TYPES];

public:

    Army(): last_action(Constants::ArmyAction::NO) {}

    Army(const std::vector<Unit*>& v): Army() {
        for (int i = 0; i < int(v.size()); ++i) {
            units[v[i]->get_unit_type()].push_back(v[i]);
        }
    }

    int step() {
        int res = 0;
        for (int i = 0; i < Constants::N_TYPES; ++i) {
            for (int j = 0; j < units[i].size(); ++j) {
                units[i][j]->can_do = true;
                res += units[i][j]->get_unit_resource(); ///!!!
            }
        }
        Constants::ArmyAction lst = last_action;
        last_action = Constants::ArmyAction::NO;
        if (lst == Constants::ArmyAction::ATTACK)
            return 0;
        return res;
    }

    void print_army() const {
        std::cout << "@@@@@@@@@@@@ ARMY @@@@@@@@@@@\n";
        for (int i = 0; i < Constants::N_TYPES; ++i) {
            for (int j = 0; j < units[i].size(); ++j) {
                units[i][j]->print_unit();
            }
        }
        std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    }

    void attack(Army& other) {
        last_action = Constants::ArmyAction::ATTACK;
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
            attackers[i]->attack_in_army(*osafers[id]);
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
                attackers[i]->attack_in_army(*oattackers[id]);
                if (!oattackers[id]->alive)
                    remove_unit(oattackers, id);
            } else {
                id -= oattackers.size();
                attackers[i]->attack_in_army(*oproducers[id]);
                if (!oproducers[id]->alive)
                    remove_unit(oproducers, id);
            }
        }

        ///END Attackers attack
        clean_army(attackers);

        ///Safer -> other.Safers
        i = 0;
        for (; i < int(safers.size()); ++i) {
            if (osafers.size() == 0)
                break;
            int id = rand() % osafers.size();
            safers[i]->attack_in_army(*osafers[id]);
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
                safers[i]->attack_in_army(*oattackers[id]);
                if (!oattackers[id]->alive)
                    remove_unit(oattackers, id);
            } else {
                id -= oattackers.size();
                safers[i]->attack_in_army(*oproducers[id]);
                if (!oproducers[id]->alive)
                    remove_unit(oproducers, id);
            }
        }

        ///END Safers attack
        clean_army(safers);
    }

    void move(int dx, int dy) {
        last_action = Constants::ArmyAction::ATTACK;
        if (last_action!= Constants::ArmyAction::NO) {
            throw("You Already do something by this Army!!!");
        }

        last_action = Constants::ArmyAction::MOVE;

        for (int i = 0; i < Constants::N_TYPES; ++i) {
            for (int j = 0; j < int(units[i].size()); ++j) {
                units[i][j]->move(dx, dy);
            }
        }
    }
};
