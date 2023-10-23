#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include "Piece.h"

class Player {
public:
	Player(int playerId);		// -1 == black, 1 == white
	int getPlayerId() const;
	void addPiece(Piece piece);
	int getPieceCount() const;

private:
	const int id;
	std::string name;
	std::vector<Piece> pieces;
};

#endif // !__PLAYER_H__
