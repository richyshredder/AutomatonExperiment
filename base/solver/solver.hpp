#pragma once

#include "../automaton/automaton.hpp"
#include "../view/view.hpp"
#include "./result.hpp"

class Solver {
protected:
	View* view;
	virtual Result solve(Automaton a) = 0;
public:
	virtual void add(Automaton a) = 0;
	Solver(string type) {}

	void begin() {
		view->begin();
	}

	void end() {
		view->end();
	}
};