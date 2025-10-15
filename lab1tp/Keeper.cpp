#include "Keeper.h"
#include "Submarine.h"
#include <iostream>
#include <fstream>
using namespace std;

Keeper::Keeper() : items(nullptr), count(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i)
        delete items[i];
    delete[] items;
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
        cout << "Неверный индекс!\n";
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
        cout << "Неверный индекс!\n";
        return;
    }
    items[index]->Edit();
}

void Keeper::ShowAll() const {
    if (count == 0) {
        cout << "Контейнер пуст.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        cout << "\n--- Объект #" << i + 1 << " ---\n";
        items[i]->Show();
    }
}

void Keeper::SaveToFile(const char* filename) const {
    ofstream out(filename, ios::binary);
    if (!out) {
        cout << "Ошибка открытия файла для записи!\n";
        return;
    }
    out.write((char*)&count, sizeof(count));
    for (int i = 0; i < count; ++i)
        items[i]->Save(out);
    out.close();
    cout << "Данные сохранены в файл: " << filename << "\n";
}

void Keeper::LoadFromFile(const char* filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cout << "Ошибка открытия файла для чтения!\n";
        return;
    }

    for (int i = 0; i < count; ++i)
        delete items[i];
    delete[] items;
    items = nullptr;
    count = 0;

    in.read((char*)&count, sizeof(count));
    items = new Base * [count];
    for (int i = 0; i < count; ++i) {
        Submarine* sub = new Submarine();
        sub->Load(in);
        items[i] = sub;
    }
    in.close();
    cout << "Данные успешно загружены из файла: " << filename << "\n";
}
