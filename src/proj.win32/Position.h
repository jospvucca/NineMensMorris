#pragma once
#ifndef __POSITION_H__
#define __POSITION_H__

#include "cocos2d.h"
#include "Piece.h"
#include <optional>

class Position : cocos2d::Sprite {
public:
	Position(cocos2d::Vec2& screenPosition, cocos2d::Vec2& matrixPosition);
	void setPiece(Piece piece);
	void clearPiece();
	bool hasPiece() const;
	std::vector<Position> createPositions(cocos2d::Size& visibleSize, cocos2d::Vec2& origin);	//Should not be placed here but it is for now
	cocos2d::Vec2 getScreenPosition();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	std::optional<Piece> piece = std::nullopt;
	std::string emptyTexture;
	cocos2d::Vec2 screenPosition;
	cocos2d::Vec2 matrixPosition;
};

#endif // !__POSITION_H__
