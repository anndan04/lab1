#include "Boat.h"
#include <iostream>
#include <cstring>
using namespace std;

Boat::Boat() : speed(0), capacity(0) {
#ifdef _MSC_VER
    strcpy_s(purpose, sizeof(purpose), "���");
    strcpy_s(hullMaterial, sizeof(hullMaterial), "���");
    strcpy_s(performance, sizeof(performance), "���");
#else
    strncpy(purpose, "���", sizeof(purpose) - 1);
    purpose[sizeof(purpose) - 1] = '\0';
    strncpy(hullMaterial, "���", sizeof(hullMaterial) - 1);
    hullMaterial[sizeof(hullMaterial) - 1] = '\0';
    strncpy(performance, "���", sizeof(performance) - 1);
    performance[sizeof(performance) - 1] = '\0';
#endif
    cout << "[Boat] ����������� ��� ����������\n";
}

Boat::Boat(const char* p, const char* m, const char* perf, double s, int cap)
    : speed(s), capacity(cap) {
#ifdef _MSC_VER
    strcpy_s(purpose, sizeof(purpose), p);
    strcpy_s(hullMaterial, sizeof(hullMaterial), m);
    strcpy_s(performance, sizeof(performance), perf);
#else
    strncpy(purpose, p, sizeof(purpose) - 1); purpose[sizeof(purpose) - 1] = '\0';
    strncpy(hullMaterial, m, sizeof(hullMaterial) - 1); hullMaterial[sizeof(hullMaterial) - 1] = '\0';
    strncpy(performance, perf, sizeof(performance) - 1); performance[sizeof(performance) - 1] = '\0';
#endif
    cout << "[Boat] ����������� � �����������\n";
}

Boat::Boat(const Boat& other)
    : speed(other.speed), capacity(other.capacity) {
#ifdef _MSC_VER
    strcpy_s(purpose, sizeof(purpose), other.purpose);
    strcpy_s(hullMaterial, sizeof(hullMaterial), other.hullMaterial);
    strcpy_s(performance, sizeof(performance), other.performance);
#else
    strncpy(purpose, other.purpose, sizeof(purpose) - 1); purpose[sizeof(purpose) - 1] = '\0';
    strncpy(hullMaterial, other.hullMaterial, sizeof(hullMaterial) - 1); hullMaterial[sizeof(hullMaterial) - 1] = '\0';
    strncpy(performance, other.performance, sizeof(performance) - 1); performance[sizeof(performance) - 1] = '\0';
#endif
    cout << "[Boat] ����������� �����������\n";
}

Boat& Boat::operator=(const Boat& other) {
    if (this != &other) {
        speed = other.speed;
        capacity = other.capacity;
#ifdef _MSC_VER
        strcpy_s(purpose, sizeof(purpose), other.purpose);
        strcpy_s(hullMaterial, sizeof(hullMaterial), other.hullMaterial);
        strcpy_s(performance, sizeof(performance), other.performance);
#else
        strncpy(purpose, other.purpose, sizeof(purpose) - 1); purpose[sizeof(purpose) - 1] = '\0';
        strncpy(hullMaterial, other.hullMaterial, sizeof(hullMaterial) - 1); hullMaterial[sizeof(hullMaterial) - 1] = '\0';
        strncpy(performance, other.performance, sizeof(performance) - 1); performance[sizeof(performance) - 1] = '\0';
#endif
    }
    cout << "[Boat] �������� ������������\n";
    return *this;
}

Boat::~Boat() {
    cout << "[Boat] ���������� ������\n";
}

void Boat::Input() {
    
    while (true) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������ ����� getline
        cout << "������� ���������� ������: ";
        cin.getline(purpose, sizeof(purpose));
        if (strlen(purpose) > 0) break;
        cout << "������: ���������� �� ����� ���� ������.\n";
    }

   
    while (true) {
        cout << "������� �������� �������: ";
        cin.getline(hullMaterial, sizeof(hullMaterial));
        if (strlen(hullMaterial) > 0) break;
        cout << "������: �������� ������� �� ����� ���� ������.\n";
    }

   
    while (true) {
        cout << "������� ������� ��������: ";
        cin.getline(performance, sizeof(performance));
        if (strlen(performance) > 0) break;
        cout << "������: ������� �������� �� ����� ���� �������.\n";
    }


    while (true) {
        cout << "������� ��������: ";
        if (cin >> speed && speed > 0) break;
        cout << "������: �������� ������ ���� ������\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

 
    while (true) {
        cout << "������� ����������� (���-�� �����): ";
        if (cin >> capacity && capacity > 0) break;
        cout << "������: ����������� ������ ���� ����� ������\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Boat::Show() const {
    cout << "\n=== ����� ===\n";
    cout << "����������: " << purpose << "\n";
    cout << "�������� �������: " << hullMaterial << "\n";
    cout << "������� ��������: " << performance << "\n";
    cout << "��������: " << speed << "\n";
    cout << "�����������: " << capacity << "\n";
}

void Boat::Edit() {
    cout << "\n�������������� ������:\n";
    Input();
}

Base* Boat::Clone() const {
    cout << "[Boat] ������ ����� Clone().\n";
    return new Boat(*this);
}

void Boat::Save(ofstream& out) const {
    out << "Boat\n";
    out << purpose << '\n'
        << hullMaterial << '\n'
        << performance << '\n'
        << speed << '\n'
        << capacity << '\n';
}

void Boat::Load(ifstream& in) {
    in.ignore();
    in.getline(purpose, sizeof(purpose));
    in.getline(hullMaterial, sizeof(hullMaterial));
    in.getline(performance, sizeof(performance));
    in >> speed;
    in >> capacity;
    in.ignore();
}
