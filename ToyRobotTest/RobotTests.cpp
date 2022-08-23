#include "pch.h"
#include "../ToyRobot/Robot.h"

TEST(RobotTests, TestConstructors) 
{
	Robot robot1;
	Robot robot2(Table(6,6));

	//test default constructor
	EXPECT_EQ(robot1.getPosition(), Position(0, 0));
	EXPECT_EQ(robot1.getDirection(), direction::NORTH);
	EXPECT_EQ(robot1.getTable(), Table(5,5));

	//test parameterized constructor
	EXPECT_EQ(robot2.getPosition(), Position(0, 0));
	EXPECT_EQ(robot2.getDirection(), direction::NORTH);
	EXPECT_EQ(robot2.getTable(), Table(6, 6));
}

TEST(RobotTests, TestTurnLeft) 
{
	Robot robot;

	//call to set property _isPlaced
	robot.place(Position(0, 0), direction::NORTH);

	EXPECT_TRUE(robot.turnLeft());
	EXPECT_EQ(robot.getDirection(), direction::WEST);

	EXPECT_TRUE(robot.turnLeft());
	EXPECT_EQ(robot.getDirection(), direction::SOUTH);

	EXPECT_TRUE(robot.turnLeft());
	EXPECT_EQ(robot.getDirection(), direction::EAST);
	
	EXPECT_TRUE(robot.turnLeft());
	EXPECT_EQ(robot.getDirection(), direction::NORTH);

}

TEST(RobotTests, TestTurnRight) 
{
	Robot robot;

	//call to set property _isPlaced
	robot.place(Position(0, 0), direction::NORTH);

	EXPECT_TRUE(robot.turnRight());
	EXPECT_EQ(robot.getDirection(), direction::EAST);

	EXPECT_TRUE(robot.turnRight());
	EXPECT_EQ(robot.getDirection(), direction::SOUTH);

	EXPECT_TRUE(robot.turnRight());
	EXPECT_EQ(robot.getDirection(), direction::WEST);

	EXPECT_TRUE(robot.turnRight());
	EXPECT_EQ(robot.getDirection(), direction::NORTH);

}

TEST(RobotTests, TestPlaceOutOfBounds)
{
	Robot robot;
	
	EXPECT_FALSE(robot.place(Position(5, 2), direction::SOUTH));
	EXPECT_EQ(robot.getPosition(),Position(0, 0));
	EXPECT_EQ(robot.getDirection(), direction::NORTH);
}

TEST(RobotTests, TestPlaceInBound)
{
	Robot robot;

	EXPECT_TRUE(robot.place(Position(3, 2), direction::SOUTH));
	EXPECT_EQ(robot.getPosition(), Position(3, 2));
	EXPECT_EQ(robot.getDirection(), direction::SOUTH);
}

TEST(RobotTests, TestMoveOutOfBounds)
{
	Robot robot;

}

TEST(RobotTests, TestMoveInBound)
{
	Robot robot;

	//call to set property _isPlaced
	robot.place(Position(0, 0), direction::NORTH);

	EXPECT_TRUE(robot.moveForward());
	EXPECT_EQ(robot.getPosition(), Position(0,1));

	EXPECT_TRUE(robot.turnRight());
	EXPECT_TRUE(robot.moveForward());
	EXPECT_EQ(robot.getPosition(), Position(1, 1));

	EXPECT_TRUE(robot.turnRight());
	EXPECT_TRUE(robot.moveForward());
	EXPECT_EQ(robot.getPosition(), Position(1, 0));

	EXPECT_TRUE(robot.turnRight());
	EXPECT_TRUE(robot.moveForward());
	EXPECT_EQ(robot.getPosition(), Position(0, 0));
}

TEST(RobotTests, TestReport)
{
	Robot robot;

	//call to set property _isPlaced
	robot.place(Position(0, 0), direction::NORTH);

	EXPECT_TRUE(robot.report());
}

TEST(RobotTests, TestCommandsBeforePlace)
{
	Robot robot;

	//test move
	EXPECT_FALSE(robot.moveForward());
	
	//test turn left
	EXPECT_FALSE(robot.turnLeft());

	//test turn right
	EXPECT_FALSE(robot.turnRight());

	//test report
	EXPECT_FALSE(robot.report());
}