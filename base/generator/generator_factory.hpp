#pragma once

#include <string>
#include "./generator.hpp"
#include "./simple_generator.hpp"
#include "./smart_generator.hpp"

using namespace std;

class GeneratorFactory {
public:
	Generator* generate(string s, int n, int m, Solver* solver) {
		if (s == "simple")
			return new SimpleGenerator(n, m, solver);
		if (s == "smart")
			return new SmartGenerator(n, m, solver);
		throw "undefined";
	}
};