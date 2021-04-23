#ifndef FACTORY_H
#define FACTORY_H
#include "My_Units.cpp"

class UnitFactory {
public:
    virtual Unit* create_unit(int& resources, int = 0, int = 0) const = 0;
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

    bool can_create(const int&) const override;
};
#endif
