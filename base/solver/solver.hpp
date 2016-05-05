#pragma once

#include "../automaton/automaton.hpp"
#include "./result.hpp"

class Solver {
protected:
	Automaton a;
public:
	Solver(Automaton a) : a(a) {}
	virtual Result solve() = 0;
};