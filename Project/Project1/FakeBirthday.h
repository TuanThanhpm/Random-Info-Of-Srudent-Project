#pragma once

#include "Date.h"

class FakeBirthday {
public:
	static Date next();
	static Date next(int year);
};