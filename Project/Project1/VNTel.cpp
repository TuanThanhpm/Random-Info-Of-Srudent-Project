#include <iostream>
#include "VNTel.h"

using namespace std;

string VNTel::toString() {
	stringstream builder;
	
	builder << this->_format << this->_remaining;
	string result = builder.str();
	return result;
}