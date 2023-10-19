#include "Intersections.h"

Intersections::Intersections(const Size& playgroundSize, int numRows, int numColumns) :
	playgroundSize(playgroundSize), numRows(numRows), numColumns(numColumns) {
	intersectionSpacingX = playgroundSize.width / numColumns;
	intersectionSpacingY = playgroundSize.height / numRows;
}

Vec2 Intersections::getIntersectionPosition(int row, int column) {
	float x = intersectionSpacingX * column + intersectionSpacingX / 2;
	float y = intersectionSpacingY * row + intersectionSpacingY / 2;
	return Vec2(x, y);
}