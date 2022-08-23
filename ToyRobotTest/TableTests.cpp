#include "pch.h"
#include "../ToyRobot/Table.h"

TEST(TableTests, TestConstructor)
{
	Table table1;
	Table table2(7,8);

	EXPECT_EQ(table1.getColumns(),5);
	EXPECT_EQ(table1.getRows(), 5);

	EXPECT_EQ(table2.getColumns(), 7);
	EXPECT_EQ(table2.getRows(), 8);
}

TEST(TableTests, TestCheckBounds)
{
	Table table(7,7);

	EXPECT_FALSE(table.checkBounds(7, 7));
	EXPECT_FALSE(table.checkBounds(7, 6));
	EXPECT_FALSE(table.checkBounds(6, 7));
	EXPECT_FALSE(table.checkBounds(-1, 0));
	EXPECT_FALSE(table.checkBounds(0, -1));
	EXPECT_TRUE(table.checkBounds(4, 3));
}