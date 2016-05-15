#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

#include "./sync_view.hpp"
#include "../solver/sync_result.hpp"

using namespace std;

namespace sync_statistics {
	bool compare(const pair<string, long long> &a, const pair<string, long long> &b) {
		return a.first.length() > b.first.length();
	}
}

class SyncStatisticsView : public SyncView {
protected:
	map <string, long long> m;
public:
	
	void begin() {
		m.clear();
		printf("[\n");
	}
	
	void add(SyncResult r) {
		bool result = r.result;
		if (!result)
			return;

		string current = r.s;
		m[current]++;
	}
	
	void end() {
		bool first = true;
		vector <pair<string, long long>> a;
		for (auto pair : m)
			a.push_back(pair);
		sort(a.begin(), a.end(), sync_statistics::compare);
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