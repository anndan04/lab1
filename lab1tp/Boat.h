#ifndef BOAT_H
#define BOAT_H

#include "Base.h"
#include <iostream>
#include <cstring>

class Boat : public Base {
private:
    char purpose[50];       // ����������
    char hullMaterial[50];  // �������� �������
    char performance[50];   // ������� ��������
    double speed;           // ��������
    int capacity;           // ���������� �����

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
    const char* getPurpose() const;
    const char* getHullMaterial() const;
    const char* getPerformance() const;
    double getSpeed() const;
    int getCapacity() const;
    void setPurpose(const char* p);
    void setHullMaterial(const char* m);
    void setPerformance(const char* perf);
    void setSpeed(double s);
    void setCapacity(int cap);


};

#endif

