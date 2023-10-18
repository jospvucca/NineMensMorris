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