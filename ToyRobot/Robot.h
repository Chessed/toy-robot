#pragma once

#include "ToyRobotData.h"
#include "Table.h"

using namespace std;

class Robot {
private:
	Position _position;
	direction::Direction _direction;
	Table _table;
	bool _isPlaced = false;

	Position getNewPos() const;
public:
	//Constructors
	Robot() : _position({ 0, 0 }), _direction(direction::NORTH), _table(5,5) {}
	Robot(Table table) : _position({ 0, 0 }), _direction(direction::NORTH), _table(table) {}

	//Setters
	void setPosition(const Position& position) { _position = position; }
	void setDirection(const direction::Direction& direction) { _direction = direction; }
		
	//Getters
	const Position& getPosition() { return _position; }
	const direction::Direction& getDirection() { return _direction; }
	const Table& getTable() { return _table; }

	//Methods
	bool turnLeft();
	bool turnRight();
	bool moveForward();
	bool place(const Position& , const direction::Direction&);
	bool report() const;

	bool isInBound(Position pos) const;
};