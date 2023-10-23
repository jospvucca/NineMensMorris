#include "TouchManagement.h"

USING_NS_CC;

TouchManagement* TouchManagement::instance = nullptr;

TouchManagement* TouchManagement::getInstance(BoardManagement boardManagement) {
	if (!instance) {
		instance = new TouchManagement();

		if (!instance && !instance->init(boardManagement)) {
			delete instance;
			instance = nullptr;
		}
	}

	return instance;
}

bool TouchManagement::init(BoardManagement boardManagement) {
	this->boardManager = boardManagement;

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(TouchManagement::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TouchManagement::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TouchManagement::onTouchEnded, this);

	dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

bool TouchManagement::onTouchBegan(Touch* touch, Event* event) {
	Point touchPoint = touch->getLocation();


	return true;
}

void TouchManagement::onTouchMoved(Touch* touch, Event* event) {

}

void TouchManagement::onTouchEnded(Touch* touch, Event* event) {

}

TouchManagement::TouchManagement() {

}