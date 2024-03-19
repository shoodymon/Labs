#include <iostream>
#include "Deque.h"

int main() {
    setlocale(0, "");
    Deque deque;
    int choice;
    int value;
    int position;

    do {
        cout << "\n\t\tМеню:\n";
        cout << "\t---------------------------\n";
        cout << "\tДобавление:\n";
        cout << "\t1. В начало списка\n";
        cout << "\t2. В конец списка\n";
        cout << "\t3. В произвольное место\n";
        cout << "\tУдаление:\n";
        cout << "\t4. Из начала списка\n";
        cout << "\t5. Из конца списка\n";
        cout << "\t6. Из произвольного места списка\n";
        cout << "\tПрочее:\n";
        cout << "\t7. Очистка списка\n";
        cout << "\t8. Вывод списка\n";
        cout << "\t9. Выход\n";
        cout << "\n\tВаш выбор --> ";
        cin >> choice;

        switch (static_cast<Deque_operation>(choice)) {
        case Deque_operation::PUSH_FRONT:
            cout << "\tЗначение: ";
            cin >> value;
            deque.pushFront(value);
            break;
        case Deque_operation::PUSH_BACK:
            cout << "\tЗначение: ";
            cin >> value;
            deque.pushBack(value);
            break;
        case Deque_operation::INSERT:
            cout << "\tЗначение: ";
            cin >> value;
            cout << "\tПозиция: ";
            cin >> position;
            deque.insert(value, position);
            break;
        case Deque_operation::POP_FRONT:
            deque.popFront();
            break;
        case Deque_operation::POP_BACK:
            deque.popBack();
            break;
        case Deque_operation::ERASE:
            cout << "\tПозиция: ";
            cin >> position;
            deque.erase(position);
            break;
        case Deque_operation::CLEAR_DEQUE:
            deque.clear();
            break;
        case Deque_operation::PRINT_DEQUE:
            deque.print();
            break;
        case Deque_operation::EXIT:
            cout << "\n\tЗавершение..." << endl;
            break;
        default:
            cout << "\n\tНеправильный выбор! Попробуйте еще раз." << endl;
            break;
        }
    } while (static_cast<Deque_operation>(choice) != Deque_operation::EXIT);

    return 0;
}
