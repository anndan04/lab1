#include "Keeper.h"
#include "Submarine.h"
#include "Boat.h"
#include "Sailboat.h"
#include <iostream>
#include <fstream>
using namespace std;

Keeper::Keeper() : items(nullptr), count(0) { cout << "[Keeper] Конструктор без параметров\n"; }

Keeper::~Keeper() {
    cout << "[Keeper] Деструктор\n";
    for (int i = 0; i < count; ++i)
        delete items[i];
    delete[] items;
}
Keeper& Keeper::operator=(const Keeper& other) {
    cout << "[Keeper] Оператор присваивания\n";
    if (this == &other) return *this;

    for (int i = 0; i < count; ++i)
        delete items[i];
    delete[] items;
    items = nullptr;
    count = 0;

    if (other.count > 0) {
        count = other.count;
        items = new Base * [count];
        for (int i = 0; i < count; ++i)
            items[i] = other.items[i]->Clone();
    }

    return *this;
}
Keeper::Keeper(const Keeper& other) : items(nullptr), count(0) {
    cout << "[Keeper] Конструктор копирования\n";
    if (other.count > 0) {
        count = other.count;
        items = new Base * [count];
        for (int i = 0; i < count; ++i)
            items[i] = other.items[i]->Clone(); 
    }
}

void Keeper::Add(Base* obj) { //добавление нового
    Base** new_items = new Base * [count + 1];
    for (int i = 0; i < count; ++i)
        new_items[i] = items[i];
    new_items[count] = obj;
    delete[] items;
    items = new_items;
    count++;
}

void Keeper::Remove(int index) { //удалитьь
    if (index < 0 || index >= count) {
        cout << "Неверный индекс\n";
        return;
    }

    delete items[index];

    for (int i = index; i < count - 1; ++i)
        items[i] = items[i + 1];

    count--;

    if (count == 0) {
        delete[] items;
        items = nullptr;
    }
    else {
        Base** new_items = new Base * [count];
        for (int i = 0; i < count; ++i)
            new_items[i] = items[i];
        delete[] items;
        items = new_items;
    }
}

void Keeper::Edit(int index) {
    if (index < 0 || index >= count) {
        cout << "Неверный индекс\n";
        return;
    }
    items[index]->Edit();
}

void Keeper::ShowAll() const {
    if (count == 0) {
        cout << "Контейнер пусой\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        cout << "\n Корабль " << i + 1 << "\n";
        items[i]->Show();
    }
}
void Keeper::SaveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        cout << "Ошибка открытия файла для записи\n";
        return;
    }
    out << count << '\n'; 
    for (int i = 0; i < count; ++i) {
        items[i]->Save(out);
    }

    cout << "Данные успешно сохранены в " << filename << endl;
    out.close();
}

void Keeper::LoadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Ошибка открытия файла для чтения\n";
        return;
    }

   
    for (int i = 0; i < count; ++i)
        delete items[i];
    delete[] items;
    items = nullptr;
    count = 0;

    int newCount;
    in >> newCount;
    in.ignore();

    for (int i = 0; i < newCount; ++i) {
        string type;
        getline(in, type);

        Base* obj = nullptr;
        if (type == "Sailboat")
            obj = new Sailboat();
        else if (type == "Submarine")
            obj = new Submarine();
        else if (type == "Boat")
            obj = new Boat();

        if (obj) {
            obj->Load(in);
            Add(obj);
        }
    }

    cout << "Данные успешно загружены из " << filename << endl;
    in.close();
}