#pragma once

#include <string>
#include "./sync_view.hpp"
#include "./sync_full_view.hpp"
#include "./sync_maximum_view.hpp"
#include "./sync_statistics_view.hpp"

using namespace std;

class SyncViewFactory {
public:
	SyncView* generate(string s) {
		if (s == "full")
			return new SyncFullView();
		if (s == "maximum")
			return new SyncMaximumView();
		if (s == "statistics")
			return new SyncStatisticsView();
		throw "undefined";
	}
};