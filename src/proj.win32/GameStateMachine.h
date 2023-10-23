#pragma once
#ifndef __GAME_STATE_MACHINE_H__
#define __GAME_STATE_MACHINE_H__

#include "BaseState.h"

class GameStateMachine {
public:
	GameStateMachine(BaseState& initialState);
	void ChangeState(BaseState& newState, Player black, Player white);
	void Initialize(Player black, Player white);
	void Run(Player black, Player white);

private:
	BaseState& currentState;
};

#endif // !__GAME_STATE_MACHINE_H__
