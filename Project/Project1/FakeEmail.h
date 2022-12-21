#pragma once
#include "Email.h"

class FakeEmail {
public:
	static Email next(std::string fn);
};