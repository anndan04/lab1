#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Base.h"
#include <iostream>

class Sailboat : public Base {
private:
    char type[50];
    char name[50];
    bool isMilitary;
    double hullLength;
    double speed;
    int crew;

public:
    Sailboat();
    Sailboat(const char* t, const char* n, bool m, double hl, double s, int c);
    Sailboat(const Sailboat& other);
    Sailboat& operator=(const Sailboat& other);
    ~Sailboat();


    const char* getType() const;
    const char* getName() const;
    bool getIsMilitary() const;
    double getHullLength() const;
    double getSpeed() const;
    int getCrew() const;

    void setType(const char* t);
    void setName(const char* n);
    void setIsMilitary(bool m);
    void setHullLength(double hl);
    void setSpeed(double s);
    void setCrew(int c);


    void Input() override;
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream& out) const override;
    void Load(std::ifstream& in) override;
    Base* Clone() const override;
};

#endif
