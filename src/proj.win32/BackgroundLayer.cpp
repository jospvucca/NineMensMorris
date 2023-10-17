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
	//TODO: clean coding, this might be suitable for a seperate class, to decide later
	std::vector<std::string> searchPaths = FileUtils::getInstance()->getSearchPaths();
	searchPaths.insert(searchPaths.begin(), "textures");
	FileUtils::getInstance()->setSearchPaths(searchPaths);

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
	backgroundSprite->setPosition(Vec2((Director::getInstance()->getVisibleSize().width / 2),
		(Director::getInstance()->getVisibleSize().height / 2)));

	backgroundSprite->setScale(Director::getInstance()->getVisibleSize().width / backgroundSprite->getContentSize().width,
		Director::getInstance()->getVisibleSize().height / backgroundSprite->getContentSize().height);

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