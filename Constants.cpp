#ifndef CONSTANTS
#define CONSTANTS

#include <string>

namespace Constants {
    enum UnitType {
        Attacker,
        Producer,
        Safer
    };


    enum Actions {
        No,
        Attack,
        Move
    };

    const int N_TYPES = 3;

    std::string UnitTypeStr[N_TYPES] = {"ATTACKER", "PRODUCER", "SAFER"};
}
#endif