#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "AttributesEnum.h"
#include "FakeID.h"
#include "FakeFullname.h"
#include "FakeAddress.h"
#include "FakeVNTel.h"
#include "FakeEmail.h"
#include "FakeBirthday.h"
#include "FakeGPA.h"

using std::vector;
using std::unordered_map;
using std::swap;

#define numberOfStudent 30
#define numberOfAttribute 7



class Student {
private:
	vector<Student*> _list;
	ID _id;
	Fullname _fullname;
	Address _address;
	VNTel _tel;
	Email _email;
	Date _dob;
	GPA _gpa;

public:
	vector<Student*> getList() { return this->_list; }
	auto getSize() { return this->_list.size(); }
	ID getID() { return this->_id; }
	Fullname getFullName() { return this->_fullname; }
	Address getAddress() { return this->_address; }
	VNTel getVNTel() { return this->_tel; }
	Email getEmail() { return this->_email; }
	Date getBirthday() { return this->_dob; }
	GPA getGPA() { return this->_gpa; }

	void setID(const ID& id) { this->_id = id; }
	void setFullName(const Fullname& fullname) { this->_fullname = fullname; }
	void setAddress(const Address& address) { this->_address = address; }
	void setVNTel(const VNTel& tel) { this->_tel = tel; }
	void setEmail(const Email& email) { this->_email = email; }
	void setBirthday(const Date& dob) { this->_dob = dob; }
	void setGPA(const GPA& gpa) { this->_gpa = gpa; }

public:
	void initList();
	void sortList();

};