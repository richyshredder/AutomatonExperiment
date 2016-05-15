#include <stdio.h>
#include <string>

#include "./vendor/cmdline.h"
#include "./sync_game/solver/sync_solver.hpp"
#include "./base/generator/generator_factory.hpp"
#include "./sync_game/view/sync_view_factory.hpp"
#include "./base/constants.hpp"

#pragma comment(linker, "/STACK:64777216")

using namespace std;

cmdline::parser parse_args(int argc, const char * argv[]) {
	cmdline::parser a;

	a.add<int>("automaton", 'n', "automaton size", false, 4, cmdline::range(1, constants::max_automaton_size));
	a.add<int>("abc", 'm', "alphabet size", false, 2, cmdline::range(1, constants::max_automaton_size));
	a.add<string>("view", 'v', "output format", false, "full", cmdline::oneof<string>("full", "maximum", "statistics"));
	a.add<string>("generator", 'g', "generator", false, "smart", cmdline::oneof<string>("smart", "simple"));

	a.parse_check(argc, argv);
	return a;
}

int main(int argc, const char * argv[]) {
	cmdline::parser args = parse_args(argc, argv);
 	int n = args.get<int>("automaton"), m = args.get<int>("abc");
	string view_type = args.get<string>("view"), generator_type = args.get<string>("generator");
	//int n = 3, m = 2;
	//string view_type = "statistics", generator_type = "smart";

	Solver* solver = new SyncSolver(view_type);
	GeneratorFactory* generator_factory = new GeneratorFactory();
	Generator *generator = generator_factory->generate(generator_type, n, m, solver);

	solver->begin();
	generator->generate();
	solver->end();

	return 0;
}