#include <stdio.h>
#include <string>

#include "./vendor/cmdline.h"
#include "./base/generator/simple_generator.hpp"
#include "./sync_game/solver/sync_solver.hpp"
#include "./sync_game/view/sync_view_factory.hpp"
#include "./base/constants.hpp"

#pragma comment(linker, "/STACK:32777216")

using namespace std;

cmdline::parser parse_args(int argc, const char * argv[]) {
	cmdline::parser a;

	a.add<int>("automaton", 'n', "automaton size", false, 4, cmdline::range(1, constants::max_automaton_size));
	a.add<int>("abc", 'm', "alphabet size", false, 2, cmdline::range(1, constants::max_automaton_size));
	a.add<string>("view", 'v', "output format", false, "full", cmdline::oneof<string>("full", "maximum", "statistics"));
	a.add<string>("solver", 's', "task solver", false, "sync_game", cmdline::oneof<string>("sync_game"));

	a.parse_check(argc, argv);
	return a;
}

int main(int argc, const char * argv[]) {
	cmdline::parser args = parse_args(argc, argv);

 	int n = args.get<int>("automaton"), m = args.get<int>("abc");
	Generator *generator = new SimpleGenerator(n, m);
	ViewFactory *view_factory = new SyncViewFactory();

	string view_type = args.get<string>("view");
	View *view = view_factory->generate(view_type);
	vector <Automaton> generated_array = generator->generate();

	view->begin();
	for (auto automaton : generated_array) {
		Solver *solver = new SyncSolver(automaton);
		view->add(solver->solve());
	}
	view->end();

	return 0;
}