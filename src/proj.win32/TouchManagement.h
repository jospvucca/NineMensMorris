#pragma once
#ifndef __TOUCH_MANAGEMENT_H__
#define __TOUCH_MANAGEMENT_H__

#include "BoardManagement.h"
#include "BaseState.h"
#include "cocos2d.h"

class TouchManagement : public cocos2d::Layer {
public:
	static TouchManagement* getInstance(BoardManagement boardManager);
	bool init(BoardManagement boardManager);

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	TouchManagement();
	static TouchManagement* instance;
	BoardManagement boardManager;
	//TODO nastavit
};

#endif // !__TOUCH_MANAGEMENT_H__
