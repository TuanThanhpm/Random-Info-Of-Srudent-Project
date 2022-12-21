#pragma once

#include "Object.h"

using namespace std;

class VNTel: public Object {
private:
	string _format;
	string _remaining;

public:
	VNTel() { this->_format = this->_remaining = ""; }
	VNTel(string format, string remaining) { this->_format = format; this->_remaining = remaining; }

public:
	string getFormat() { return this->_format; }
	string getRemaining() { return this->_remaining; }
	void setFormat(string format) { this->_format = format; }
	void setRemaining(string remaining) { this->_remaining = remaining; }

public:
	string toString();
};

