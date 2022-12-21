#include "GPA.h"
#include <iostream>

using namespace std;

string GPA::toString() {
	stringstream builder;

	builder << this->_natural << "." << this->_decimal;
	string result = builder.str();
	return result;

}