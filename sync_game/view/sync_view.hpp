#pragma once

#include "../solver/sync_result.hpp"

class SyncView {
public:
	virtual void add(SyncResult r) = 0;
	virtual void begin() = 0;
	virtual void end() = 0;
};