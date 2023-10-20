#include "SplashScene.h"
#include "MainMenu.h"
#include "Definitions.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    Scene* scene = Scene::create();		//scene is an autorelease
    Layer* layer = SplashScene::create();	//layer is an autorelease

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

bool SplashScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();

    //Add Background + transition to next scene
    Point origin = Director::getInstance()->getVisibleOrigin();
    Sprite* background = Sprite::create("splashScene.png");
    background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background, -1);

    float rX = visibleSize.width / background->getContentSize().width;
    float rY = visibleSize.height / background->getContentSize().height;
    background->setScaleX(rX);
    background->setScaleY(rY);

    scheduleOnce([this](float dt) {
        this->SwitchToMainMenu(dt);
        }, SPLASH_SCENE_SHOW_TIME, "SPLASH_SCENE_SHOW_TIME");

    return true;
}
void SplashScene::SwitchToMainMenu(float dt)
{
    Scene* scene = MainMenu::createScene();
    TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transition);
}