#pragma once

#include "../constants.hpp"

class Automaton {
private:
	int a[constants::max_automaton_size][50];
	int n, m, id;
public:
	Automaton(int n, int m, int id) : n(n), m(m), id(id) {
		int current = id;
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

	inline int index() {
		return id;
	}

	inline int get(int x, int y) {
		return a[x][y];
	}
};