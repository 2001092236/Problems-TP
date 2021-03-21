#ifndef MY_UNITS
#define MY_UNITS
#include "My_Units.cpp"
#endif

class UnitFactory {
public:
    virtual Unit* create_unit(int& resources, int x = 0, int y = 0) const = 0;
    virtual bool can_create(const int&resources) const = 0;
};

class AttackerFactory: public UnitFactory {
public:
    Unit* create_unit(int& resources, int x = 0, int y = 0) const override {
        Unit* t = nullptr;
        if (can_create(resources)) {
            resources -= Constants::Attacker_cost;
            t = new Attacker(x, y);
        }
        return t;
    }

    bool can_create(const int& resources) const override {
        return resources >= Constants::Attacker_cost;
    }
};

class SaferFactory: public UnitFactory {
public:
    Unit* create_unit(int& resources, int x = 0, int y = 0) const override {
        Unit* t = nullptr;
        if (can_create(resources)) {
            resources -= Constants::Safer_cost;
            t = new Safer(x, y);
        }
        return t;
    }

    bool can_create(const int& resources) const override {
        return resources >= Constants::Safer_cost;
    }
};

class ProducerFactory: public UnitFactory {
public:
    Unit* create_unit(int& resources, int x = 0, int y = 0) const override {
        Unit* t = nullptr;
        if (can_create(resources)) {
            resources -= Constants::Producer_cost;
            t = new Producer(x, y);
        }
        return t;
    }

    bool can_create(const int& resources) const override {
        return resources >= Constants::Producer_cost;
    }
};