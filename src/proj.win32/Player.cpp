#include "Player.h"

Player::Player(int playerId) : id(playerId), name(playerId == -1 ? "Black" : "White") { }

int Player::getPlayerId() const {
	return id;
}

void Player::addPiece(Piece piece) {
	piece.setTexture((name == "Black") ? "blackToken.png" : "whiteToken.png");
	pieces.push_back(piece);
}

int Player::getPieceCount() const {
	return this->pieces.size();
}