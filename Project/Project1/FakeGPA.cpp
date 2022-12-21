#include "FakeGPA.h"
#include <iostream>
#include "RandomGenerator.h"
#include "Utils.h"

using namespace std;

/// <summary>
/// randomly generate GPA
/// </summary>
/// <returns>GPA type value</returns>
GPA FakeGPA::next() {
	auto rng = RandomGenerator::instance();

	int natural = rng->next(4, 9);
	int decimal = rng->next(0, 9);

	GPA gpa;
	gpa.setNatural(natural);
	gpa.setDecimal(decimal);
	return gpa;
}