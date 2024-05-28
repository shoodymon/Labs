#include "prototypes.h"
#include <Windows.h>

UserInterface::UserInterface() : flag(true) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
}

void UserInterface::run() {
    int choice = 0;

    do {
        std::cout << "\n\tВыберите нужное задание: :)\n";
        std::cout << "1) Задание 1\n";
        std::cout << "2) Задание 2\n";
        std::cout << "3) Задание 3\n";
        std::cout << "4) Задание 4\n";
        std::cout << "5) Задание 5\n";
        std::cout << "6) Задание 6\n";
        std::cout << "7) Выход\n";
        std::cout << "\tВаш выбор --> ";
        std::cin >> choice;
        std::cout << '\n' << '\n';

        switch (static_cast<MAIN_MENU>(choice)) {
        case MAIN_MENU::TASK1:
            task1();
            break;
        case MAIN_MENU::TASK2:
            task2();
            break;
        case MAIN_MENU::TASK3:
            task3();
            break;
        case MAIN_MENU::TASK4:
            task4();
            break;
        case MAIN_MENU::TASK5:
            task5();
            break;
        case MAIN_MENU::TASK6:
            task6();
            break;
        case MAIN_MENU::EXIT:
            exit();
            break;
        default:
            error();
        }
    } while (flag);
}

void UserInterface::error() {
    std::cout << "Ошибка! Неверный выбор. Попробуйте еще раз." << std::endl;
}

void UserInterface::exit() {
    std::string message = "Завершение работы...";
    std::cout << message << std::endl;
    flag = false;
}

template <typename T>
T UserInterface::input(const std::string& str) {
    T value;
    std::cout << str;
    std::cin >> value;
    return value;
}

template <typename T>
void UserInterface::input(const std::string& str, T& variable) {
    std::cout << str;
    std::string input_str;
    std::getline(std::cin, input_str);

    try {
        std::stringstream ss(input_str);
        ss >> variable;

        // Проверка на полное извлечение из строки
        if (ss.rdbuf()->in_avail() != 0) {
            throw std::invalid_argument("Некорректный ввод.");
        }
    }
    catch (const std::exception& e) {
        // Ввод не является числом
        std::cout << e.what() << " Введите число." << std::endl;
        variable = T(); // Присвоить значение по умолчанию для типа T
    }
}

template <typename T>
T UserInterface::input(const std::string& request, T min, T max) {
    T value{};
    while (true) {
        try {
            std::cout << request;
            std::cin >> value;
            if (value >= min && value < max) {
                return value;
            }
            else {
                throw std::out_of_range("Значение вне диапазона");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << ". Попробуйте еще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

std::vector<int> UserInterface::input(const std::string& request, std::vector<int>& arr) {
    std::string numbStr = "";
    std::cin.clear(); 
    std::cin.ignore();

    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << request;
        std::getline(std::cin, numbStr);

        try {
            double numb = std::stod(numbStr);
            int result = static_cast<int>(numb);

            if (result != numb) {
                std::cout << "Число " << numb << " было преобразовано в " << result << "\n\n";
            }

            arr.at(i) = result;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Некорректное значение: строка не может быть преобразована в число\n";
            i--; // Возвращаемся к текущему индексу
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Число выходит за пределы допустимого диапазона\n";
            i--; // Возвращаемся к текущему индексу
        }
    }

    return arr;
}

double UserInterface::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Деление на ноль");
    }
    return a / b;
}

double UserInterface::divideWithException(double a, double b) {
    double result;
    try {
        result = divide(a, b);
    }
    catch (const std::exception& e) {
        // std::cerr << "Ошибка1: " << e.what() << std::endl;
        throw; // Выбрасываем исключение дальше без вывода сообщения
    }
    return result;
}

double UserInterface::sqrt(double x) {
    if (x < 0) {
        throw std::domain_error("Отрицательный корень");
    }
    return std::sqrt(x);
}

double UserInterface::sqrtWithException(double x) {
    try {
        return sqrt(x);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 0;
    }
}

int UserInterface::stringToInt(const std::string& str) {
    int value{ 0 };
    int sign{ 1 };
    size_t i{ 0 };
     
    if (str.empty()) { 
        throw std::invalid_argument("Пустая строка не может быть преобразована в число"); 
    }

    if (str[0] == '-') { 
        sign = -1; 
        i = 1; 
    }
    else if (str[0] == '+') { 
        i = 1; 
    }

    for (; i < str.length(); ++i) { 
        if (str[i] < '0' || str[i] > '9') { 
            throw std::invalid_argument("Неверный формат данных: строка содержит недопустимые символы"); 
        }
        value = value * 10 + (str[i] - '0'); 
    }

    return value * sign;
}

int UserInterface::stringToIntWithException(const std::string& str) {
    try {
        return stringToInt(str);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\nОшибка: " << e.what() << std::endl;
        return 0;  // Возвращаем значение по умолчанию в случае ошибки
    }
}

void UserInterface::task1() {
    int a = input<int>("Введите a: ");
    std::cout << "Введенное значение a: " << a << std::endl;

    double b = input<double>("Введите b: ");
    std::cout << "Введенное значение b: " << b << std::endl;

    std::string c = input<std::string>("Введите c: ");
    std::cout << "Введенное значение c: " << c << std::endl;

    std::string d = input<std::string>("Введите d: ");
    std::cout << "Введенное значение d: " << d << std::endl;
}

void UserInterface::task2() {
    int c = input<int>("Введите значение c в диапазоне [0;9]: ", 0, 10);
    std::cout << "Введенное значение c = " << c << std::endl;
}

void UserInterface::task3() {
    std::vector<int> arr(5);
    arr = input("Введите элемент массива (целочисленное число) --> ", arr);

    std::cout << "\tВаш массив из целых чисел: { ";
    for (size_t i = 0; i < arr.size() - 1; i++) {
        std::cout << arr.at(i) << ", ";
    }
    std::cout << arr.at(arr.size() - 1) << " }\n\n";
}

void UserInterface::task4() {
    double x = input<double>("Введите x: ");
    double y = input<double>("Введите y: ");
    try {
        double result = divideWithException(x, y);
        std::cout << "Результат деления " << x << " на " << y << ": " << result << std::endl;
    }
    catch (const std::exception& e) {
        // Обработка исключения здесь
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

void UserInterface::task5() {
    double z = input<double>("Введите z: ");
    double sqrtResult = sqrtWithException(z);
    if (z >= 0) {
        std::cout << "Квадратный корень из " << z << ": " << sqrtResult << std::endl;
    }
    else {
        std::cout << "Квадратный корень не может быть вычислен для отрицательного числа: " << z << std::endl;
    }
}

void UserInterface::task6() {
    std::string strValue = input<std::string>("Введите строку для преобразования в число: ");
    int intValue = stringToIntWithException(strValue);
    if (intValue != 0 || (intValue == 0 && strValue == "0")) {  
        std::cout << "Результат преобразования строки '" << strValue << "' в число: " << intValue << std::endl;
    }
    else {
        std::cout << "Конечная обработка ошибки: строка '" << strValue << "' не может быть преобразована в число" << std::endl;
    }
}
