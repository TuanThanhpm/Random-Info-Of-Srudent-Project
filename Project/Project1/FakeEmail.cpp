#include <iostream>
#include "FakeEmail.h"
#include "RandomGenerator.h"
#include "Utils.h"
#include <algorithm> 

using namespace std;
/// <summary>
/// randomly generate email which bases on fullname
/// </summary>
/// <param name="fn">fullname</param>
/// <returns>type of value is Email</returns>
Email FakeEmail::next(string fn) {
	auto rng = RandomGenerator::instance();

	vector<string> companyDomain = Utils::File::readFile("companyDomain.txt");
	
	int index = rng->next(static_cast<int>(companyDomain.size()));
	string domain = companyDomain[index];

	vector<string> v = Utils::String::split(fn, " ");
	
	size_t last = v.size() - 1;
	auto format = std::string(1, v[0][0]);
	for (int i = 1; i < last; i++) {
		format += v[i][0];
	}
	format = format.append(v[last]);
	//transform string to lower string
	transform(format.begin(), format.end(), format.begin(), ::tolower);

	Email email;
	email.setDomain(domain);
	email.setFormat(format);
	return email;
}
