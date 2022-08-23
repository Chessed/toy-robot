#pragma once

#include "Table.h"


bool Table::checkBounds(int x, int y) const
{
	return x >= 0 && x < _columns && y >= 0 && y < _rows;
}