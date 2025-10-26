#include "Boat.h"
#include <iostream>
#include <cstring>
using namespace std;

Boat::Boat() : speed(0), capacity(0) {
#ifdef _MSC_VER
    strcpy_s(purpose, sizeof(purpose), "Нет");
    strcpy_s(hullMaterial, sizeof(hullMaterial), "Нет");
    strcpy_s(performance, sizeof(performance), "Нет");
#else
    strncpy(purpose, "Нет", sizeof(purpose) - 1);
    purpose[sizeof(purpose) - 1] = '\0';
    strncpy(hullMaterial, "Нет", sizeof(hullMaterial) - 1);
    hullMaterial[sizeof(hullMaterial) - 1] = '\0';
    strncpy(performance, "Нет", sizeof(performance) - 1);
    performance[sizeof(performance) - 1] = '\0';
#endif
    cout << "[Boat] Конструктор без параметров\n";
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
    cout << "[Boat] Конструктор с параметрами\n";
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
    cout << "[Boat] Конструктор копирования\n";
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
    cout << "[Boat] Оператор присваивания\n";
    return *this;
}

Boat::~Boat() {
    cout << "[Boat] Деструктор вызван\n";
}

void Boat::Input() {
    
    while (true) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера перед getline
        cout << "Введите назначение катера: ";
        cin.getline(purpose, sizeof(purpose));
        if (strlen(purpose) > 0) break;
        cout << "Ошибка: назначение не может быть пустым.\n";
    }

   
    while (true) {
        cout << "Введите материал корпуса: ";
        cin.getline(hullMaterial, sizeof(hullMaterial));
        if (strlen(hullMaterial) > 0) break;
        cout << "Ошибка: материал корпуса не может быть пустым.\n";
    }

   
    while (true) {
        cout << "Введите ходовые качества: ";
        cin.getline(performance, sizeof(performance));
        if (strlen(performance) > 0) break;
        cout << "Ошибка: ходовые качества не могут быть пустыми.\n";
    }


    while (true) {
        cout << "Введите скорость: ";
        if (cin >> speed && speed > 0) break;
        cout << "Ошибка: скорость должна быть числом\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

 
    while (true) {
        cout << "Введите вместимость (кол-во людей): ";
        if (cin >> capacity && capacity > 0) break;
        cout << "Ошибка: вместимость должна быть целым числом\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Boat::Show() const {
    cout << "\n=== Катер ===\n";
    cout << "Назначение: " << purpose << "\n";
    cout << "Материал корпуса: " << hullMaterial << "\n";
    cout << "Ходовые качества: " << performance << "\n";
    cout << "Скорость: " << speed << "\n";
    cout << "Вместимость: " << capacity << "\n";
}

void Boat::Edit() {
    cout << "\nРедактирование катера:\n";
    Input();
}

Base* Boat::Clone() const {
    cout << "[Boat] Вызван метод Clone().\n";
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
