#pragma once

#include <vector>

#include "../automaton/automaton.hpp"

using namespace std;

class Generator {
protected:
	int n, m;
	vector<Automaton> list;
public:
	Generator(int n, int m) : n(n), m(m) {}
	virtual vector<Automaton> generate() = 0;
};