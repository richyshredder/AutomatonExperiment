#pragma once

#include "../automaton/automaton.hpp"
#include "./generator.hpp"
#include "../solver/solver.hpp"

using namespace std;

class SmartGenerator : public Generator {
private:
	long long n_pows[constants::max_automaton_size * constants::max_automaton_size];

	void search(int cur_n, int cur_m, int cur_max, long long current_ans) {
		if (cur_n == n) {
			solver->add(Automaton(n, m, current_ans));
			return;
		}
		if (cur_m == m) {
			search(cur_n + 1, 0, cur_max, current_ans);
			return;
		}
		for (int i = 0; i < cur_max && i < n; i++)
			search(cur_n, cur_m + 1, max(cur_max, i + 2), current_ans + n_pows[cur_n * m + cur_m] * i);
	}

public:
	SmartGenerator(int n, int m, Solver* solver) : Generator(n, m, solver) {
		n_pows[0] = 1;
		for (int i = 1; i <= n * m; i++) {
			n_pows[i] = n_pows[i - 1] * n;
		}
	}

	void generate() {
		search(0, 0, 2, 0);
	}
};