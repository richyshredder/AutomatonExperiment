#include <stdio.h>
#include <string>

#include "vendor/cmdline.h"
#include "base/generator/simple_generator.hpp"
#include "sync_game/solver/sync_solver.hpp"
#include "sync_game/view/sync_view.hpp"

#pragma comment(linker, "/STACK:32777216")

using namespace std;

cmdline::parser parse_args(int argc, const char * argv[]) {
	cmdline::parser a;

	a.add<int>("automaton", 'n', "automaton size", false, 4, cmdline::range(1, 10));
	a.add<int>("abc", 'm', "alphabet size", false, 2, cmdline::range(1, 10));
	a.add<string>("view", 'v', "output format", false, "full", cmdline::oneof<string>("full", "maximum", "statistics"));
	a.add<string>("solver", 's', "task solver", false, "sync_game", cmdline::oneof<string>("sync_game"));

	a.parse_check(argc, argv);
	return a;
}

int main(int argc, const char * argv[]) {
	cmdline::parser args = parse_args(argc, argv);

 	//int n = args.get<int>("automaton"), m = args.get<int>("abc");
	int n = 5, m = 2;
	Generator *generator = new SimpleGenerator(n, m);
	View *view = new SyncView();

	vector <Automaton> generated_array = generator->generate();
	for (auto automaton : generated_array) {
		Solver *solver = new SyncSolver(automaton);
		view->add(solver->solve());
	}
	view->show(args.get<string>("view"));

	return 0;
}