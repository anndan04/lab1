#include "Sailboat.h"
#include <cstring>
#include <iostream>
using namespace std;

Sailboat::Sailboat() : isMilitary(false), hullLength(0), speed(0), crew(0) {
#ifdef _MSC_VER
    strcpy_s(type, sizeof(type), "Нет");
    strcpy_s(name, sizeof(name), "Нет");
#else
    strncpy(type, "Нет", sizeof(type) - 1);
    type[sizeof(type) - 1] = '\0';
    strncpy(name, "Нет", sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
#endif
    cout << "[Sailboat] Конструктор без параметров\n";
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
    cout << "[Sailboat] Конструктор с параметрами вызван\n";
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
    cout << "[Sailboat] Конструктор копирования вызван\n";
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
        cout << "[Sailboat] Оператор присваивания\n";
    }
    return *this;
}


Sailboat::~Sailboat() {
    cout << "[Sailboat] Деструктор вызван: " << name << "\n";
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
    cout << "Введите тип парусника: "; cin.ignore(); cin.getline(type, sizeof(type));
    cout << "Введите название: "; cin.getline(name, sizeof(name));
    cout << "Мирный (0) или военный (1): "; cin >> isMilitary;
    cout << "Длина корпуса: "; cin >> hullLength;
    cout << "Скорость: "; cin >> speed;
    cout << "Экипаж: "; cin >> crew;
}

void Sailboat::Show() const {
    cout << "\n=== Парусник ===\n";
    cout << "Тип: " << type << "\n";
    cout << "Название: " << name << "\n";
    cout << "Военный: " << (isMilitary ? "Да" : "Нет") << "\n";
    cout << "Длина корпуса: " << hullLength << "\n";
    cout << "Скорость: " << speed << "\n";
    cout << "Экипаж: " << crew << "\n";
}

void Sailboat::Edit() {
    cout << "\nРедактирование парусника:\n";
    Input();
}



Base* Sailboat::Clone() const {
    cout << "[Sailboat] Вызван метод Clone().\n";
    return new Sailboat(*this);
}

