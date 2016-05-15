#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "../../base/view/view.hpp"
#include "../../base/solver/result.hpp"
#include "../solver/sync_result.hpp"

using namespace std;

class SyncMaximumView : public View {
protected:
	bool first;
	string optimal;
	int index;
public:
	
	void begin() {
		first = true;
	}
	
	void add(Result r) {
		int result = r.get_int_attr("result");
		if (!result)
			return;

		string current = r.get_string_attr("optimal");
		if (result && (first || this->optimal.length() < current.length()))
		{
			this->optimal = current;
			this->index = r.get_int_attr("index");
		}
		
		first = false;
	}
	
	void end() {
		printf("{\"index\": %d, \"win\": true, \"length\": %d, \"optimal\": \"", index, optimal.length());
		cout << optimal;
		printf("\"}");
	}
};