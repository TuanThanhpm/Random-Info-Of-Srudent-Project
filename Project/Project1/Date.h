#pragma once

#include "Object.h"
#include <iomanip>
#include <ctime>

#define MAX_VALID_YR  2023
#define MIN_VALID_YR  1910

class Date: public Object {
public:
    Date();
    Date(int, int, int);
    static Date Now() { return Date(); }

public:
    int getYear() { return _year; }
    int getMonth() { return _month; }
    int getDay() { return _day; }
    void setYear(int year) { this->_year = year; }
    void setMonth(int month) { this->_month = month; }
    void setDay(int day) { this->_day = day; }

public:
    Date parse(std::string);
    std::string toString();
    bool isValid(std::string);
    static bool isLeapYear(int year);
    

private:
    int _day;
    int _month;
    int _year;
};