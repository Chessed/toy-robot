// ToyRobot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "ToyRobot.h"
#include "Command.h"

using namespace std;

int main()
{
	string inputStringCommand;

	//initialize components
	Table table;
	Parser parser;
	Robot toyRobot(table);
	Command cmd;
	
	//Catch Input
	cout	<<	"****************************** Toy Robot *******************************"	<< endl
			<<	"Supported Commands:"														<< endl
			<<	"  1. PLACE X,Y,F - Starting command. Places the Robot to X,Y position."	<< endl
			<<	"                   on the Table. Use again to relocate the Robot."			<< endl
			<<	"                   F Values: NORTH, EAST, SOUTH, WEST"						<< endl
			<<  "  2. MOVE - Moves the Robot 1 step forward to the direction it is facing."	<< endl
			<<	"  3. LEFT - Turns the Robot's direction 90 degrees counter-clockwise."		<< endl
			<<	"  4. RIGHT - Turns the Robot's direction 90 degrees clockwise."			<< endl
			<<	"  5. REPORT - Report current position and direction of the Robot: X,Y,F"	<< endl
			<<	"  *Use 'exit' command to exit program"										<< endl
			<<	"************************************************************************"	<< endl
			<<	"Start Command Input" << endl; 
	
	while (std::getline(cin, inputStringCommand)) {
		if (inputStringCommand == "exit") break;
		try 
		{
			auto [command, args] = parser.parseCommand(inputStringCommand);
			cmd.CommandFactory(command, args)(toyRobot);
		}
		catch(const exception& e) {
			cerr << "> ERROR: " << e.what() << endl;
		}

	}
	
}
