#include <iostream>
#include "FakeFullname.h"
#include "RandomGenerator.h"
#include "Utils.h"

using namespace std;

/// <summary>
/// randomly generate fullname
/// </summary>
/// <returns>type of value is Fullname</returns>
Fullname FakeName::next() {
	vector<string> firstNameArr = Utils::File::readFile("firstName.txt");
	vector<string> middleNameArr = Utils::File::readFile("middleName.txt");
	vector<string> lastNameArr = Utils::File::readFile("lastName.txt");

	auto rng = RandomGenerator::instance();

	string firstName = firstNameArr[rng->next(static_cast<int>(firstNameArr.size()))];
	string middleName = middleNameArr[rng->next(static_cast<int>(middleNameArr.size()))];
	string lastName = lastNameArr[rng->next(static_cast<int>(lastNameArr.size()))];

	Fullname fn;
	fn.setFirstName(firstName);
	fn.setMiddleName(middleName);
	fn.setLastName(lastName);

	return fn;
}