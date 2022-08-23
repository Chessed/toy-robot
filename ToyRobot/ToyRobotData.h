#pragma once

#include<iostream>
#include <string_view>

using namespace std;

class Position
{
private:
	int _x;
	int _y;
public:
	//Constructors
	Position() : Position(0, 0) {}
	Position(int x, int y): _x(x), _y(y) {}

	//Setters
	void setX(const int x) { _x = x; }
	void setY(const int y) { _y = y; }

	//Getters
	int getX() const { return _x; }
	int getY() const { return _y; }

	//Overloads
	bool operator == (const Position& pos) const {
		return pos.getX() == _x && pos.getY() == _y;
	}

};

namespace direction {
	typedef enum Direction {
		UNKNOWN,
		NORTH,
		EAST,
		SOUTH,
		WEST
	} Direction;

	inline std::string toString(Direction direction)
	{
		switch (direction)
		{
		case NORTH:	return "NORTH";
		case EAST:	return "EAST";
		case SOUTH: return "SOUTH";
		case WEST:	return "WEST";
		default:	throw invalid_argument("Unknown F value");
		}
	}

	inline Direction fromString(string_view direction)
	{
		if (direction == "NORTH") return NORTH;
		if (direction == "EAST") return EAST;
		if (direction == "SOUTH") return SOUTH;
		if (direction == "WEST") return WEST;

		throw invalid_argument("Unknown F value");
	}
}