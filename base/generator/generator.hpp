#pragma once

#include "../automaton/automaton.hpp"
#include "../solver/solver.hpp"

using namespace std;

class Generator {
protected:
	int n, m;
	Solver* solver;
public:
	Generator(int n, int m, Solver* solver) : n(n), m(m), solver(solver) {}
	virtual void generate() = 0;
};