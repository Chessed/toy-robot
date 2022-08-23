#include <iostream>
#include <functional>
#include "Robot.h"
#include "ToyRobotData.h"

using namespace std;

class Command {
public:
	auto CommandFactory(string name, vector<string> arguments) const -> function<void(Robot&)>;
};