#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Command.h"

using namespace std;

auto Command::CommandFactory(string name, vector<string> arguments) const -> std::function<void(Robot&)>
{
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	const string command = name;

	if (command == "PLACE")
	{
		if (arguments.size() != 3)
			throw invalid_argument("PLACE command called with incorrect number of arguments.");

		int x,y;
		try {
			x = stoi(arguments[0]);
			y = stoi(arguments[1]);
		}
		catch(const exception& e) {
			throw invalid_argument("X,Y invalid has value");
		}

		const Position pos(x, y);

		transform(arguments[2].begin(), arguments[2].end(), arguments[2].begin(), ::toupper);
		const direction::Direction direction = direction::fromString(arguments[2]);

		return  [&, pos, direction](auto& robot) { robot.place(pos, direction); };
	}

	if (command == "MOVE") {
		if(!arguments.empty()) throw invalid_argument("Unexpected arguments for " + command);
		return [](auto& robot) { robot.moveForward(); };
	}

	if (command == "LEFT") {
		if (!arguments.empty()) throw invalid_argument("Unexpected arguments for " + command);
		return [](auto& robot) { robot.turnLeft(); };
	}

	if (command == "RIGHT") {
		if (!arguments.empty()) throw invalid_argument("Unexpected arguments for " + command);
		return [](auto& robot) { robot.turnRight(); };
	}

	if (command == "REPORT") {
		if (!arguments.empty()) throw invalid_argument("Unexpected arguments for " + command);
		return [](auto& robot) { robot.report(); };
	}

	throw invalid_argument("Unknown command: " + command);
}