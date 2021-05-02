#ifndef GAME_CPP
#define GAME_CPP
#include "Game.h"

Game::Game() {
    players.resize(2);
    players[0] = Player();
    players[1] = Player();
}

int get_num() {
    string s;
    cin >> s;
    if (s.size() == 0)
        throw "BAD INPUT";
    int x = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] > '9' || s[i] < '0')
            throw "BAD INPUT";
        x *= 10;
        x += s[i] - '0';
    }
    return x;
}

int get_z() {
    string s;
    cin >> s;
    if (s.size() == 0)
        throw "BAD INPUT";
    int zn = 1;
    if (s[0] == '-') {
        s = s.substr(1, s.size() - 1);
        zn = -1;
    }
    int x = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] > '9' || s[i] < '0')
            throw "BAD INPUT";
        x *= 10;
        x += s[i] - '0';
    }
    return x * zn;
}

bool Game::try_move(int h) {
    try {
        cout << "Enter number of your army, dx and dy: \n";
        int num = get_num();
        int dx = get_z();
        int dy = get_z();
        if (players[h].move(num, dx, dy)) {
            std::cout << "OK\n";
            ///step = true;
            return true;
        }
    } catch (...) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Wrong input form\n";
    return false;
}

bool Game::try_create(int h) {
    cout << "Enter Unit type: ATTACKER(3), SAFER(5), PRODUCER(6)\n";
    string s;
    cin >> s;
    cout << "Enter number of your army, which receive this unit:\n";
    int number;
    try {
        number = get_num();
    } catch (...) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input form\n";
        return false;
    }
    if (number < 0 || number >= players[h].armies.size()) {
        std::cout << "Wrong input form\n";
        return false;
    }
    if (s == "ATTACKER") {
        if (players[h].add_unit_to_army(Constants::UnitType::Attacker, number)) {
            cout << "OK\n";
            return true;
        } else {
            std::cout << "Wrong input form\n";
            return false;
        }
    }
    if (s == "SAFER") {
        if (players[h].add_unit_to_army(Constants::UnitType::Safer, number)) {
            cout << "OK\n";
            return true;
        } else {
            std::cout << "Wrong input form\n";
            return false;
        }
    }
    if (s == "PRODUCER") {
        if (players[h].add_unit_to_army(Constants::UnitType::Producer, number)) {
            cout << "OK\n";
            return true;
        } else {
            std::cout << "Wrong input form\n";
            return false;
        }
    }
    return false;
}

bool Game::try_attack(int h) {
    cout << "Enter number of your army and number of enemy's army: \n";
    int n1, n2;

    try {
        n1 = get_num();
        n2 = get_num();
    } catch (...) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input form\n";
        return false;
    }

    if (players[h].attack(n1, players[1 - h], n2)) {
        std::cout << "OK\n";
        return true;
    } else {
        std::cout << "Wrong input form\n";
        return false;
    }
}

bool Game::try_merge(int h) {
    cout << "Enter 2 numbers of yours armies: \n";
    int n1, n2;

    try {
        n1 = get_num();
        n2 = get_num();
    } catch (...) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input form\n";
        return false;
    }
    if (n1 > n2)
        std::swap(n1, n2);
    if (max(n1, n2) >= players[h].armies.size()) {
        std::cout << "Wrong input form\n";
        return false;
    }
    players[h].armies[n1]->merge(*players[h].armies[n2]);
    std::swap(players[h].armies[n2], players[h].armies.back());
    players[h].armies.pop_back();
    ///throw "Don't implemented merge armies";
    return true;
}

/**

 CREATE_ARMY
 CREATE
 ATTACKER
 1

 CREATE_ARMY
 CREATE
 SAFER
 0

 CREATE_ARMY
 CREATE_ARMY
 MERGE_ARMY
 1 2
 */

void print_unit(const Unit& u, int number) {
    if (number == -1)
        std::cout << "----- " << Constants::UnitTypeStr[u.get_unit_type()] << "   ";
    else
        std::cout << "----- #" << number << " " << Constants::UnitTypeStr[u.get_unit_type()] << "   ";

    if (u.alive)
        std::cout << " LIVE ";
    else
        std::cout << " DEAD ";
    std::cout << " -----\n";

    std::cout << "---   Health: " << u.health << " Force: " << u.force << " ---\n";
    std::cout << "------------------------------\n";
}

void print_army(const Player& p, int num_army) {
    std::cout << "@@@@@@@@@@@@ " << num_army << " @@@@@@@@@@@\n";
    int cnt = 0;
    for (int k = 0; k < Constants::N_TYPES; ++k) {
        for (int i = 0; i < p.armies[num_army]->units[k].size(); ++i) {
            print_unit(*(p.armies[num_army]->units[k][i]), ++cnt);
        }
    }
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

void print_player(const Player& p, std::string str) {
    std::cout << str << ":\n";
    std::cout << "resources: " << p.resources << "\n";
    std::cout << "Armies: \n";
    for (size_t i = 0; i < p.armies.size(); ++i) {
        print_army(p, i);
    }
}

[[noreturn]] void Game::start() {
    cout << "The Game is start!!!\n";
    int h = -1;
    while (true) {
        ++h;
        h %= players.size();
        cout << "Turn Player# " << h + 1 << "\n";
        print_player(players[h], "P");
        cout << "\n";
        cout << "You can move some army, create army, attack enemy's army, create armies, merge armies\n";
        bool step = false;

        while (!step) {
            cout << "Enter MOVE for move, CREATE for create, ATTACK to attack, CREATE_ARMY for create new empty army, MERGE_ARMY to merge TWO armies together, NO for skip\n";
            string s;
            cin >> s;
            if (s == "MOVE") { /// NOT DEBUG
                step = try_move(h);
                continue;
            }
            else if (s == "CREATE") {
                step = try_create(h);
                continue;
            }
            else if (s == "ATTACK") { ///DO WRONG: When i write ATTACK r: do contrattack???
                step = try_attack(h);
                continue;
            }
            else if (s == "CREATE_ARMY") {
                players[h].armies.push_back(new Army());
                cout << "Army# " << players[h].armies.size() - 1 << " was created!\n";
                continue;
            } else if (s == "MERGE_ARMY") {
                try_merge(h);
                continue;
            }
            else if (s == "NO") {
                step = true;
                continue;
            }
        }
        players[h].step();
    }
}

#endif