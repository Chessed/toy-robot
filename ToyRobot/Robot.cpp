#pragma once

#include "Robot.h"

bool Robot::turnLeft() 
{
	if (!_isPlaced) {
		cout << "> PLACE robot first. Ignoring LEFT command." << endl;
		return false;
	}

	switch (_direction)
	{
	case direction::NORTH:	_direction = direction::WEST;	break;
	case direction::EAST:	_direction = direction::NORTH;	break;
	case direction::SOUTH:	_direction = direction::EAST;	break;
	case direction::WEST:	_direction = direction::SOUTH;	break;
	default:	/*do nothing*/		break;
	}
	return true;
}

bool Robot::turnRight()
{
	if (!_isPlaced) {
		cout << "> PLACE robot first. Ignoring RIGHT command." << endl;
		return false;
	}

	switch (_direction)
	{
	case direction::NORTH:	_direction = direction::EAST;	break;
	case direction::EAST:	_direction = direction::SOUTH;	break;
	case direction::SOUTH:	_direction = direction::WEST;	break;
	case direction::WEST:	_direction = direction::NORTH;	break;
	default:	/*do nothing*/		break;
	}
	return true;
}

bool Robot::moveForward()
{
	if (!_isPlaced) {
		cout << "PLACE robot first. Ignoring MOVE command." << endl;
		return false;
	}

	const Position newPos = getNewPos();
	if (isInBound(newPos)) {
		_position = newPos;
	}
	return true;
}

bool Robot::place(const Position& pos, const direction::Direction& dir)
{
	if (!isInBound(pos)) {
		cout << "PLACE robot out of bounds." << endl;
		return false;
	}
	_isPlaced = true;
	_position = pos;
	_direction = dir;
	return true;
}

bool Robot::report() const
{
	if (!_isPlaced) {
		cout << "PLACE robot first. Ignoring REPORT command." << endl;
		return false;
	}

	cout << "Output: " << _position.getX() << "," << _position.getY() << "," << direction::toString(_direction) << endl;
	return true;
}

bool Robot::isInBound(Position pos) const
{
	return _table.checkBounds(pos.getX(), pos.getY());
}


Position Robot::getNewPos() const
{
	Position newPos = _position;
	switch (_direction)
	{
	case direction::NORTH:	newPos.setY(_position.getY() + 1);	break;
	case direction::EAST:	newPos.setX(_position.getX() + 1);	break;
	case direction::SOUTH:	newPos.setY(_position.getY() - 1);	break;
	case direction::WEST:	newPos.setX(_position.getX() - 1);	break;
	default:	break;
	}

	return newPos;
}