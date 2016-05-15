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
	struct Statistics {
		long long count = 0;
		long long example = 0;
	};

	bool compare(const pair<string, Statistics> &a, const pair<string, Statistics> &b) {
		return a.first.length() > b.first.length();
	}
}

class SyncStatisticsView : public SyncView {
protected:
	map <string, sync_statistics::Statistics> m;
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
		m[current].count++;
		m[current].example = r.a.index();
	}
	
	void end() {
		bool first = true;
		vector <pair<string, sync_statistics::Statistics>> a;
		for (auto pair : m)
			a.push_back(pair);
		sort(a.begin(), a.end(), sync_statistics::compare);
		for (auto pair : a) {
			if (!first)
				printf(",\n");
			first = false;
			printf("{\"count\": %lld, \"example\": %lld, \"length\": %d, \"optimal\": \"", pair.second.count, pair.second.example, pair.first.length());
			cout << pair.first;
			printf("\"}");
		}
		printf("\n]");
	}
};