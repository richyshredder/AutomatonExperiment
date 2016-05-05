#pragma once

#include <string>

#include "../../base/solver/solver.hpp"
#include "./sync_result.hpp"
#include "./sync_graph.hpp"
#include "./sync_search.hpp"

using namespace std;

class SyncSolver : public Solver {
public:
	SyncSolver(Automaton a) : Solver(a) {}
	Result solve() {
		SyncGraph g(a);
		SyncSearch s(g);
		bool result = s.search();
		string answer = s.find_answer();
		SyncResult r(a, answer, result);
		return r;
	}
};