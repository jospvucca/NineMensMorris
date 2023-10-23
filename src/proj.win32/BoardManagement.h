#pragma once
#ifndef __BOARD_MANAGEMENT_H__
#define __BOARD_MANAGEMENT_H__

#include <iostream>
#include "cocos2d.h"
#include "Position.h"

class BoardManagement {
public:
	BoardManagement();
	std::vector<std::unique_ptr<Position>> createPositions(cocos2d::Size& visibleSize, cocos2d::Vec2& origin);
};

#endif // !__BOARD_MANAGEMENT_H__
