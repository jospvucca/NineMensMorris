#include "MainScene.h"

bool MainScene::init() {
	if (!Scene::init()) {
		return false;
	}

	//Create an instance of BackgroundLayer
	auto backgroundLayer = BackgroundLayer::create();
	if (backgroundLayer) {
		this->addChild(backgroundLayer);
	}

	//TODO: add other game scene elements

	return true;
}