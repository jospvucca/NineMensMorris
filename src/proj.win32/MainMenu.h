#pragma once
#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, its best to return the class instance pointer
    static cocos2d::Scene* createScene();

    // Method 'init' in cocos2d-x returns bool, instead of returning 'id'
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
private:
    Layer* menuLayer;
    Layer* menu2;
};

#endif // __MAIN_MENU_H__