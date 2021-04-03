#include <vector>
#ifndef MY_UNITS
#define MY_UNITS
#include "My_Units.cpp"
#endif

#ifndef FACTORY
#define FACTORY
#include "Factory.cpp"
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
    cout << "BEFORE:\n";
    for (int i = 0; i < A.size(); ++i) {
        A[i].print_unit();
    }
    for (int i = 0; i < 14; ++i) {
        int i1 = rand() % A.size();
        int j1 = i1;
        while (j1 == i1) {
            j1 = rand() % A.size();
        }
        A[i1].attack(A[j1]);
    }
    cout << "\nAFTER:\n";
    for (int i = 0; i < A.size(); ++i) {
        A[i].print_unit();
    }
    cout << "\n--------------------------\n";
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

    cout << "res: " << res << "\n";
    for (int i = 0; i < A.size(); ++i) {
        A[i].print_unit();
    }
    cout << "\n--------------------------\n";
}

int main() {
    srand(time(0));
    test0_units();
    test_attack();
    test_unit_Fact();
}
