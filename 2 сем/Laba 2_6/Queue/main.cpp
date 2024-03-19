#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

int main() {
    setlocale(0, "");
    Queue que;
    int choice;
    int value;

    do {
        cout << "\n\t\tМеню:\n";
        cout << "\t1. Добавление значения в конец очереди\n";
        cout << "\t2. Удаление значения из начала очереди\n";
        cout << "\t3. Удаление всех данных в очереди\n";
        cout << "\t4. Вывод всей очереди\n";
        cout << "\t5. Выход\n";
        cout << "\n\tВаш выбор --> ";
        cin >> choice;

        switch (static_cast<Queue_operation>(choice)) {
        case Queue_operation::ADD_VALUE:
            cout << "\tВведите значение для добавления: ";
            cin >> value;
            que.enqueue(value);
            break;
        case Queue_operation::REMOVE_VALUE:
            if (!que.isEmpty())
                que.dequeue();
            else { cout << "\n\tОчередь пуста!" << endl; }
            break;
        case Queue_operation::CLEAR_QUEUE:
            que.clear();
            break;
        case Queue_operation::PRINT_QUEUE:
            if (!que.isEmpty())
                que.print();
            else { cout << "\n\tОчередь пуста!" << endl; }
            break;
        case Queue_operation::EXIT:
            cout << "\n\tВыход..." << endl;
            break;
        default:
            cout << "\n\tНеверный выбор! Попробуйте еще раз." << endl;
            break;
        }
    } while (static_cast<Queue_operation>(choice) != Queue_operation::EXIT);

    return 0;
}
