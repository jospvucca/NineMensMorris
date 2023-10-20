#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, its best to return the class instance pointer
	static cocos2d::Scene* createScene();

	// Method 'init' in cocos2d-x returns bool, instead of returning 'id'
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

public:
	// Touch event listeners
	cocos2d::EventListenerTouchOneByOne* listener;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

	bool isValidMove(int, int);
	bool isMillFormed(int, int);
	void EndGame();

	// Logic elements
	cocos2d::Sprite* tokens[24];	// Possible positions

	int database[24];				// Ownership of positions
	int player = -1;				// Player turn
	int times = 0;					// Num of moves
	cocos2d::Sprite* black[9];		// pieces
	cocos2d::Sprite* white[9];		// pieces

	int selected = -1;				// selected piece
	int source = 0;					// original position of the selected piece
	int destination = 0;			// destination position of the selected piece
	int capture = 0;				// can player capture enemy piece
	int noCapture[24];				// can piece be captured
	int blackPieces, whitePieces;	// number of player pieces

	bool isHeld = false;			// if the piece is held by a player
};


#endif // __GAME_SCENE_H__