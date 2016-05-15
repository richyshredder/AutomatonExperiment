#pragma once

#include "../solver/result.hpp"
#include "../automaton/automaton.hpp"

using namespace std;

class View {
public:
	virtual void add(Result r) = 0;
	virtual void begin() = 0;
	virtual void end() = 0;
};