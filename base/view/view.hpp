#pragma once

#include <vector>
#include <string>

#include "../solver/result.hpp"

using namespace std;

class View {
protected:
	vector <Result> a;
public:
	void add(Result r) {
		a.push_back(r);
	}

	virtual void maximum() = 0;
	virtual void full() = 0;
	virtual void statistics() = 0;

	void show(string s) {
		if (s == "full")
			full();
		else if (s == "maximum")
			maximum();
		else if (s == "statistics")
			statistics();
	}
};