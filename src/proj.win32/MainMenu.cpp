#include "MainMenu.h"
#include "GameScene.h"
#include "Definitions.h"
#include "ui/UIButton.h"

using namespace std;
USING_NS_CC;

Scene* MainMenu::createScene()
{
	Scene* scene = Scene::create();		//scene is an autorelease
	Layer* layer = MainMenu::create();	//layer is an autorelease

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}

bool MainMenu::init()
{
	//////////////////////////////
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//	----	background	----	//
	Point origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("mainMenuBackground.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);
	//////////////////////////////////

	//	----	Menu layer	----	//
	menuLayer = Layer::create();

	//Add button for 1v1 game
	auto PlayervPlayerButton = ui::Button::create("1v1.png");
	PlayervPlayerButton->setPosition(Point(visibleSize.width / 4 + origin.x, visibleSize.height * 0.58f + origin.y));
	menuLayer->addChild(PlayervPlayerButton);

	PlayervPlayerButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = GameScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		});

	menuLayer->setScale(rY);
	this->addChild(menuLayer);
	//////////////////////////////////

	return true;
}