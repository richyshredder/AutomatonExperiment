#pragma once

#include <string>

#include "./view.hpp"

using namespace std;

class ViewFactory {
public:
	virtual View* generate(string s) = 0;
};