#include "Student.h"

/// <summary>
/// Initialize list of all attributes of 30 student
/// </summary>
void Student::initList() {
	auto rng = RandomGenerator::instance();
	unordered_map<string, bool> mp_id, mp_name, mp_address, mp_tel, mp_email;

	int currentYear = Date::Now().getYear() - 18;
	for (int i = 0; i < numberOfStudent; i++) {
		Student* student = new Student;
		student->_id = FakeID::next();
		student->_fullname = FakeName::next();
		student->_address = FakeAddress::next();
		student->_tel = FakeVNTel::next();
		student->_email = FakeEmail::next(student->_fullname.toString());
		student->_dob = FakeBirthday::next(currentYear);
		student->_gpa = FakeGPA::next();
		string id = student->_id.toString();
		string fullname = student->_fullname.toString();
		string address = student->_address.toString();
		string tel = student->_tel.toString();
		string email = student->_email.toString();
		string dob = student->_dob.toString();
		string gpa = student->_gpa.toString();

		if (mp_id[id] == false && mp_name[fullname] == false && mp_address[address] == false
			&& mp_tel[tel] == false && mp_email[email] == false)
		{
			mp_id[id] = mp_name[fullname] = mp_address[address] = mp_tel[tel] = mp_email[email] = true;
			this->_list.push_back(student);
		}
		else {
			i--;
		}
	}

	sortList();
}

/// <summary>
/// Sort list based on fullname except id.
/// Sort ID ascending then assigning again into list
/// </summary>
void Student::sortList() {
	auto size = this->_list.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (_list[i]->_fullname.getLastName() > _list[j]->_fullname.getLastName()) {
				swap(_list[i], _list[j]);
			}
			else if (_list[i]->_fullname.getLastName() == _list[j]->_fullname.getLastName()) {
				if (_list[i]->_fullname.getFirstName() > _list[j]->_fullname.getFirstName()) {
					swap(_list[i], _list[j]);
				}
			}
		}
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			int ID = stoi(_list[i]->_id.toString());
			int _ID = stoi(_list[j]->_id.toString());
			if (ID > _ID)
				swap(_list[i]->_id, _list[j]->_id);
		}
	}

}
