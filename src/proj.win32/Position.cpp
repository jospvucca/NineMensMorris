#include "Position.h"

Position::Position(Intersections intersections) : intersections(intersections) { }

Position::Position(const Size& playgroundSize, int numRows, int numCols) :
	intersections(playgroundSize, numRows, numCols) { }

Sprite* Position::createCircleSprite(const Color3B& color, float radius) {
	DrawNode* circleShape = DrawNode::create();
	circleShape->drawDot(Vec2(0, 0), radius, Color4F(color));
	circleShape->setPosition(Vec2(0, 0));

	Sprite* circleSprite = Sprite::create();
	circleSprite->setColor(color);
	circleSprite->addChild(circleShape);
	circleSprite->setPosition(intersections.getIntersectionPosition(1, 1));		//This needs to be dynamic if it doesnt work, this is just example position

	return circleSprite;
}

std::vector<Vec2> Position::getNeighbours(int row, int column) {
	std::vector<Vec2> neighbours;

	//Determine the neighbours by the game rules
	if ((row == 0 || row == 6) && (column == 1 || column == 3 || column == 5)) {
		// Top and bottom rows with positions in the middle column
		neighbours.push_back(intersections.getIntersectionPosition(row, column - 1));	//Left neighbour
		neighbours.push_back(intersections.getIntersectionPosition(row, column + 1));	//Right neighbour
	}
	else if ((column == 0 || column == 6) && (row == 1 || row == 3 || row == 5)) {
		// Left and right columns with positions in the middle row
		neighbours.push_back(intersections.getIntersectionPosition(row - 1, column)); // Upper neighbor
		neighbours.push_back(intersections.getIntersectionPosition(row + 1, column)); // Lower neighbor
	}
	else if (row == 1 || row == 3 || row == 5) {
		// Middle rows
		if (column == 1 || column == 5) {
			// Positions in the second and sixth columns
			neighbours.push_back(intersections.getIntersectionPosition(row, column - 1)); // Left neighbor
			neighbours.push_back(intersections.getIntersectionPosition(row, column + 1)); // Right neighbor
		}
		else {
			// Positions in the third and fourth columns
			neighbours.push_back(intersections.getIntersectionPosition(row - 1, column)); // Upper neighbor
			neighbours.push_back(intersections.getIntersectionPosition(row + 1, column)); // Lower neighbor
		}
	}
	else {
		// All other positions
		neighbours.push_back(intersections.getIntersectionPosition(row, column - 1)); // Left neighbor
		neighbours.push_back(intersections.getIntersectionPosition(row, column + 1)); // Right neighbor
		neighbours.push_back(intersections.getIntersectionPosition(row - 1, column)); // Upper neighbor
		neighbours.push_back(intersections.getIntersectionPosition(row + 1, column)); // Lower neighbor
	}
	
	return neighbours;
}