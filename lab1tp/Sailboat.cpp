#include "Sailboat.h"
#include <cstring>
#include <iostream>
using namespace std;

Sailboat::Sailboat() : isMilitary(false), hullLength(0), speed(0), crew(0) {

    strcpy_s(type, sizeof(type), "���");
    strcpy_s(name, sizeof(name), "���");

    cout << "[Sailboat] ����������� ��� ����������\n";
}

Sailboat::Sailboat(const char* t, const char* n, bool m, double hl, double s, int c)
    : isMilitary(m), hullLength(hl), speed(s), crew(c) {

    strcpy_s(type, sizeof(type), t);
    strcpy_s(name, sizeof(name), n);

    cout << "[Sailboat] ����������� � ����������� ������\n";
}

Sailboat::Sailboat(const Sailboat& other)
    : isMilitary(other.isMilitary), hullLength(other.hullLength),
    speed(other.speed), crew(other.crew) {

    strcpy_s(type, sizeof(type), other.type);
    strcpy_s(name, sizeof(name), other.name);

    cout << "[Sailboat] ����������� ����������� ������\n";
}

Sailboat& Sailboat::operator=(const Sailboat& other) {
    if (this != &other) {
        isMilitary = other.isMilitary;
        hullLength = other.hullLength;
        speed = other.speed;
        crew = other.crew;

        strcpy_s(type, sizeof(type), other.type);
        strcpy_s(name, sizeof(name), other.name);

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
    char bufferType[sizeof(type)];
    char bufferName[sizeof(name)];
    bool m;
    double hl, s;
    int c;

    while (true) {
        cout << "������� ��� ���������: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(bufferType, sizeof(bufferType));
        if (strlen(bufferType) > 0) break;
        cout << "������: ��� �� ����� ���� ������.\n";
    }
    setType(bufferType);

    while (true) {
        cout << "������� ��������: ";
        cin.getline(bufferName, sizeof(bufferName));
        if (strlen(bufferName) > 0) break;
        cout << "������: �������� �� ����� ���� ������.\n";
    }
    setName(bufferName);

    while (true) {
        cout << "������ (0) ��� ������� (1): ";
        if (cin >> m && (m == 0 || m == 1)) break;
        cout << "������: ������� 0 (������) ��� 1 (�������).\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setIsMilitary(m);

    while (true) {
        cout << "����� �������: ";
        if (cin >> hl && hl > 0) break;
        cout << "������: ����� ������ ���� ������\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setHullLength(hl);

    while (true) {
        cout << "��������: ";
        if (cin >> s && s > 0) break;
        cout << "������: �������� ������ ���� ������\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setSpeed(s);

    while (true) {
        cout << "������: ";
        if (cin >> c && c > 0) break;
        cout << "������: ������ ������ ���� ����� ������\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    setCrew(c);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Sailboat::Show() const {
    cout << "\n=== �������� ===\n";
    cout << "���: " << getType() << "\n";
    cout << "��������: " << getName() << "\n";
    cout << "�������: " << (getIsMilitary() ? "��" : "���") << "\n";
    cout << "����� �������: " << getHullLength() << "\n";
    cout << "��������: " << getSpeed() << "\n";
    cout << "������: " << getCrew() << "\n";
}

void Sailboat::Save(ofstream& out) const {
    out << "Sailboat\n";
    out << getType() << '\n'
        << getName() << '\n'
        << getIsMilitary() << '\n'
        << getHullLength() << '\n'
        << getSpeed() << '\n'
        << getCrew() << '\n';
}
void Sailboat::Edit() {
    cout << "\n�������������� ���������:\n";
    Input();
}

void Sailboat::Load(ifstream& in) {
    char bufferType[sizeof(type)];
    char bufferName[sizeof(name)];
    bool m;
    double hl, s;
    int c;

    in.ignore();

    in.getline(bufferType, sizeof(bufferType));
    in.getline(bufferName, sizeof(bufferName));
    in >> m;
    in >> hl;
    in >> s;
    in >> c;
    in.ignore();

    setType(bufferType);
    setName(bufferName);
    setIsMilitary(m);
    setHullLength(hl);
    setSpeed(s);
    setCrew(c);
}



Base* Sailboat::Clone() const {
    cout << "[Sailboat] ������ ����� Clone().\n";
    return new Sailboat(*this);
}

