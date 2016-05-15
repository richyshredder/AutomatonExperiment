#pragma once

#include <vector>

#include "../automaton/automaton.hpp"
#include "./generator.hpp"

using namespace std;

class SimpleGenerator: public Generator {
public:
	SimpleGenerator(int n, int m) : Generator(n, m) {}
 	vector<Automaton> generate() {
		list.clear();
		int count = (int)pow(n, m * n);
		for (int i = 0; i < count; i++) {
			list.push_back(Automaton(n, m, i));
		}
		return list;
	}
};