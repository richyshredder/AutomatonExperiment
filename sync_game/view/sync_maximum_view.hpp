#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "./sync_view.hpp"
#include "../solver/sync_result.hpp"

using namespace std;

class SyncMaximumView : public SyncView {
protected:
	bool first;
	string optimal;
	long long index;
public:
	
	void begin() {
		first = true;
	}
	
	void add(SyncResult r) {
		bool result = r.result;
		if (!result)
			return;

		string current = r.s;
		if (result && (first || this->optimal.length() < current.length()))
		{
			this->optimal = current;
			this->index = r.a.index();
		}
		
		first = false;
	}
	
	void end() {
		printf("{\"index\": %lld, \"win\": true, \"length\": %d, \"optimal\": \"", index, optimal.length());
		cout << optimal;
		printf("\"}");
	}
};