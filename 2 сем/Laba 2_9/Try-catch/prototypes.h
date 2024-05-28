#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <stdexcept>

class UserInterface {
public:
    UserInterface();
    void run();

private:
    enum class MAIN_MENU { TASK1 = 1, TASK2, TASK3, TASK4, TASK5, TASK6, EXIT };

    bool flag;

    void error();
    void exit();

    template <typename T>
    T input(const std::string& str);

    template <typename T>
    void input(const std::string& str, T& variable);

    template <typename T>
    T input(const std::string& request, T min, T max);

    std::vector<int> input(const std::string& request, std::vector<int>& arr);

    double divide(double a, double b);
    double divideWithException(double a, double b);
    double sqrt(double x);
    double sqrtWithException(double x);
    int stringToInt(const std::string& str);
    int stringToIntWithException(const std::string& str);

    void task1();
    void task2();
    void task3();
    void task4();
    void task5();
    void task6();
};