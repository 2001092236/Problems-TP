#include <string>

namespace Constants {
    enum UnitType {
        Attacker,
        Producer,
        Safer
    };

    enum ArmyAction {
        NO,
        ATTACK,
        MOVE
    };

    const int N_TYPES = 3;

    std::string UnitTypeStr[N_TYPES] = {"ATTACKER", "PRODUCER", "SAFER"};

    const double contr_attack_coeff = 0.75;


    const int Attacker_health = 10;
    const int Attacker_force = 5;
    const int Attacker_cost = 3;

    const int Producer_health = 6;
    const int Producer_force = 0;
    const int Producer_cost = 6;
    const int Producer_produce = 2;

    const int Safer_health = 15;
    const int Safer_force = 2;
    const int Safer_cost = 5;
}