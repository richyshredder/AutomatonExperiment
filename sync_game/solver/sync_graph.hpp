#pragma once

#include <vector>

#include "../../base/automaton/automaton.hpp"
#include "../../base/constants.hpp"

using namespace std;

class SyncGraph {
private:
	Automaton a;
	vector <pair<int, int>> n[(1 << constants::max_automaton_size)], p[(1 << constants::max_automaton_size)];
	int graph_size;
public:
	SyncGraph(Automaton a) : a(a) {
		int ar[constants::max_automaton_size][constants::max_automaton_size];
		long long current = a.index();
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < a.abc_size(); j++) {
				ar[i][j] = current % a.size();
				current /= a.size();
			}
		}

		graph_size = 1 << a.size();
		for (int i = 0; i < graph_size; i++) {
			for (int j = 0; j < a.abc_size(); j++) {
				int next = 0;
				for (int k = 0; k < a.size(); k++)
					if (i & (1 << k)) {
						next |= 1 << ar[k][j];
					}
				p[next].push_back(make_pair(i, j));
				n[i].push_back(make_pair(next, j));
			}
		}
	}

	inline vector<pair<int, int>> next(int q) {
		return n[q];
	}

	inline vector<pair<int, int>> prev(int q) {
		return p[q];
	}

	inline Automaton automaton() {
		return a;
	}

	inline int size() {
		return graph_size;
	}
};