#include <iostream>
#include "Node.h"
#include "Stack.h"


int main() {
    setlocale(0, "");
    Stack stk;
    int choice;
    int value;

    do {
        cout << "\n\t\tМеню:\n";
        cout << "\t1. Добавление значения в вершину\n";
        cout << "\t2. Удаление значения из вершины\n";
        cout << "\t3. Удаление всех данных\n";
        cout << "\t4. Вывод всего списка\n";
        cout << "\t5. Выход\n";
        cout << "\n\tВаш выбор --> ";
        cin >> choice;

        switch (static_cast<Stack_operation>(choice)) {
        case Stack_operation::ADD_VALUE:
            cout << "\tВведите значение для добавления: ";
            cin >> value;
            stk.push(value);
            break;
        case Stack_operation::REMOVE_VALUE:
            if (!stk.isEmpty())
                stk.pop();
            else { cout << "\n\tСтек пуст!" << endl; }
            break;
        case Stack_operation::CLEAR_STACK:
            while (!stk.isEmpty())
                stk.pop();
            break;
        case Stack_operation::PRINT_STACK:
            if (!stk.isEmpty())
                stk.print();
            else { cout << "\n\tСтек пуст!" << endl; }
            break;
        case Stack_operation::EXIT:
            cout << "\n\tВыход..." << endl;
            break;
        default:
            cout << "\n\tНеверный выбор! Попробуйте еще раз." << endl;
            break;
        }
    } while (static_cast<Stack_operation>(choice) != Stack_operation::EXIT);

    return 0;
}
