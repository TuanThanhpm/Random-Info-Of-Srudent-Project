#include <iostream>
#include "Email.h"

using namespace std;

string Email::toString() {
	stringstream builder;

	builder << this->_format << "@" << this->_domain;
	string result = builder.str();
	return result;
}