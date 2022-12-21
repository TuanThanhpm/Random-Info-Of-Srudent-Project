#include <iostream>
#include "FakeAddress.h"
#include "RandomGenerator.h"
#include "Utils.h"

using namespace std;
/// <summary>
/// randomly generate address
/// </summary>
/// <returns>Address type value</returns>
Address FakeAddress::next() {
	unordered_map <string, vector<vector<string>>> mp = Utils::File::readAddress("Address.txt");
	vector<string> districtArr;
	for (auto& it : mp) {
		districtArr.push_back(it.first);
	}

	auto rng = RandomGenerator::instance();
	string number = Utils::String::convertNumberToString(rng->next(100));

	string district = districtArr[rng->next(3)];
	vector<vector<string>> v = mp[district];

	int i = rng->next(0, 4);
	int j = rng->next(1, 4);
	string street = v[i][j];
	string ward = v[i][0];

	Address address;
	address.setNumber(number);
	address.setStreet(street);
	address.setWard(ward);
	address.setDistrict(district);

	return address;

}