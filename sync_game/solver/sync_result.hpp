#pragma once

#include <string>

#include "../../base/automaton/automaton.hpp"

using namespace std;

class SyncResult {
public:
	Automaton a;
	string s;
	bool result;
	SyncResult(Automaton a, string s, bool f) : a(a), s(s), result(f) {}
};