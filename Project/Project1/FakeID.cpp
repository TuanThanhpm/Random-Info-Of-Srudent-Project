#include <iostream>
#include "FakeID.h"
#include "RandomGenerator.h"

using namespace std;

/// <summary>
/// randomly generate ID
/// </summary>
/// <returns>ID type value</returns>
ID FakeID::next() {
	auto rng = RandomGenerator::instance();

	stringstream builder;
	for (int i = 0; i < 3; i++) {
		int num = rng->next(10);
		builder << num;
	}
	string remaining = builder.str();

	ID id;
	id.setRemaining(remaining);
	return id;
}