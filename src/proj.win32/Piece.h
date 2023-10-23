#pragma once
#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include "cocos2d.h"

class Piece {
public:
	Piece(int pieceId);
	cocos2d::Vec2 getPosition() const;
	bool changePosition(cocos2d::Vec2 newPosition);
	void const setTexture(std::string texture);	//Should not be public

private:
	const int id;
	const std::string texture;
	cocos2d::Vec2 position;	//Location on map (question if we are not 
};

#endif // !__PIECE_H__
