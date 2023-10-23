#include "GameScene.h"
#include "GameStateMachine.h"
#include "PlacementState.h"
#include "BoardManagement.h"
#include "TouchManagement.h"
#include "Player.h"

#include "MainMenu.h"
#include"definitions.h"

#include "ui/CocosGUI.h"
#include <sstream>
#include <algorithm>
#include<iostream>

using namespace std;
USING_NS_CC;

Scene* GameScene::createScene()
{
	Scene* scene = Scene::create();		//scene is an autorelease
	Layer* layer = GameScene::create();	//layer is an autorelease

	// add layer as a child to scene
	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//	----	Players	----	//
	Player black = Player::Player(-1);
	Player white = Player::Player(1);
	//////////////////////////////

	//	----	Game State Machine	----	//
	PlacementState placementState;
	GameStateMachine gameStateMachine(placementState);
	gameStateMachine.Initialize(black, white);
	//////////////////////////////////////////

	//	----	Background	----	//
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("backgroundTexture.png");
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(background, -1);

	float rX = visibleSize.width / background->getContentSize().width;
	float rY = visibleSize.height / background->getContentSize().height;
	background->setScaleX(rX);
	background->setScaleY(rY);
	//////////////////////////////////

	//	----	Positions	----	//
	BoardManagement boardManager = BoardManagement::BoardManagement();
	std::vector<std::unique_ptr<Position>> positions = boardManager.createPositions(visibleSize, origin);
	//////////////////////////////////

	//	----	Touch Manager	----	//
	TouchManagement* touchManager = TouchManagement::getInstance(boardManager);
	//////////////////////////////////////
	
	//	----	Back button	----	//
	auto backButton = cocos2d::ui::Button::create("backButton.png");
	backButton->setPosition(Point(visibleSize.width / 1.06 + origin.x, visibleSize.height / 1.08 + origin.y));
	backButton->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{

		case ui::Widget::TouchEventType::ENDED:
			auto scene = MainMenu::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		}
		});

	backButton->setScale(rY * 0.9);
	this->addChild(backButton);
	//////////////////////////////////

	////	----	Positioning black pieces	----	//
	//black[0] = Sprite::create("blackToken.png");
	//black[0]->setPosition(Point(visibleSize.width / 5.55 + origin.x, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(black[0], -1);

	//black[1] = Sprite::create("blackToken.png");
	//black[1]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(black[1], -1);

	//black[2] = Sprite::create("blackToken.png");
	//black[2]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(black[2], -1);
	////	----	----	----	----	----	----	//

	//black[3] = Sprite::create("blackToken.png");
	//black[3]->setPosition(Point(visibleSize.width / 5.55 + origin.x, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	//this->addChild(black[3], -1);

	//black[4] = Sprite::create("blackToken.png");
	//black[4]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	//this->addChild(black[4], -1);

	//black[5] = Sprite::create("blackToken.png");
	//black[5]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width));//done 23
	//this->addChild(black[5], -1);
	////	----	----	----	----	----	----	//

	//black[6] = Sprite::create("blackToken.png");
	//black[6]->setPosition(Point(visibleSize.width / 5.55 + origin.x, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width * 2));//done 23
	//this->addChild(black[6], -1);

	//black[7] = Sprite::create("blackToken.png");
	//black[7]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width * 2));//done 23
	//this->addChild(black[7], -1);

	//black[8] = Sprite::create("blackToken.png");
	//black[8]->setPosition(Point(visibleSize.width / 5.55 + origin.x - black[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - black[1]->getContentSize().width * 2));//done 23
	//this->addChild(black[8], -1);
	////////////////////////////////////////////////////

	////	----	Positioning white pieces	----	//
	//white[0] = Sprite::create("whiteToken.png");
	//white[0]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(white[0], -1);

	//white[1] = Sprite::create("whiteToken.png");
	//white[1]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(white[1], -1);

	//white[2] = Sprite::create("whiteToken.png");
	//white[2]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y));//done 23
	//this->addChild(white[2], -1);
	////	----	----	----	----	----	----	//

	//white[3] = Sprite::create("whiteToken.png");
	//white[3]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	//this->addChild(white[3], -1);

	//white[4] = Sprite::create("whiteToken.png");
	//white[4]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	//this->addChild(white[4], -1);

	//white[5] = Sprite::create("whiteToken.png");
	//white[5]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width));//done 23
	//this->addChild(white[5], -1);
	////	----	----	----	----	----	----	//

	//white[6] = Sprite::create("whiteToken.png");
	//white[6]->setPosition(Point(visibleSize.width / 1.08 + origin.x, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	//this->addChild(white[6], -1);

	//white[7] = Sprite::create("whiteToken.png");
	//white[7]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	//this->addChild(white[7], -1);

	//white[8] = Sprite::create("whiteToken.png");
	//white[8]->setPosition(Point(visibleSize.width / 1.08 + origin.x - white[1]->getContentSize().width * 2, visibleSize.height / 2 + origin.y - white[1]->getContentSize().width * 2));//done 23
	//this->addChild(white[8], -1);
	////////////////////////////////////////////////////

	//	----	Event handling	----	//
	listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	//////////////////////////////////////

	return true;
}

