#include "Submarine.h"
#include <cstring>
#include <iostream>
using namespace std;

// === ������������ ===
Submarine::Submarine()
    : length(0), width(0), crew(0),
    underwater_time(0), max_underwater_speed(0) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), "���");
#else
    strncpy(weapon, "���", sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
    cout << "[Submarine] ������ ����������� ��� ����������.\n";
}

Submarine::Submarine(double l, double w, int c, double ut, double mus, const char* wp)
    : length(l), width(w), crew(c), underwater_time(ut), max_underwater_speed(mus) {
#ifdef _MSC_VER
    strcpy_s(weapon, sizeof(weapon), wp);
#else
    strncpy(weapon, wp, sizeof(weapon) - 1);
    weapon[sizeof(weapon) - 1] = '\0';
#endif
    cout << "[Submarine] ������ ����������� � �����������.\n";
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
    cout << "[Submarine] ������ ����������� �����������.\n";
}

// === ���������� ===
Submarine::~Submarine() {
    cout << "[Submarine] ������ ���������� ��� ������� � �����������: " << weapon << "\n";
}

// === ��������� ===
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
        cout << "[Submarine] �������� ������������ ������.\n";
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

// === ������ ������� (get / set) ===
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

// === ������ Base ===
void Submarine::Input() {
    cout << "������� ����� (�): "; cin >> length;
    cout << "������� ������ (�): "; cin >> width;
    cout << "������� ����������� �������: "; cin >> crew;
    cout << "������� ����� ��� ����� (����): "; cin >> underwater_time;
    cout << "������� ������������ ��������� �������� (����): "; cin >> max_underwater_speed;
    cout << "������� ����������: ";
    cin.ignore();
    cin.getline(weapon, sizeof(weapon));
}

void Submarine::Show() const {
    cout << "\n=== ��������� ����� ===\n";
    cout << "�����: " << length << " �\n";
    cout << "������: " << width << " �\n";
    cout << "������: " << crew << " ���\n";
    cout << "����� ��� �����: " << underwater_time << " �\n";
    cout << "����. ��������: " << max_underwater_speed << " �����\n";
    cout << "����������: " << weapon << "\n";
}

void Submarine::Edit() {
    cout << "\n�������������� ������ ��������� �����:\n";
    Input();
}

void Submarine::Save(ofstream& out) const {
    out.write((char*)&length, sizeof(length));
    out.write((char*)&width, sizeof(width));
    out.write((char*)&crew, sizeof(crew));
    out.write((char*)&underwater_time, sizeof(underwater_time));
    out.write((char*)&max_underwater_speed, sizeof(max_underwater_speed));
    out.write(weapon, sizeof(weapon));
}

void Submarine::Load(ifstream& in) {
    in.read((char*)&length, sizeof(length));
    in.read((char*)&width, sizeof(width));
    in.read((char*)&crew, sizeof(crew));
    in.read((char*)&underwater_time, sizeof(underwater_time));
    in.read((char*)&max_underwater_speed, sizeof(max_underwater_speed));
    in.read(weapon, sizeof(weapon));
}

Base* Submarine::Clone() const {
    cout << "[Submarine] ������ ����� Clone().\n";
    return new Submarine(*this);
}
