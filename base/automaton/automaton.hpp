#pragma once

#include "../constants.hpp"

class Automaton {
private:
	int n, m;
	long long id;
	int a[constants::max_automaton_size][constants::max_automaton_size];
public:
	Automaton(int n, int m, long long id) : n(n), m(m), id(id) {
		long long current = id;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = current % n;
				current /= n;
			}
		}
	}

	inline int size() {
		return n;
	}

	inline int abc_size() {
		return m;
	}

	inline long long index() {
		return id;
	}

	inline int get(int x, int y) {
		return a[x][y];
	}
};