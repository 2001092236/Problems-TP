#include <vector>
#ifndef PLAYER
#define PLAYER
#include "Player.cpp"
#endif

using namespace std;

void test0_units() {
    vector<Unit> A;
    A.push_back(Attacker(1, 2));
    A.push_back(Safer(2, 3));
    A.push_back(Producer(3, 7));
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i].get_unit_type() << " ";
    }
    cout << "\n--------------------------\n";
}

void test_attack() {
    vector<Unit> A;
    A.push_back(Attacker(1, 2));
    A.push_back(Safer(2, 3));
    A.push_back(Producer(3, 7));
    for (int i = 0; i < 14; ++i) {
        int i1 = rand() % A.size();
        int j1 = i1;
        while (j1 == i1) {
            j1 = rand() % A.size();
        }
        A[i1].attack(A[j1]);
        A[i1].step();
    }
}

void test_unit_Fact() {
    vector<Unit> A;
    int res = 10;
    AttackerFactory F;
    for (int i = 0; i < 3; ++i) {
        if (F.can_create(res)) {
            A.push_back(*F.create_unit(res));
        }
    }
}

void test_army() {
    Player p1, p2;
    p1.create_empty_army();
    p1.add_unit_to_army(Constants::Attacker, 0);
    p1.create_empty_army();
    p1.add_unit_to_army(Constants::Producer, 1);
    p1.step();
    p2.create_empty_army();
    p2.add_unit_to_army(Constants::Attacker, 0);
    p2.add_unit_to_army(Constants::Attacker, 0);
    p2.step();
    p1.attack(0, p2, 0);
}

int main() {
    srand(time(0));
    test0_units();
    test_attack();
    test_unit_Fact();
    test_army();
}