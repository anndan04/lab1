//в этой версии добавлены оператор присвваивания, конструктор копирования, 
// вывод при вызове конструкторов, изменения в load
//save и load bool

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
            items[i] = other.items[i]->Clone(); // глубокое копирование
    }
}
void Keeper::Add(Base* obj) {
    Base** new_items = new Base * [count + 1];
    for (int i = 0; i < count; ++i)
        new_items[i] = items[i];
    new_items[count] = obj;
    delete[] items;
    items = new_items;
    count++;
}

void Keeper::Remove(int index) {
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
        cout << "\n--- Объект " << i + 1 << " ---\n";
        items[i]->Show();
    }
}



