#pragma once
#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__

#include "cocos2d.h"

class SplashScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, its best to return the class instance pointer
    static cocos2d::Scene* createScene();

    // Method 'init' in cocos2d-x returns bool, instead of returning 'id'
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(SplashScene);

private:
    void SwitchToMainMenu(float dt);
};
#endif // __SPLASH_SCENE_H__