#include <iostream>
#include "ID.h"

using namespace std;

string ID::toString() {
	stringstream builder;

	builder << this->_format << this->_remaining;
	string result = builder.str();
	return result;
}