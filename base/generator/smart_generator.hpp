#pragma once

#include "../automaton/automaton.hpp"
#include "./generator.hpp"
#include "../solver/solver.hpp"

using namespace std;

class SmartGenerator : public Generator {
private:
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
			search(cur_n, cur_m + 1, max(cur_max, i + 2), current_ans + (long long)pow(n, cur_n * m + cur_m) * i);
	}

public:
	SmartGenerator(int n, int m, Solver* solver) : Generator(n, m, solver) {}

	void generate() {
		search(0, 0, 2, 0);
	}
};