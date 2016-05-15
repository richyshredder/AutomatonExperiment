#pragma once

#include "../constants.hpp"

class Automaton {
private:
	int n, m;
	long long id;
public:
	Automaton(int n, int m, long long id) : n(n), m(m), id(id) {}

	inline int size() {
		return n;
	}

	inline int abc_size() {
		return m;
	}

	inline long long index() {
		return id;
	}
};