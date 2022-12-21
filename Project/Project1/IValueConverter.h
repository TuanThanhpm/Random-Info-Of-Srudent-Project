#pragma once
#include "Object.h"
#include "Student.h"
#include <vector>

using std::vector;

class IValueConverter : public Object {
public:
	virtual string convert(Student*, vector<int>) = 0;
};