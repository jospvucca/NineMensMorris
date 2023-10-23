#pragma once
#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__

#include "Player.h"

// Abstract class
class BaseState {
public:
	virtual void onEnter(Player black, Player white) = 0;
	virtual void onUpdate(Player black, Player white) = 0;
	virtual void onExit() = 0;
	virtual ~BaseState() = default;
};

#endif // !__BASE_STATE_H__
