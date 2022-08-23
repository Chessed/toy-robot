#pragma once

#include "ToyRobotData.h"

using namespace std;

class Table {
private:
	int _rows;
	int _columns;
public:
	//Constructors
	Table() : _columns(5), _rows(5) {}
	Table(int colums, int rows) : _columns(colums), _rows(rows){}

	//Operator overload
	bool operator == (const Table& table) const {
		return table.getColumns() == _columns && table.getRows() == _rows;
	}

	//Getters
	const int getRows() const { return _rows; }
	const int getColumns() const { return _columns; }

	//Methods
	bool checkBounds(int x, int y) const;
};