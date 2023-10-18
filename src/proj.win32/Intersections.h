#pragma once

#ifndef __INTERSECTIONS_H__
#define __INTERSECTIONS_H__

#include "cocos2d.h"
using namespace cocos2d;

class Intersections {
public:
	Intersections(const Size& playgroundSize, int numRows, int numCols);
	Vec2 getIntersectionPosition(int row, int column);
	int getNumRows() const { return numRows; }
	int getNumColumns() const { return numColumns; }

private:
	Size playgroundSize;
	int numRows;
	int numColumns;
	float intersectionSpacingX;
	float intersectionSpacingY;
};

#endif // !__INTERSECTIONS_H__
