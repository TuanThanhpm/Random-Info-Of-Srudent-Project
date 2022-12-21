#include "FakeBirthday.h"
#include "RandomGenerator.h"

using namespace std;

/// <summary>
/// randomly generate birthday(day, month) but this year is constant
/// </summary>
/// <param name="year">input value</param>
/// <returns>Date type value</returns>
Date FakeBirthday::next(int year) {
    auto rng = RandomGenerator::instance();
    int month = rng->next(1, 12);

    int maxDaysInMonth[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (Date::isLeapYear(year)) {
        maxDaysInMonth[2] = 29;
    }

    int day = rng->next(1, maxDaysInMonth[month]);

    Date result(day, month, year);
    return result;
}

/// <summary>
/// randomly generate birthday (day, month, year)
/// </summary>
/// <returns>Date type value</returns>
Date FakeBirthday::next() {
    const int MAX_AGE = 118;
    int currentYear = Date::Now().getYear();
    auto rng = RandomGenerator::instance();

    int year = min(1900 + (rng->next() % MAX_AGE), currentYear);

    Date result = next(year);
    return result;
}