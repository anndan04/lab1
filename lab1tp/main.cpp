#include "Keeper.h"
#include "Submarine.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    Keeper keeper;
    int choice;

    while (true) {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Добавить подводную лодку\n";
        cout << "2. Удалить подводную лодку\n";
        cout << "3. Показать все подводные лодки\n";
        cout << "4. Изменить данные подводной лодки\n";
        cout << "5. Сохранить все в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Submarine* s = new Submarine();
            s->Input();
            keeper.Add(s);
            cout << "Подводная лодка добавлена!\n";
            break;
        }
        case 2: {
            int idx;
            cout << "Введите номер лодки для удаления: ";
            cin >> idx;
            keeper.Remove(idx - 1);
            break;
        }
        case 3:
            keeper.ShowAll();
            break;
        case 4: {
            int idx;
            cout << "Введите номер лодки для изменения: ";
            cin >> idx;
            keeper.Edit(idx - 1);
            break;
        }
        case 5:
            keeper.SaveToFile("submarines.dat");
            break;
        case 6:
            keeper.LoadFromFile("submarines.dat");
            break;
        case 0:
            cout << "Выход из программы...\n";
            return 0;
        default:
            cout << "Неверный выбор!\n";
        }
    }
}
