#include <iostream>
#include "Address.h"

using namespace std;

Address::Address() {
	this->_number = this->_street = this->_ward = this->_district = "";
	this->_city = "Ho Chi Minh City";
}

Address::Address(string number, string street, string ward, string district, string city) {
	this->_number = number;
	this->_street = street;
	this->_ward = ward;
	this->_district = district;
	this->_city = city;
}

string Address::toString() {
	stringstream builder;
	
	builder << this->_number << this->_street << "Street, " << this->_ward << ", "
		<< this->_district << ", " << this->_city;
	string result = builder.str();
	return result;
}