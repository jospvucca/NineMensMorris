#pragma once

#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;	//To not explicitly cast cocos2d for each engine class

class BackgroundLayer : public Layer {
public:
	BackgroundLayer();
	virtual ~BackgroundLayer();

	virtual bool init() override;
	static BackgroundLayer* create();
};

#endif // !__BACKGROUND_LAYER_H__
