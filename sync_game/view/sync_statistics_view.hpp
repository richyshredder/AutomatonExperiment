#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

#include "../../base/view/view.hpp"
#include "../../base/solver/result.hpp"
#include "../solver/sync_result.hpp"

using namespace std;

bool compare(const pair<string, long long> &a, const pair<string, long long> &b) {
	return a.first.length() > b.first.length();
}

class SyncStatisticsView : public View {
protected:
	map <string, long long> m;
public:
	
	void begin() {
		m.clear();
		printf("[\n");
	}
	
	void add(Result r) {
		int result = r.get_int_attr("result");
		if (!result)
			return;

		string current = r.get_string_attr("optimal");
		m[current]++;
	}
	
	void end() {
		bool first = true;
		vector <pair<string, long long>> a;
		for (auto pair : m)
			a.push_back(pair);
		sort(a.begin(), a.end(), compare);
		for (auto pair : a) {
			if (!first)
				printf(",\n");
			first = false;
			printf("{\"count\": %lld, \"length\": %d, \"optimal\": \"", pair.second, pair.first.length());
			cout << pair.first;
			printf("\"}");
		}
		printf("\n]");
	}
};