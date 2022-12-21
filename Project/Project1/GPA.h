#pragma once
#include "Object.h"

using namespace std;

class GPA: public Object {
private:
	int _natural;
	int _decimal;

public:
	GPA() { this->_natural = this->_decimal = 0; }
	GPA(int natural, int decimal) { this->_natural = natural; this->_decimal = decimal; }

public:
	int getNatural() { return this->_natural; }
	int getDecimal() { return this->_decimal; }
	void setNatural(int natural) { this->_natural = natural; }
	void setDecimal(int decimal) { this->_decimal = decimal; }

public:
	string toString();
};