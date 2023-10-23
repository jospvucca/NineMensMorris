#pragma once
#ifndef __PLACEMENT_STATE_H__
#define __PLACEMENT_STATE_H__

#include "BaseState.h"

class PlacementState : public BaseState {
    void onEnter(Player black, Player white) override;
    void onUpdate(Player black, Player white) override;
    void onExit() override;
};

#endif // !__PLACEMENT_STATE_H__
