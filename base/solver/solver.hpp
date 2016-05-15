#pragma once

#include <string>
#include "../automaton/automaton.hpp"

using namespace std;

class Solver {
public:
	virtual void add(Automaton a) = 0;
	Solver(string type) {}

	virtual void begin() = 0;
	virtual void end() = 0;
};