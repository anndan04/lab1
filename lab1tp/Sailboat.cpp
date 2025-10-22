#include "Sailboat.h"
#include <cstring>
#include <iostream>
using namespace std;

Sailboat::Sailboat() : isMilitary(false), hullLength(0), speed(0), crew(0) {
#ifdef _MSC_VER
    strcpy_s(type, sizeof(type), "���");
    strcpy_s(name, sizeof(name), "���");
#else
    strncpy(type, "���", sizeof(type) - 1);
    type[sizeof(type) - 1] = '\0';
    strncpy(name, "���", sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
#endif
    cout << "[Sailboat] ����������� ��� ����������\n";
}

Sailboat::Sailboat(const char* t, const char* n, bool m, double hl, double s, int c)
    : isMilitary(m), hullLength(hl), speed(s), crew(c) {
#ifdef _MSC_VER
    strcpy_s(type, sizeof(type), t);
    strcpy_s(name, sizeof(name), n);
#else
    strncpy(type, t, sizeof(type) - 1); type[sizeof(type) - 1] = '\0';
    strncpy(name, n, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
#endif
    cout << "[Sailboat] ����������� � ����������� ������\n";
}

Sailboat::Sailboat(const Sailboat& other)
    : isMilitary(other.isMilitary), hullLength(other.hullLength),
    speed(other.speed), crew(other.crew) {
#ifdef _MSC_VER
    strcpy_s(type, sizeof(type), other.type);
    strcpy_s(name, sizeof(name), other.name);
#else
    strncpy(type, other.type, sizeof(type) - 1); type[sizeof(type) - 1] = '\0';
    strncpy(name, other.name, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
#endif
    cout << "[Sailboat] ����������� ����������� ������\n";
}

Sailboat& Sailboat::operator=(const Sailboat& other) {
    if (this != &other) {
        isMilitary = other.isMilitary;
        hullLength = other.hullLength;
        speed = other.speed;
        crew = other.crew;
#ifdef _MSC_VER
        strcpy_s(type, sizeof(type), other.type);
        strcpy_s(name, sizeof(name), other.name);
#else
        strncpy(type, other.type, sizeof(type) - 1); type[sizeof(type) - 1] = '\0';
        strncpy(name, other.name, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
#endif
        cout << "[Sailboat] �������� ������������\n";
    }
    return *this;
}


Sailboat::~Sailboat() {
    cout << "[Sailboat] ���������� ������: " << name << "\n";
}


const char* Sailboat::getType() const { return type; }
const char* Sailboat::getName() const { return name; }
bool Sailboat::getIsMilitary() const { return isMilitary; }
double Sailboat::getHullLength() const { return hullLength; }
double Sailboat::getSpeed() const { return speed; }
int Sailboat::getCrew() const { return crew; }

void Sailboat::setType(const char* t) {
#ifdef _MSC_VER
    strcpy_s(type, sizeof(type), t);
#else
    strncpy(type, t, sizeof(type) - 1); type[sizeof(type) - 1] = '\0';
#endif
}
void Sailboat::setName(const char* n) {
#ifdef _MSC_VER
    strcpy_s(name, sizeof(name), n);
#else
    strncpy(name, n, sizeof(name) - 1); name[sizeof(name) - 1] = '\0';
#endif
}
void Sailboat::setIsMilitary(bool m) { isMilitary = m; }
void Sailboat::setHullLength(double hl) { hullLength = hl; }
void Sailboat::setSpeed(double s) { speed = s; }
void Sailboat::setCrew(int c) { crew = c; }


void Sailboat::Input() {
    cout << "������� ��� ���������: "; cin.ignore(); cin.getline(type, sizeof(type));
    cout << "������� ��������: "; cin.getline(name, sizeof(name));
    cout << "������ (0) ��� ������� (1): "; cin >> isMilitary;
    cout << "����� �������: "; cin >> hullLength;
    cout << "��������: "; cin >> speed;
    cout << "������: "; cin >> crew;
}

void Sailboat::Show() const {
    cout << "\n=== �������� ===\n";
    cout << "���: " << type << "\n";
    cout << "��������: " << name << "\n";
    cout << "�������: " << (isMilitary ? "��" : "���") << "\n";
    cout << "����� �������: " << hullLength << "\n";
    cout << "��������: " << speed << "\n";
    cout << "������: " << crew << "\n";
}

void Sailboat::Edit() {
    cout << "\n�������������� ���������:\n";
    Input();
}



Base* Sailboat::Clone() const {
    cout << "[Sailboat] ������ ����� Clone().\n";
    return new Sailboat(*this);
}

