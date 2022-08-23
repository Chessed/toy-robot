#include "pch.h"
#include "../ToyRobot/Command.h"

bool TestNoArgsCommand(const string& rawcommand);

TEST(CommandTests, TestCommandFactoryPlace)
{
	Command cmd;
	Robot robot;

	string command("Place");

	EXPECT_THROW({
		try {
			cmd.CommandFactory(command,{})(robot);
		}
		catch (const exception& e) {
			EXPECT_STREQ(e.what(), "PLACE command called with incorrect number of arguments.");
			throw;
		}
	}, exception);

	EXPECT_THROW({
		try {
			cmd.CommandFactory(command, {"1","2","LEFT"} )(robot);
		}
		catch (const exception& e) {
			EXPECT_STREQ(e.what(), "Unknown F value");
			throw;
		}
	}, exception);

	EXPECT_THROW({
		try {
			cmd.CommandFactory(command, {"1","x","LEFT"})(robot);
		}
		catch (const exception& e) {
			EXPECT_STREQ(e.what(), "X,Y invalid has value");
			throw;
		}
	}, exception);

	EXPECT_NO_THROW(cmd.CommandFactory(command, { "1","2","North" })(robot););

}

TEST(CommandTests, TestCommandFactoryMove)
{
	string command("MOVE");

	EXPECT_TRUE(TestNoArgsCommand(command));
}

TEST(CommandTests, TestCommandFactoryTurnLeft)
{
	string command("left");

	EXPECT_TRUE(TestNoArgsCommand(command));
}

TEST(CommandTests, TestCommandFactoryTurnRight)
{
	string command("rIGht");

	EXPECT_TRUE(TestNoArgsCommand(command));
}

TEST(CommandTests, TestCommandFactoryReport)
{
	string command("rePORT");

	EXPECT_TRUE(TestNoArgsCommand(command));
}

bool TestNoArgsCommand(const string& rawcommand) {
	Command cmd;
	Robot robot;

	const vector<string> args({ "1","2","North" });
	string uppercaseCommand = rawcommand;

	transform(uppercaseCommand.begin(), uppercaseCommand.end(), uppercaseCommand.begin(), ::toupper);
	const string errorMsg = "Unexpected arguments for " + uppercaseCommand;

	EXPECT_THROW({
		try {
			cmd.CommandFactory(rawcommand,args)(robot);
		}
		catch (const exception& e) {
			EXPECT_STREQ(e.what(), errorMsg.c_str() );
			throw;
		}
	}, exception);

	EXPECT_NO_THROW(cmd.CommandFactory(rawcommand, {})(robot););
}