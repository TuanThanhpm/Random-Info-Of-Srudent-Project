#pragma once

#include "Object.h"

using namespace std;

class Fullname: public Object {
private:
	string _firstName;
	string _middleName;
	string _lastName;

public:
	Fullname() { this->_firstName = this->_middleName = this->_lastName = ""; }
	Fullname(string, string, string);

public:
	string getFirstName() { return this->_firstName; }
	string getMiddleName() { return this->_middleName; }
	string getLastName() { return this->_lastName; }
	void setFirstName(string str) { this->_firstName = str; }
	void setMiddleName(string str) { this->_middleName = str; }
	void setLastName(string str) { this->_lastName = str; }

public:
	string toString();

};

