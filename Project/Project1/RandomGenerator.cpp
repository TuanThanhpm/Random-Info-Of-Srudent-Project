#include <iostream>
#include "RandomGenerator.h"
using namespace std;

RandomGenerator::RandomGenerator()
{
    srand(time(NULL));
}

RandomGenerator::~RandomGenerator() {}

/// <summary>
/// Trả ra số nguyên ngẫu nhiên
/// </summary>
/// <returns>Số nguyên miền giá trị [0, 65535]</returns>
int RandomGenerator::next() {
    int result = rand();
    return result;
}

/// <summary>
/// Sinh số nguyên ngẫu nhiên
/// </summary>
/// <param name="max">Giá trị tối đa</param>
/// <returns>Số nguyên trong đoạn [0, max)</returns>
int RandomGenerator::next(int max) {
    int result = rand() % max;
    return result;
}

/// <summary>
/// Sinh số nguyên ngẫu nhiên
/// </summary>
/// <param name="left">Biên trái</param>
/// <param name="right">Biên phải</param>
/// <returns>Số nguyên trong đoạn [left, right]</returns>
int RandomGenerator::next(int left, int right) {
    int result = rand() % (right - left + 1) + left;
    return result;
}

