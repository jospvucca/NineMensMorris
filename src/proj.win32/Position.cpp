#include "Position.h"

USING_NS_CC;

Position::Position(Vec2& screenPosition, Vec2& matrixPosition) : screenPosition(screenPosition), matrixPosition(matrixPosition), piece(std::nullopt) {
	setPosition(screenPosition);
}

void Position::setPiece(Piece p) {
	if (this->piece.has_value()) {
		p.changePosition(this->screenPosition);	//TODO: do visual change

		this->piece.emplace(p);
	}
}

void Position::clearPiece() {
	piece.reset();
}

bool Position::hasPiece() const {
	return piece.has_value() ? false : true;
}
