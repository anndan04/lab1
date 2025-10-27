#include "Submarine.h"
#include <cstring>
#include <iostream>
using namespace std;


Submarine::Submarine()
    : length(0), width(0), crew(0),
    underwater_time(0), max_underwater_speed(0) {

    strcpy_s(weapon, sizeof(weapon), "Нет");

    cout << "[Submarine] Вызван конструктор без параметров\n";
}

Submarine::Submarine(double l, double w, int c, double ut, double mus, const char* wp)
    : length(l), width(w), crew(c), underwater_time(ut), max_underwater_speed(mus) {

    strcpy_s(weapon, sizeof(weapon), wp);

    cout << "[Submarine] Вызван конструктор с параметрами\n";
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew),
    underwater_time(other.underwater_time),
    max_underwater_speed(other.max_underwater_speed) {

    strcpy_s(weapon, sizeof(weapon), other.weapon);

    cout << "[Submarine] Вызван конструктор копирования\n";
}

Submarine::~Submarine() {
    cout << "[Submarine] Вызван деструктор " << weapon << "\n";
}


Submarine& Submarine::operator=(const Submarine& other) {
    if (this != &other) {
        length = other.length;
        width = other.width;
        crew = other.crew;
        underwater_time = other.underwater_time;
        max_underwater_speed = other.max_underwater_speed;

        strcpy_s(weapon, sizeof(weapon), other.weapon);

        cout << "[Submarine] Оператор присваивания вызван\n";
    }
    return *this;
}



double Submarine::getLength() const { return length; }
double Submarine::getWidth() const { return width; }
int Submarine::getCrew() const { return crew; }
double Submarine::getUnderwaterTime() const { return underwater_time; }
double Submarine::getMaxUnderwaterSpeed() const { return max_underwater_speed; }
const char* Submarine::getWeapon() const { return weapon; }

void Submarine::setLength(double l) { length = l; }
void Submarine::setWidth(double w) { width = w; }
void Submarine::setCrew(int c) { crew = c; }
void Submarine::setUnderwaterTime(double t) { underwater_time = t; }
void Submarine::setMaxUnderwaterSpeed(double s) { max_underwater_speed = s; }
void Submarine::setWeapon(const char* w) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), w);
#else
    strncpy(weapon, w, sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
}


void Submarine::Input() {
    double l, w, ut, mus;
    int c;
    char wp[sizeof(weapon)];

    while (true) {
        cout << "Введите длину (м): ";
        if (cin >> l && l > 0) break;
        else {
            cout << "Ошибка: длина должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    setLength(l);

    while (true) {
        cout << "Введите ширину (м): ";
        if (cin >> w && w > 0) break;
        else {
            cout << "Ошибка: ширина должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    setWidth(w);

    while (true) {
        cout << "Введите численность экипажа: ";
        if (cin >> c && c > 0) break;
        else {
            cout << "Ошибка: экипаж должен быть целым числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    setCrew(c);

    while (true) {
        cout << "Введите время под водой (часы): ";
        if (cin >> ut && ut > 0) break;
        else {
            cout << "Ошибка: время под водой должно быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    setUnderwaterTime(ut);

    while (true) {
        cout << "Введите максимальную подводную скорость (узлы): ";
        if (cin >> mus && mus > 0) break;
        else {
            cout << "Ошибка: скорость должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    setMaxUnderwaterSpeed(mus);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите вооружение: ";
    cin.getline(wp, sizeof(wp));

    while (strlen(wp) == 0) {
        cout << "Ошибка: вооружение не может быть пустым ";
        cin.getline(wp, sizeof(wp));
    }
    setWeapon(wp);
}
Base* Submarine::Clone() const {
    cout << "[Submarine] Вызван метод Clone().\n";
    return new Submarine(*this);
}
void Submarine::Show() const {
    cout << "\n----Подводная лодка ----\n";
    cout << "Длина: " << getLength() << " м\n";
    cout << "Ширина: " << getWidth() << " м\n";
    cout << "Экипаж: " << getCrew() << " чел\n";
    cout << "Время под водой: " << getUnderwaterTime() << " ч\n";
    cout << "Макс. скорость: " << getMaxUnderwaterSpeed() << " узлов\n";
    cout << "Вооружение: " << getWeapon() << "\n";
}

void Submarine::Edit() {
    cout << "\nРедактирование данных подводной лодки:\n";
    Input();
}

void Submarine::Save(ofstream& out) const {
    out << "Submarine\n";
    out << getLength() << '\n'
        << getWidth() << '\n'
        << getCrew() << '\n'
        << getUnderwaterTime() << '\n'
        << getMaxUnderwaterSpeed() << '\n'
        << getWeapon() << '\n';
}

void Submarine::Load(ifstream& in) {
    double l, w, ut, mus;
    int c;
    char wp[sizeof(weapon)];

    in >> l >> w >> c >> ut >> mus;
    in.ignore();
    in.getline(wp, sizeof(wp));

    setLength(l);
    setWidth(w);
    setCrew(c);
    setUnderwaterTime(ut);
    setMaxUnderwaterSpeed(mus);
    setWeapon(wp);
}


