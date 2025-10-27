#include "Boat.h"
#include <iostream>
#include <cstring>
using namespace std;

Boat::Boat() : speed(0), capacity(0) {

    strcpy_s(purpose, sizeof(purpose), "Нет");
    strcpy_s(hullMaterial, sizeof(hullMaterial), "Нет");
    strcpy_s(performance, sizeof(performance), "Нет");

    cout << "[Boat] Конструктор без параметров\n";
}

Boat::Boat(const char* p, const char* m, const char* perf, double s, int cap)
    : speed(s), capacity(cap) {

    strcpy_s(purpose, sizeof(purpose), p);
    strcpy_s(hullMaterial, sizeof(hullMaterial), m);
    strcpy_s(performance, sizeof(performance), perf);

    cout << "[Boat] Конструктор с параметрами\n";
}

Boat::Boat(const Boat& other)
    : speed(other.speed), capacity(other.capacity) {
    strcpy_s(purpose, sizeof(purpose), other.purpose);
    strcpy_s(hullMaterial, sizeof(hullMaterial), other.hullMaterial);
    strcpy_s(performance, sizeof(performance), other.performance);

    cout << "[Boat] Конструктор копирования\n";
}

Boat& Boat::operator=(const Boat& other) {
    if (this != &other) {
        speed = other.speed;
        capacity = other.capacity;

        strcpy_s(purpose, sizeof(purpose), other.purpose);
        strcpy_s(hullMaterial, sizeof(hullMaterial), other.hullMaterial);
        strcpy_s(performance, sizeof(performance), other.performance);

    }
    cout << "[Boat] Оператор присваивания\n";
    return *this;
}

Boat::~Boat() {
    cout << "[Boat] Деструктор вызван\n";
}

const char* Boat::getPurpose() const { return purpose; }
const char* Boat::getHullMaterial() const { return hullMaterial; }
const char* Boat::getPerformance() const { return performance; }
double Boat::getSpeed() const { return speed; }
int Boat::getCapacity() const { return capacity; }


void Boat::setPurpose(const char* p) {

    strcpy_s(purpose, sizeof(purpose), p);
}

void Boat::setHullMaterial(const char* m) {

    strcpy_s(hullMaterial, sizeof(hullMaterial), m);
}

void Boat::setPerformance(const char* perf) {

    strcpy_s(performance, sizeof(performance), perf);
}

void Boat::setSpeed(double s) { speed = s; }
void Boat::setCapacity(int cap) { capacity = cap; }

void Boat::Input() {
    char bufPurpose[sizeof(purpose)];
    char bufHullMaterial[sizeof(hullMaterial)];
    char bufPerformance[sizeof(performance)];
    double s;
    int cap;

    while (true) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введите назначение катера: ";
        cin.getline(bufPurpose, sizeof(bufPurpose));
        if (strlen(bufPurpose) > 0) break;
        cout << "Ошибка: назначение не может быть пустым.\n";
    }
    setPurpose(bufPurpose);

    while (true) {
        cout << "Введите материал корпуса: ";
        cin.getline(bufHullMaterial, sizeof(bufHullMaterial));
        if (strlen(bufHullMaterial) > 0) break;
        cout << "Ошибка: материал корпуса не может быть пустым.\n";
    }
    setHullMaterial(bufHullMaterial);

    while (true) {
        cout << "Введите ходовые качества: ";
        cin.getline(bufPerformance, sizeof(bufPerformance));
        if (strlen(bufPerformance) > 0) break;
        cout << "Ошибка: ходовые качества не могут быть пустыми.\n";
    }
    setPerformance(bufPerformance);

    while (true) {
        cout << "Введите скорость: ";
        if (cin >> s && s > 0) break;
        cout << "Ошибка: скорость должна быть числом\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setSpeed(s);

    while (true) {
        cout << "Введите вместимость (кол-во людей): ";
        if (cin >> cap && cap > 0) break;
        cout << "Ошибка: вместимость должна быть целым числом\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setCapacity(cap);
}
void Boat::Edit() {
    cout << "\nРедактирование катера:\n";
    Input();
}
void Boat::Show() const {
    cout << "\n=== Катер ===\n";
    cout << "Назначение: " << getPurpose() << "\n";
    cout << "Материал корпуса: " << getHullMaterial() << "\n";
    cout << "Ходовые качества: " << getPerformance() << "\n";
    cout << "Скорость: " << getSpeed() << "\n";
    cout << "Вместимость: " << getCapacity() << "\n";
}

void Boat::Save(ofstream& out) const {
    out << "Boat\n";
    out << getPurpose() << '\n'
        << getHullMaterial() << '\n'
        << getPerformance() << '\n'
        << getSpeed() << '\n'
        << getCapacity() << '\n';
}

void Boat::Load(ifstream& in) {
    char bufPurpose[sizeof(purpose)];
    char bufHullMaterial[sizeof(hullMaterial)];
    char bufPerformance[sizeof(performance)];
    double s;
    int cap;

    in.ignore();
    in.getline(bufPurpose, sizeof(bufPurpose));
    in.getline(bufHullMaterial, sizeof(bufHullMaterial));
    in.getline(bufPerformance, sizeof(bufPerformance));
    in >> s;
    in >> cap;
    in.ignore();

    setPurpose(bufPurpose);
    setHullMaterial(bufHullMaterial);
    setPerformance(bufPerformance);
    setSpeed(s);
    setCapacity(cap);
}


Base* Boat::Clone() const {
    cout << "[Boat] Вызван метод Clone().\n";
    return new Boat(*this);
}

