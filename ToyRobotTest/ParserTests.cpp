#include "pch.h"
#include "../ToyRobot/Parser.h"

TEST(ParserTests, TestRemoveWhiteSpacesMethod)
{
	Parser parser;

	EXPECT_EQ(parser.removeLeadingAndTrailingWhiteSpace("     command"),"command");
	EXPECT_EQ(parser.removeLeadingAndTrailingWhiteSpace("command   "), "command");
	EXPECT_EQ(parser.removeLeadingAndTrailingWhiteSpace("     command   "), "command");
	EXPECT_EQ(parser.removeLeadingAndTrailingWhiteSpace("     c o m m a n d   "), "c o m m a n d");
	EXPECT_EQ(parser.removeLeadingAndTrailingWhiteSpace("    "), "");
}

TEST(ParserTests, TestTokenizeMethod)
{
	Parser parser;

	auto spaceDelimitedArr = parser.tokenize("This is a  test",' ');
	auto commaDelimitedArr = parser.tokenize("apple, mango, banana, strawberry,,pineapple",',');

	EXPECT_EQ(spaceDelimitedArr.size(),5);
	EXPECT_EQ(spaceDelimitedArr[0], "This");
	EXPECT_EQ(spaceDelimitedArr[1], "is");
	EXPECT_EQ(spaceDelimitedArr[2], "a");
	EXPECT_EQ(spaceDelimitedArr[3], "");
	EXPECT_EQ(spaceDelimitedArr[4], "test");

	EXPECT_EQ(commaDelimitedArr.size(),6);
	EXPECT_EQ(commaDelimitedArr[0], "apple");
	EXPECT_EQ(commaDelimitedArr[1], " mango");
	EXPECT_EQ(commaDelimitedArr[2], " banana");
	EXPECT_EQ(commaDelimitedArr[3], " strawberry");
	EXPECT_EQ(commaDelimitedArr[4], "");
	EXPECT_EQ(commaDelimitedArr[5], "pineapple");
}

TEST(ParserTests, TestParseCommandMethodInvalidArgumentWithSpaces)
{
	Parser parser;

	//white spaces in the argument will be considered as another unknown part of the command input
	EXPECT_ANY_THROW(parser.parseCommand("place 1,2,  North"));
	EXPECT_ANY_THROW(parser.parseCommand("place 1, 2,North"));
	EXPECT_ANY_THROW(parser.parseCommand("place 1 2 North"));
}

TEST(ParserTests, TestParseCommandMethodWithWhiteSpaces)
{
	Parser parser;

	EXPECT_NO_THROW(parser.parseCommand("     PLACE 1,2,NORTH"));
	EXPECT_NO_THROW(parser.parseCommand("PLACE 1,2,NORTH     "));
	EXPECT_NO_THROW(parser.parseCommand("     PLACE 1,2,NORTH     "));
	EXPECT_ANY_THROW(parser.parseCommand("     PLACE    1,2,NORTH     "));
}

TEST(ParserTests, TestParseCommandMethodInputCorrectness)
{
	Parser parser;

	//no validation of commands done, parsing only for commands and arguments
	//so "move 2,x" should be acceptable
	EXPECT_NO_THROW(parser.parseCommand("move 2,x"));

	auto [command, args] = parser.parseCommand("PLACE 2,2,NORTH");
	EXPECT_EQ(command, "PLACE");
	EXPECT_EQ(args.size(), 3);
	EXPECT_EQ(args[0], "2");
	EXPECT_EQ(args[1], "2");
	EXPECT_EQ(args[2], "NORTH");
}

