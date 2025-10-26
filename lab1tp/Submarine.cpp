#include "Submarine.h"
#include <cstring>
#include <iostream>
using namespace std;


Submarine::Submarine()
    : length(0), width(0), crew(0),
    underwater_time(0), max_underwater_speed(0) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), "Нет");
#else
    strncpy(weapon, "Нет", sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
    cout << "[Submarine] Вызван конструктор без параметров\n";
}

Submarine::Submarine(double l, double w, int c, double ut, double mus, const char* wp)
    : length(l), width(w), crew(c), underwater_time(ut), max_underwater_speed(mus) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), wp);
#else
    strncpy(weapon, wp, sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
    cout << "[Submarine] Вызван конструктор с параметрами\n";
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew),
    underwater_time(other.underwater_time),
    max_underwater_speed(other.max_underwater_speed) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), other.weapon);
#else
    strncpy(weapon, other.weapon, sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
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
#ifdef _MSC_VER
        strcpy_s(weapon, sizeof(weapon), other.weapon);
#else
        strncpy(weapon, other.weapon, sizeof(weapon) - 1);
        weapon[sizeof(weapon) - 1] = '\0';
#endif
        cout << "[Submarine] Оператор присваивания вызван\n";
    }
    return *this;
}

bool Submarine::operator==(const Submarine& other) const {
    return (length == other.length &&
        width == other.width &&
        crew == other.crew &&
        underwater_time == other.underwater_time &&
        max_underwater_speed == other.max_underwater_speed &&
        strcmp(weapon, other.weapon) == 0);
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
    while (true) {
        cout << "Введите длину (м): ";
        if (cin >> length && length > 0) break;
        else {
            cout << "Ошибка: длина должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Введите ширину (м): ";
        if (cin >> width && width > 0) break;
        else {
            cout << "Ошибка: ширина должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Введите численность экипажа: ";
        if (cin >> crew && crew > 0) break;
        else {
            cout << "Ошибка: экипаж должен быть целым числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Введите время под водой (часы): ";
        if (cin >> underwater_time && underwater_time > 0) break;
        else {
            cout << "Ошибка: время под водой должно быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) {
        cout << "Введите максимальную подводную скорость (узлы): ";
        if (cin >> max_underwater_speed && max_underwater_speed > 0) break;
        else {
            cout << "Ошибка: скорость должна быть числом\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Введите вооружение: ";
    cin.getline(weapon, sizeof(weapon));

   
    while (strlen(weapon) == 0) {
        cout << "Ошибка: вооружение не может быть пустым ";
        cin.getline(weapon, sizeof(weapon));
    }
}

void Submarine::Show() const {
    cout << "\n=== Подводная лодка ===\n";
    cout << "Длина: " << length << " м\n";
    cout << "Ширина: " << width << " м\n";
    cout << "Экипаж: " << crew << " чел\n";
    cout << "Время под водой: " << underwater_time << " ч\n";
    cout << "Макс. скорость: " << max_underwater_speed << " узлов\n";
    cout << "Вооружение: " << weapon << "\n";
}

void Submarine::Edit() {
    cout << "\nРедактирование данных подводной лодки:\n";
    Input();
}

Base* Submarine::Clone() const {
    cout << "[Submarine] Вызван метод Clone().\n";
    return new Submarine(*this);
}
void Submarine::Save(ofstream& out) const {
    out << "Submarine\n"; 
    out << length << '\n'
        << width << '\n'
        << crew << '\n'
        << underwater_time << '\n'
        << max_underwater_speed << '\n'
        << weapon << '\n';
}

void Submarine::Load(ifstream& in) {
    in >> length;
    in >> width;
    in >> crew;
    in >> underwater_time;
    in >> max_underwater_speed;
    in.ignore(); 
    in.getline(weapon, sizeof(weapon));
}

