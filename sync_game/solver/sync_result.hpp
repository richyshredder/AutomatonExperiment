#pragma once

#include <string>

#include "../../base/automaton/automaton.hpp"
#include "../../base/solver/result.hpp"

using namespace std;

class SyncResult : public Result {
protected:
	Automaton a;
public:
	SyncResult(Automaton a, string s, bool f) : a(a) {
		str_attr["optimal"] = s;
		long_attr["index"] = a.index();
		int_attr["result"] = f;
	}
};