#include "Parser.h"
#include <regex>
#include <sstream>

pair<string, vector<string>> Parser::parseCommand(const string& input) const
{
	auto tokens = tokenize(removeLeadingAndTrailingWhiteSpace(input), ' ');

	if (tokens.size() == 1)
	{
		return  make_pair(move(tokens[0]), vector<string>{});
	}
	if (tokens.size() == 2)
	{
		auto arguments = tokenize(tokens[1], ',');
		return make_pair(move(tokens[0]), move(arguments));
	}

	throw invalid_argument("Unknown command: " + input);
}

vector<string> Parser::tokenize(const string& input, const char delimiter) const
{
	istringstream strStream(input);
	string token;
	vector<string> tokens;

	while (getline(strStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

string Parser::removeLeadingAndTrailingWhiteSpace(const string& input) const
{
	string output = input;
	output = regex_replace(output, regex("^\\s+"), "");
	output = regex_replace(output, regex("\\s+$"), "");
	return output;
}