int hold = 0;		// TODO: this is getting refactored, placed as bool isHeld in .h file
void GameScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("onTouchEnded.");

	//Destination
	Point touchPoint = touch->getLocation();

	//position == 0 -> empty, -1 -> black, 1 -> white
	//isMillFormed -> rules say you cant remove a piece in line

	if (capture)
	{
		for (int j = 0; j < 24; j++) //gather those who cant be captured
		{
			if (database[j] != 0 && (isMillFormed(j, database[j])))
				noCapture[j] = 1;
		}

		for (int i = 0; i < 24; i++)
		{
			if (tokens[i]->getBoundingBox().containsPoint(touchPoint) && database[i] == player && noCapture[i] == 0)
			{
				for (int k = 0; k < 9; k++) {
					if (player == -1 && black[k]->getBoundingBox().containsPoint(touchPoint)) {
						MoveTo* moveTo = MoveTo::create(0.5, Point(0, 0));
						black[k]->runAction(moveTo);

						//This can possibly be outside of the ifs and for(k)
						database[i] = 0;
						capture = 0;
					}
					else if (player == 1 && white[k]->getBoundingBox().containsPoint(touchPoint)) {
						MoveTo* moveTo = MoveTo::create(0.5, Point(0, 0));
						white[k]->runAction(moveTo);

						database[i] = 0;
						capture = 0;
					}
					else {
						cocos2d::log("Error in logic.");
					}
				}
			}
		}
		EndGame();
	}
	else {
		if (times < 18)
		{
			for (int i = 0; i < 24; i++)
			{
				if (database[i] == 0 && tokens[i]->getBoundingBox().containsPoint(touchPoint)) {
					database[i] = player;
					MoveTo* moveTo = MoveTo::create(0.5, Vec2(tokens[i]->getPosition().x, tokens[i]->getPosition().y));

					if (player == -1) {
						black[times / 2]->runAction(moveTo);
					}
					else if (player == 1) {
						white[times / 2]->runAction(moveTo);
					}
					else {
						cocos2d::log("Error in logic.");
					}

					capture = isMillFormed(i, player);
					cocos2d::log("IsMillFormed? -> %d", isMillFormed(i, player));
					times++;
					player *= -1;
				}
			}
		}
		//else if (times == 18)
		//{
		//	if (hold)
		//	{
		//		// Find the destination where the player wants to move the piece
		//		int destination = -1;
		//		for (int i = 0; i < 24; i++) {
		//			if (database[i] == 0 && tokens[i]->getBoundingBox().containsPoint(touchPoint)) {
		//				destination = 1;
		//				break;
		//			}
		//		}

		//		//Check if the move is valid or certain conditions are met
		//		if (destination != -1) {
		//			bool validMove = isValidMove(source, destination) || (blackPieces == 3 && player == -1) || (whitePieces == 3 && player == 1);

		//			if (database[destination] == 0 && validMove) {
		//				MoveTo* moveTo = MoveTo::create(0.5, Vec2(tokens[destination]->getPosition().x, tokens[destination]->getPosition().y));

		//				if (player == -1) {
		//					black[selected]->runAction(moveTo);
		//					black[selected]->setTexture("blackToken.png");
		//				}
		//				else if (player == 1) {
		//					white[selected]->runAction(moveTo);
		//					white[selected]->setTexture("whiteToken.png");
		//				}
		//				else {
		//					cocos2d::log("Error in logic.");
		//				}

		//				database[source] = 0;
		//				database[destination] = player;
		//				hold = 0;
		//				player *= -1;
		//				cocos2d::log("IsMillFormed? -> %d", isMillFormed(destination, database[destination]));
		//				cocos2d::log("%d player: %d", destination, database[destination]);
		//				capture = isMillFormed(destination, database[destination]);
		//			}
		//		}
		//	}

		//	for (int i = 0; i < 9; i++)
		//	{
		//		Sprite** pieceArray;
		//		if (player == -1) {
		//			pieceArray = black;
		//		}
		//		else if (player == 1) {
		//			pieceArray = white;
		//		}
		//		else {
		//			cocos2d::log("Error in logic.");
		//		}

		//		if (pieceArray[i] != 0 && pieceArray[i]->getBoundingBox().containsPoint(touchPoint)) {
		//			//Reset all textures for pieces
		//			for (int k = 0; k < 9; k++) {
		//				string texture;
		//				if (player == -1)
		//				{
		//					texture = "blackToken.png";
		//				}
		//				else if (player == 1) {
		//					texture = "whiteToken.png";
		//				}
		//				else {
		//					cocos2d::log("Error in logic.");
		//				}

		//				pieceArray[k]->setTexture(texture);
		//				selected = i;
		//				pieceArray[selected]->setTexture(texture);	//Possibly not the same texture
		//				hold = 1;
		//			}
		//		}
		//	}
		//	if (hold) {
		//		for (int k = 0; k < 24; k++) {
		//			if (tokens[k]->getBoundingBox().containsPoint(touchPoint) && database[k] == player) {
		//				source = k;
		//			}
		//		}
		//	}
		//}
		else if (times == 18)
		{
			if (hold)
			{
				int destination = -1;

				for (int i = 0; i < 24; i++)
				{
					if (database[i] == 0 && tokens[i]->getBoundingBox().containsPoint(touchPoint))
					{
						destination = i;
						break;
					}
				}

				if (destination != -1)
				{
					bool validMove = isValidMove(source, destination) || (blackPieces == 3 && player == -1) || (whitePieces == 3 && player == 1);

					if (database[destination] == 0 && validMove)
					{
						// Your move logic here
						MoveTo* moveTo = MoveTo::create(0.5, Vec2(tokens[destination]->getPosition().x, tokens[destination]->getPosition().y));

						if (player == -1) {
							black[selected]->runAction(moveTo);
							black[selected]->setTexture("blackToken.png");
						}
						else if (player == 1) {
							white[selected]->runAction(moveTo);
							white[selected]->setTexture("whiteToken.png");
						}
						else {
							cocos2d::log("Error in logic.");
						}

						database[source] = 0;
						database[destination] = player;
						hold = 0;
						player *= -1;
						capture = isMillFormed(destination, database[destination]);
					}
					else
					{
						// Handle invalid moves here
						cocos2d::log("Invalid move or conditions not met.");
					}
				}
				else
				{
					// Handle the case where no valid destination was found
					cocos2d::log("No valid destination found.");
				}
			}
			else
			{
				// Handle the case where hold is false
				cocos2d::log("Hold is false.");
			}
		}
		else {
		cocos2d::log("Error in logic.");
		}
	}

	log("source : %d destination %d capture %d", source, destination, capture);
	log("%d %d %d", noCapture[21], noCapture[22], noCapture[23]);
	log("%d %d %d", noCapture[18], noCapture[19], noCapture[20]);
	log("%d %d %d", noCapture[15], noCapture[16], noCapture[17]);
	log("%d %d %d %d %d %d", noCapture[9], noCapture[10], noCapture[11], noCapture[12], noCapture[13], noCapture[14]);
	log("%d %d %d", noCapture[6], noCapture[7], noCapture[8]);
	log("%d %d %d", noCapture[3], noCapture[4], noCapture[5]);
	log("%d %d %d", noCapture[0], noCapture[1], noCapture[2]);

	for (int j = 0; j < 24; j++)
	{
		noCapture[j] = 0;
	}

	return;
}


bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) {
	return true;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) { }
void GameScene::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) { }

bool GameScene::isValidMove(int in, int out)
{
	if (in == out)
		return false;

	if (in == 0)
		return(out == 1 || out == 9);
	if (in == 1)
		return(out == 0 || out == 2 || out == 4);
	if (in == 2)
		return(out == 1 || out == 14);
	if (in == 3)
		return(out == 4 || out == 10);
	if (in == 4)
		return (out == 3 || out == 5 || out == 1 || out == 7);
	if (in == 5)
		return (out == 4 || out == 13);
	if (in == 6)
		return (out == 7 || out == 11);
	if (in == 7)
		return(out == 4 || out == 6 || out == 8);
	if (in == 8)
		return(out == 12 || out == 7);
	if (in == 9)
		return(out == 0 || out == 10 || out == 21);
	if (in == 10)
		return(out == 9 || out == 11 || out == 3 || out == 18);
	if (in == 11)
		return(out == 6 || out == 10 || out == 15);
	if (in == 12)
		return(out == 8 || out == 13 || out == 17);
	if (in == 13)
		return(out == 12 || out == 14 || out == 5 || out == 20);
	if (in == 14)
		return(out == 2 || out == 23 || out == 13);
	if (in == 15)
		return(out == 11 || out == 16);
	if (in == 16)
		return(out == 15 || out == 17 || out == 19);
	if (in == 17)
		return(out == 16 || out == 12);
	if (in == 18)
		return(out == 10 || out == 19);
	if (in == 19)
		return(out == 18 || out == 20 || out == 16 || out == 22);
	if (in == 20)
		return(out == 19 || out == 13);
	if (in == 21)
		return(out == 9 || out == 22);
	if (in == 22)
		return(out == 21 || out == 19 || out == 23);
	if (in == 23)
		return(out == 22 || out == 14);

	return false;


}

