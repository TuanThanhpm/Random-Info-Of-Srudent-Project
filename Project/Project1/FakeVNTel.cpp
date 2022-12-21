#include <iostream>
#include "FakeVNTel.h"
#include "RandomGenerator.h"
#include "Utils.h"

using namespace std;

/// <summary>
/// randomly generate VN Telephone
/// </summary>
/// <returns>VNTel type value</returns>
VNTel FakeVNTel::next() {
	vector<string> numberOfNetwork = Utils::File::readFile("numberOfNetwork.txt");

	auto rng = RandomGenerator::instance();
	string format, remaining, tel;
	stringstream builder;

	format = numberOfNetwork[rng->next(static_cast<int>(numberOfNetwork.size()))];
	for (int i = 0; i < 7; i++) {
		int num = rng->next(0, 9);
		builder << num;
	}
	remaining = builder.str();

	VNTel v;
	v.setFormat(format);
	v.setRemaining(remaining);

	return v;
}
