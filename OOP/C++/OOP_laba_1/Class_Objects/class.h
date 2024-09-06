#pragma once
#include "prototypes.h"

class Time {
private:
	int m_hours;
	int m_minutes;
	int m_seconds;

	void validateTime();

public:
	Time(int h = 0, int m = 0, int s = 0) : m_hours(h), m_minutes(m), m_seconds(s) {
		setlocale(0, "");
		validateTime();
	}

	~Time() {
		std::cout << "Объект Time уничтожен" << std::endl;
	}

	void setTime(int h, int m, int s);
	int getHours();
	int getMinutes();
	int getSeconds();
	void printFormat1();
	void printFormat2();
};