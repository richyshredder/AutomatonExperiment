#pragma once

#include <string>

#include "../../base/solver/solver.hpp"
#include "./sync_result.hpp"
#include "./sync_graph.hpp"
#include "./sync_search.hpp"
#include "../view/sync_view_factory.hpp"

using namespace std;

class SyncSolver : public Solver {
protected:
	SyncView* view;
	SyncResult solve(Automaton a) {
		SyncGraph g(a);
		SyncSearch s(g);
		bool result = s.search();
		string answer = s.find_answer();
		SyncResult r(a, answer, result);
		return r;
	}
public:
	SyncSolver(string type) : Solver(type) {
		SyncViewFactory *view_factory = new SyncViewFactory();
		view = view_factory->generate(type);
	}
	
	void add(Automaton a) {
		view->add(solve(a));
	}

	void begin() {
		view->begin();
	}

	void end() {
		view->end();
	}

};