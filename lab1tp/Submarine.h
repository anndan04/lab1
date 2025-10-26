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
  
    Submarine();  
    Submarine(double l, double w, int c, double ut, double mus, const char* wp); 
    Submarine(const Submarine& other); 
    ~Submarine(); 

   
    Submarine& operator=(const Submarine& other);
    bool operator==(const Submarine& other) const;

    
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

    void Input() override;
    void Show() const override;
    void Edit() override;
    void Save(std::ofstream& out) const override;
    void Load(std::ifstream& in) override;
    Base* Clone() const override;
};

#endif
