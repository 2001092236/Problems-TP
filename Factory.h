#ifndef MY_UNITS
#define MY_UNITS
#include "My_Units.cpp"
#endif

class UnitFactory {
public:
    virtual Unit* create_unit(int&, int = 0, int = 0) const = 0;
    virtual bool can_create(const int&) const = 0;
};

class AttackerFactory: public UnitFactory {
public:

    Unit* create_unit(int&, int = 0, int = 0) const override;
    bool can_create(const int&) const override;
};

class SaferFactory: public UnitFactory {
public:

    Unit* create_unit(int&, int = 0, int = 0) const override;
    bool can_create(const int&) const override;
};

class ProducerFactory: public UnitFactory {
public:

    Unit* create_unit(int&, int = 0, int = 0) const override;
    bool can_create(const int& resources) const override;
};