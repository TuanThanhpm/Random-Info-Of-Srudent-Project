#pragma once

#include "Object.h"

using namespace std;

class ID: public Object {
private:
	string _format;
	string _remaining;

public:
	ID() { this->_format = "21127";	this->_remaining = ""; }
	ID(string format, string remaining) { this->_format = format; this->_remaining = remaining; }

public:
	string getFormat() { return this->_format; }
	string getRemaining() { return this->_remaining; }
	void setFormat(string format) { this->_format = format; }
	void setRemaining(string remaining) { this->_remaining = remaining; }

public:
	string toString();
};

