#ifndef BOAT_H
#define BOAT_H

#include "Base.h"
#include <iostream>
#include <cstring>

class Boat : public Base {
private:
    char purpose[50];       // назначение
    char hullMaterial[50];  // материал корпуса
    char performance[50];   // ходовые качества
    double speed;           // скорость
    int capacity;           // количество людей

public:
    Boat();
    Boat(const char* p, const char* m, const char* perf, double s, int cap);
    Boat(const Boat& other);
    Boat& operator=(const Boat& other);
    ~Boat();

    void Input() override;
    void Show() const override;
    void Edit() override;
    Base* Clone() const override;

    void Save(std::ofstream& out) const override;
    void Load(std::ifstream& in) override;
};

#endif

