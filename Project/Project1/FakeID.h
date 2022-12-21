#pragma once
#include "ID.h"

class FakeID :public ID {
public:
	static ID next();
};