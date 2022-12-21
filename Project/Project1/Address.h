#pragma once

#include "Object.h"

#define numberOfWard 5
#define numberOfStreet 4

using namespace std;

class Address: public Object{
private:
	string _number;
	string _street;
	string _ward;
	string _district;
	string _city;
public:
	Address();
	Address(string, string, string, string, string);

public:
	string getNumber() { return this->_number; }
	string getStreet() { return this->_street; }
	string getWard() { return this->_ward; }
	string getDistrict() { return this->_district; }
	string getCity() { return this->_city; }
	void setNumber(string number) { this->_number = number; }
	void setStreet(string street) { this->_street = street; }
	void setWard(string ward) { this->_ward = ward; }
	void setDistrict(string district) { this->_district = district; }
	void setCity(string city) { this->_city = city; }

public:
	string toString();
};