#include <iostream>
#include "Keeper.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Boat.h"
#include <locale>
using namespace std;

void menu() {
    Keeper keeper;
   const char* filename = "ships.txt";

    while (true) {
        cout 
            << "1. Добавить объект\n"
            << "2. Удалить объект\n"
            << "3. Показать все объекты\n"
            << "4. Изменить объект\n"
            << "5. Сохранить в файл\n"
            << "6. Загрузить из файла\n"
            << "0. Выход\n"
            << "Выбор: ";

        int c; cin >> c;
        if (c == 0) break;

        switch (c) {
        case 1: {
            cout << "Тип (1-подлодка, 2-Парусник, 3-Катер): ";
            int t; cin >> t;
            Base* obj = nullptr;
            switch (t) {
            case 1: obj = new Submarine(); break;
            case 2: obj = new Sailboat(); break;
            case 3: obj = new Boat(); break;
            default: cout << "Ошибка\n"; continue;
            }
            obj->Edit();
            keeper.Add(obj);
            break;
        }
        case 2: {
            int idx;
            cout << "Введите номер судна для удаления: ";
            cin >> idx;
            keeper.Remove(idx - 1);
            break;
        }
        case 3: keeper.ShowAll(); break;
        case 4: {
            int i; cout << "Введите индекс: "; cin >> i;
            keeper.Edit(i);
            break;
        }
              case 5: {
            keeper.SaveToFile(filename);
            break;
        }

        case 6: {
            keeper.LoadFromFile(filename);
            break;
        }
        default:
            cout << "Нет такого\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");  
    menu();
    return 0;
}