#pragma once

#include "../automaton/automaton.hpp"
#include "./generator.hpp"
#include "../solver/solver.hpp"

using namespace std;

class SimpleGenerator: public Generator {
public:
	SimpleGenerator(int n, int m, Solver* solver) : Generator(n, m, solver) {}

	void generate() {
		long long count = (long long)pow(n, m * n);
		for (long long i = 0; i < count; i++) {
			solver->add(Automaton(n, m, i));
		}
	}
};