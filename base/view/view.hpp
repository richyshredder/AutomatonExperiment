#pragma once

#include "../solver/result.hpp"

using namespace std;

class View {
public:
	virtual void add(Result r) = 0;
	virtual void begin() = 0;
	virtual void end() = 0;
};