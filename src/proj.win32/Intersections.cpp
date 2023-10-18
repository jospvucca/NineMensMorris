#include "Intersections.h"

Intersections::Intersections(const Size& playgroundSize, int numRows, int numColumns) :
	playgroundSize(playgroundSize), numRows(numRows), numColumns(numColumns) {
	intersectionSpacingX = playgroundSize.width / numColumns;
	intersectionSpacingY = playgroundSize.height / numRows;
}

Vec2 Intersections::getIntersectionPosition(int row, int column) {
	float x = intersectionSpacingX * column;
	float y = intersectionSpacingY * row;
	return Vec2(x, y);
}