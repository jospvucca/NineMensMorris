#include "PlacementState.h"
#include "Player.h"

USING_NS_CC;

void PlacementState::onEnter(Player black, Player white) {
	log("PlacementState::onEnter(). Adding pieces for placement.");
	//TODO: add visual placement on the side of the board
	auto initPieces = std::vector<Piece>();
	for (int i = 0; i < 18; i++) {
		auto piece = Piece::Piece(i);
		initPieces.push_back(piece);
	}

	for (int i = 0; i < 9; i++) {
		black.addPiece(initPieces[i]);
	}
	
	for (int i = 9; i < 18; i++) {
		white.addPiece(initPieces[i]);
	}
}

void PlacementState::onUpdate(Player black, Player white) {
	log("PlacementState::onUpdate()");
	if (!black.getPieceCount() && !white.getPieceCount()) {
		this->onExit();
	}
}

void PlacementState::onExit() {
	log("PlacementState::onExit()");
}