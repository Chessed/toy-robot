#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Parser{
public:
	pair<string, vector<string>> parseCommand(const string& input) const;
	vector<string> tokenize(const string& input, const char delimeter) const;
	string removeLeadingAndTrailingWhiteSpace(const string& input) const;
};