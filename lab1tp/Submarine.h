#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Base.h"
#include <iostream>
#include <cstring>

class Submarine : public Base {
private:
    double length;
    double width;
    int crew;
    double underwater_time;
    double max_underwater_speed;
    char weapon[100];

public:
    // --- Конструкторы и деструктор ---
    Submarine();  // без параметров
    Submarine(double l, double w, int c, double ut, double mus, const char* wp); // с параметрами
    Submarine(const Submarine& other); // копирования
    ~Submarine(); // деструктор

    // --- Операторы ---
    Submarine& operator=(const Submarine& other);
    bool operator==(const Submarine& other) const;

    // --- Методы доступа (get/set) ---
    double getLength() const;
    double getWidth() const;
    int getCrew() const;
    double getUnderwaterTime() const;
    double getMaxUnderwaterSpeed() const;
    const char* getWeapon() const;

    void setLength(double l);
    void setWidth(double w);
    void setCrew(int c);
    void setUnderwaterTime(double t);
    void setMaxUnderwaterSpeed(double s);
    void setWeapon(const char* w);

    // --- Методы от Base ---
    void Input() override;
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream& out) const override;
    void Load(std::ifstream& in) override;
    Base* Clone() const override;
};

#endif
