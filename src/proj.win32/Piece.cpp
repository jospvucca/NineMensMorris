#include "Piece.h"

USING_NS_CC;

Piece::Piece(int pieceId) : id(pieceId) { }

Vec2 Piece::getPosition() const {
	return position;
}

bool Piece::changePosition(Vec2 newPosition) {
	position = newPosition;
	return true;
}

void const Piece::setTexture(std::string texture) {
	this->texture.empty();
	this->texture + texture;
}