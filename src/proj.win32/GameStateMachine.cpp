#include "GameStateMachine.h"
#include "cocos2d.h"

USING_NS_CC;

GameStateMachine::GameStateMachine(BaseState& initialState) : currentState(initialState) { }

void GameStateMachine::ChangeState(BaseState& newState, Player black, Player white) {
	if (&newState == nullptr) {
		//Should be custom exception
		throw EXCEPTION_ILLEGAL_INSTRUCTION;
	}

	if (&currentState != nullptr) {
		currentState.onExit();
	}

	newState.onEnter(black, white);
	currentState = newState;
}

void GameStateMachine::Initialize(Player black, Player white) {
	if (&currentState != nullptr) {
		currentState.onEnter(black, white);
	}
}

void GameStateMachine::Run(Player black, Player white) {
	if (&currentState != nullptr) {
		currentState.onUpdate(black, white);
	}
}