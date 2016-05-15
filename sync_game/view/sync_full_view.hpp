#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "./sync_view.hpp"

using namespace std;

class SyncFullView : public SyncView {
protected:
	bool first;
public:
	
	void begin() {
		printf("[\n");
		first = true;
	}
	
	void add(SyncResult r) {
		if (!first)
			printf(",\n");
		else
			first = false;
		bool result = r.result;
		string optimal = r.s;
		long long index = r.a.index();

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