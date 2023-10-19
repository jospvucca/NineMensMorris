#pragma once
#ifndef __POSITION_H__
#define __POSITION_H__

#include "cocos2d.h"
#include "Intersections.h"
using namespace cocos2d;

class Position {
public:
	Position(Intersections intersections);
	Position(const Size& playgroundSize, int numRows, int numCols);
	Sprite* createCircleSprite(const Color3B& color, float radius);
	std::vector<Vec2> getNeighbours(int row, int column);
	
private:
	Intersections intersections;
};

#endif // !__POSITION_H__
