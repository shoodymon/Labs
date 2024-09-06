#include "class.h"

void Time::validateTime() {
    if (m_hours < 0 || m_hours > 23) m_hours = 0;
    if (m_minutes < 0 || m_minutes > 59) m_minutes = 0;
    if (m_seconds < 0 || m_seconds > 59) m_seconds = 0;
}

void Time::setTime(int h, int m, int s) {
    m_hours = h;
    m_minutes = m;
    m_seconds = s;
    validateTime();
}

int Time::getHours() {
    return m_hours;
}

int Time::getMinutes() {
    return m_minutes;
}

int Time::getSeconds() {
    return m_seconds;
}

void Time::printFormat1() {
    std::cout << m_hours << " часов " << m_minutes << " минут " << m_seconds << " секунд " << std::endl;
}

void Time::printFormat2() {
    int h = m_hours % 12;
    if (h == 0) h = 12;
    std::cout << h << ":" << std::setfill('0') << std::setw(2) << m_minutes << ":"
        << std::setw(2) << m_seconds << " " << (m_hours < 12 ? "a.m." : "p.m.") << std::endl;
}