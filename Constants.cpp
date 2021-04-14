#include <string>

namespace Constants {
    enum UnitType {
        Attacker,
        Producer,
        Safer
    };

    enum ArmyAction {
        No,
        Attack,
        Move
    };

    const int N_TYPES = 3;

    std::string UnitTypeStr[N_TYPES] = {"ATTACKER", "PRODUCER", "SAFER"};
}