bool GameScene::isMillFormed(int in, int player)
{
	if (in == 0)
		return((database[1] == player && database[2] == player) || (database[9] == player && database[21] == player));
	if (in == 1)
		return((database[0] == player && database[2] == player) || (database[4] == player && database[7] == player));
	if (in == 2)
		return((database[1] == player && database[0] == player) || (database[14] == player && database[23] == player));
	if (in == 3)
		return((database[4] == player && database[5] == player) || (database[10] == player && database[18] == player));
	if (in == 4)
		return ((database[3] == player && database[5] == player) || (database[1] == player && database[7] == player));
	if (in == 5)
		return ((database[4] == player && database[3] == player) || (database[13] == player && database[20] == player));
	if (in == 6)
		return ((database[7] == player && database[8] == player) || (database[11] == player && database[15] == player));
	if (in == 7)
		return((database[4] == player && database[1] == player) || (database[6] == player && database[8] == player));
	if (in == 8)
		return((database[12] == player && database[17] == player) || (database[7] == player && database[6] == player));
	if (in == 9)
		return((database[0] == player && database[21] == player) || (database[10] == player && database[11] == player));
	if (in == 10)
		return((database[9] == player && database[11] == player) || (database[3] == player && database[18] == player));
	if (in == 11)
		return((database[6] == player && database[15] == player) || (database[10] == player && database[9] == player));
	if (in == 12)
		return((database[8] == player && database[17] == player) || (database[13] == player && database[14] == player));
	if (in == 13)
		return((database[12] == player && database[14] == player) || (database[5] == player && database[20] == player));
	if (in == 14)
		return((database[2] == player && database[23] == player) || (database[13] == player && database[12] == player));
	if (in == 15)
		return((database[11] == player && database[6] == player) || (database[16] == player && database[17] == player));
	if (in == 16)
		return((database[15] == player && database[17] == player) || (database[19] == player && database[22] == player));
	if (in == 17)
		return((database[16] == player && database[15] == player) || (database[12] == player && database[8] == player));
	if (in == 18)
		return((database[10] == player && database[3] == player) || (database[19] == player && database[20] == player));
	if (in == 19)
		return((database[18] == player && database[20] == player) || (database[16] == player && database[22] == player));
	if (in == 20)
		return((database[19] == player && database[18] == player) || (database[13] == player && database[5] == player));
	if (in == 21)
		return((database[9] == player && database[0] == player) || (database[22] == player && database[23] == player));
	if (in == 22)
		return((database[21] == player && database[23] == player) || (database[16] == player && database[19] == player));
	if (in == 23)
		return((database[22] == player && database[21] == player) || (database[14] == player && database[2] == player));

	return false;
}

void GameScene::EndGame()
{
	if (times == 18)
	{
		blackPieces = 0;
		whitePieces = 0;

		//	----	Check if the game is over	----	//
		for (int i = 0; i < 24; i++)
		{
			if (database[i] == -1)
				blackPieces++;
			if (database[i] == 1)
				whitePieces++;
		}

		// Game over conditions
		if (blackPieces == 2)
		{
			TransitionToGameOverScene("GameOverSceneBlack");
		}
		if (whitePieces == 2)
		{
			TransitionToGameOverScene("GameOverSceneWhite");
		}
		//////////////////////////////////////////////////
	}
}

void GameScene::TransitionToGameOverScene(const std::string& sceneName)
{
	auto scene = Scene::create();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}