#include <iostream>
#include "Fullname.h"

using namespace std;

Fullname::Fullname(string first, string middle, string last) {
	this->_firstName = first;
	this->_middleName = middle;
	this->_lastName = last;
}

std::string Fullname::toString() {
	stringstream builder;

	builder << getFirstName() << " " << getMiddleName() << " " << getLastName();
	string result = builder.str();
	return result;
}
