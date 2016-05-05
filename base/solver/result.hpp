#pragma once

#include <string>
#include <map>

using namespace std;

class Result {
protected:
	map <string, string> str_attr;
	map <string, int> int_attr;
public:
	string get_string_attr(string s) {
		return str_attr[s];
	}
    int get_int_attr(string s) {
		return int_attr[s];
	}
};