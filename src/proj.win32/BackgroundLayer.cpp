#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer() {

}

BackgroundLayer::~BackgroundLayer() {

}

bool BackgroundLayer::init() {
	if (!Layer::init()) {
		return false;
	}


	//Load the background texture
	std::string fullPath = FileUtils::getInstance()->fullPathForFilename("../Resources/Textures/backgroundTexture.png");
	cocos2d::log(("Path: " + fullPath).c_str());

	FileUtils::getInstance()->addSearchPath("Texture");
	Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("backgroundTexture.png");
	if (texture == NULL) {
		//handle exception
		return false;
	}

	//Create sprite with texture
	Sprite* backgroundSprite = Sprite::createWithTexture(texture);
	if (!backgroundSprite) {
		//handle exception
		return false;
	}

	//Position the sprite in the center of the screen
	backgroundSprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));

	//Add the background sprite to this layer
	this->addChild(backgroundSprite);

	return true;
}

BackgroundLayer* BackgroundLayer::create() {
	BackgroundLayer* layer = new BackgroundLayer();
	if (layer && layer->init()) {
		layer->autorelease();
		return layer;
	}
	else
	{
		delete layer;
		return nullptr;
	}
}