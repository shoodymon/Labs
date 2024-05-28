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
        std::cout << "\n\t�������� ������ �������: :)\n";
        std::cout << "1) ������� 1\n";
        std::cout << "2) ������� 2\n";
        std::cout << "3) ������� 3\n";
        std::cout << "4) ������� 4\n";
        std::cout << "5) ������� 5\n";
        std::cout << "6) ������� 6\n";
        std::cout << "7) �����\n";
        std::cout << "\t��� ����� --> ";
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
    std::cout << "������! �������� �����. ���������� ��� ���." << std::endl;
}

void UserInterface::exit() {
    std::string message = "���������� ������...";
    std::cout << message << std::endl;
    flag = false;
}

template <typename T>
T UserInterface::input(const std::string& request) {
    T value{};
    std::cout << request;
    std::cin >> value;
    return value;
}

template <typename T>
void UserInterface::input(const std::string& request, T& variable) {
    std::cout << request;
    std::cin >> variable;
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
                throw std::out_of_range("�������� ��� ���������");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "������: " << e.what() << ". ���������� ��� ���." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

std::vector<int> UserInterface::input(const std::string& request, int size) {
    std::vector<int> arr(size);
    std::cout << request << "[" << size << "]: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}

void UserInterface::input(const std::string& request, std::vector<int>& arr) {
    std::cout << request << "[" << arr.size() << "]: ";
    for (int i = 0; i < arr.size(); ++i) {
        std::cin >> arr[i];
    }
}

double UserInterface::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("������� �� ����");
    }
    return a / b;
}

double UserInterface::divideWithException(double a, double b) {
    double result;
    try {
        result = divide(a, b);
    }
    catch (const std::exception& e) {
        // std::cerr << "������1: " << e.what() << std::endl;
        throw; // ����������� ���������� ������ ��� ������ ���������
    }
    return result;
}

double UserInterface::sqrt(double x) {
    if (x < 0) {
        throw std::domain_error("������������� ������");
    }
    return std::sqrt(x);
}

double UserInterface::sqrtWithException(double x) {
    try {
        return sqrt(x);
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
        return 0;
    }
}

int UserInterface::stringToInt(const std::string& str) {
    int value{ 0 };
    int sign{ 1 };
    size_t i{ 0 };
     
    if (str.empty()) { 
        throw std::invalid_argument("������ ������ �� ����� ���� ������������� � �����"); 
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
            throw std::invalid_argument("�������� ������ ������: ������ �������� ������������ �������"); 
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
        std::cerr << "\n������: " << e.what() << std::endl;
        return 0;  // ���������� �������� �� ��������� � ������ ������
    }
}

void UserInterface::task1() {
    int a = input<int>("������� a: ");
    std::cout << "��������� �������� a: " << a << std::endl;

    double b;
    input("������� b: ", b);
    std::cout << "��������� �������� b: " << b << std::endl;
}

void UserInterface::task2() {
    int c = input<int>("������� c [0;5]: ", 0, 5);
    std::cout << "��������� �������� c: " << c << std::endl;
}

void UserInterface::task3() {
    std::vector<int> arr = input("������� ������ : ", 5);
    std::cout << "��������� ������ : ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void UserInterface::task4() {
    double x = input<double>("������� x: ");
    double y = input<double>("������� y: ");
    try {
        double result = divideWithException(x, y);
        std::cout << "��������� ������� " << x << " �� " << y << ": " << result << std::endl;
    }
    catch (const std::exception& e) {
        // ��������� ���������� �����
        std::cerr << "������: " << e.what() << std::endl;
    }
}

void UserInterface::task5() {
    double z = input<double>("������� z: ");
    double sqrtResult = sqrtWithException(z);
    if (z >= 0) {
        std::cout << "���������� ������ �� " << z << ": " << sqrtResult << std::endl;
    }
    else {
        std::cout << "���������� ������ �� ����� ���� �������� ��� �������������� �����: " << z << std::endl;
    }
}

void UserInterface::task6() {
    std::string strValue = input<std::string>("������� ������ ��� �������������� � �����: ");
    int intValue = stringToIntWithException(strValue);
    if (intValue != 0 || (intValue == 0 && strValue == "0")) {  
        std::cout << "��������� �������������� ������ '" << strValue << "' � �����: " << intValue << std::endl;
    }
    else {
        std::cout << "�������� ��������� ������: ������ '" << strValue << "' �� ����� ���� ������������� � �����" << std::endl;
    }
}
