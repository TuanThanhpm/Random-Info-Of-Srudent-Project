#pragma once

#include "Object.h"

using namespace std;

class Email: public Object {
private:
	string _format;
	string _domain;

public:
	Email() { this->_format = this->_domain = ""; }
	Email(string format, string domain) { this->_format = format; this->_domain = domain; }

public:
	string getFormat() { return this->_format; }
	string getDomain() { return this->_domain; }
	void setFormat(string format) { this->_format = format; }
	void setDomain(string domain) { this->_domain = domain; }

public:
	string toString();
};

