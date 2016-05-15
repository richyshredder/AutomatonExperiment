#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "../../base/solver/result.hpp"
#include "../solver/sync_result.hpp"
#include "../../base/view/view.hpp"

using namespace std;

class SyncFullView : public View {
protected:
	bool first;
public:
	
	void begin() {
		printf("[\n");
		first = true;
	}
	
	void add(Result r) {
		if (!first)
			printf(",\n");
		else
			first = false;
		int result = r.get_int_attr("result");
		string optimal = r.get_string_attr("optimal");
		long long index = r.get_long_attr("index");

		if (result) {
			printf("{\"index\": %lld, \"win\": true, \"length\": %d, \"optimal\": \"", index, optimal.length());
			cout << optimal;
			printf("\"}");
		} else
			printf("{\"index\": %d, \"win\": false}", index);
	}
	
	void end() {
		printf("\n]");
	}
};