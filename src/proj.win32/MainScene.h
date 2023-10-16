#pragma once
#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "BackgroundLayer.h"
using namespace cocos2d;

class MainScene : public Scene {
public:
	virtual bool init() override;

	CREATE_FUNC(MainScene);
};

#endif // !__MAIN_SCENE_H__
