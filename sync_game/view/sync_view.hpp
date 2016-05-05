#pragma once

#include <vector>
#include <iostream>

#include "../../base/view/view.hpp"
#include "../../base/solver/result.hpp"
#include "../solver/sync_result.hpp"

using namespace std;

class SyncView : public View {
	void maximum(){}
	
	void full() {
		printf("[\n");
		for (int i = 0; i < (int)a.size(); i++) {
			int result = a[i].get_int_attr("result");
			string optimal = a[i].get_string_attr("optimal");
			int index = a[i].get_int_attr("index");
			if (result) {
				printf("{\"index\": %d, \"win\": true, \"length\": %d, \"optimal\": \"", index, optimal.length());
				cout << optimal;
				printf("\"}");
			}
			else {
				printf("{\"index\": %d, \"win\": false}", index);
			}
			printf(i + 1 < (int)a.size() ? ",\n" : "\n");
		}
		printf("]");
	}
	
	virtual void statistics() {};
};