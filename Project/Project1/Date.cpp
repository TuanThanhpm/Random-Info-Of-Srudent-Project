
#include <iostream>
#include "Date.h"
#include "Utils.h"

using namespace std;

Date::Date() {
    time_t info = time(NULL);
    tm now;
    localtime_s(&now, &info);

    _year = now.tm_year + 1900;
    _month = now.tm_mon + 1;
    _day = now.tm_mday;
}

Date::Date(int day, int month, int year) {
    this->_day = day;
    this->_month = month;
    this->_year = year;
}

Date Date::parse(string date) {
    Date d;
    int day, month, year;
    day = month = year = 0;
    if (isValid(date)) {
        vector<string> v = Utils::String::split(date, "/");
        day = stoi(v[0]);
        month = stoi(v[1]);
        year = stoi(v[2]);
        d = Date(day, month, year);
    }
    return d;
}

string Date::toString() {
    stringstream builder;

    builder << setw(2) << setfill('0') << this->_day << "/"
        << setw(2) << setfill('0') << this->_month << "/" << this->_year;

    string result = builder.str();
    return result;
}

bool Date::isValid(string date) {
    if (date.length() == 0) {
        return false;
    }
    vector<string> v = Utils::String::split(date, "/");
    int day = stoi(v[0]);
    int month = stoi(v[1]);
    int year = stoi(v[2]);

    if (year > MAX_VALID_YR || year < MIN_VALID_YR)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    if (month == 2)
    {
        if (isLeapYear(year))
            return (day <= 29);
        else
            return (day <= 28);
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);

    return true;
}

bool Date::isLeapYear(int year) {
    bool result = (year % 400) ||
        ((year % 4 == 0) && (year % 100 != 0));
    return result;
}

