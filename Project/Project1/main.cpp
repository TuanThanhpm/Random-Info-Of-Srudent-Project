#include <iostream>
#include "Table.h"
#include <algorithm>

using namespace std;

int main() {
	Utils::Console::loading();
	shared_ptr<Student> student = make_shared<Student>();
	student->initList();

	vector <string> headers = { "STT", "ID", "FULLNAME", "ADDRESS", "EMAIL", "VNTEL", "BIRTHDAY", "GPA" };
	vector<int> widths = Utils::Array::maxLengthOfAttribute(student);
	widths.insert(widths.begin(), 3);
	vector<Student*> data = student->getList();
	IValueConverter* converter = new StudentToRowConverter();

	Table table(headers, widths, data, converter);
	table.writeFile("mockData.txt");
	delete converter;
	return 0;
}