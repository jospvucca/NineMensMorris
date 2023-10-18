#include "MainScene.h"

#include "Intersections.h"
#include "Position.h"

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

	//Create intersections and positions
	Intersections intersections(getContentSize(), 9, 9);
	Position position(intersections);
	for (int row = 1; row <= intersections.getNumRows(); row++) {
		for (int column = 1; column <= intersections.getNumColumns(); column++) {
			//Create a circle sprite with grey color
			float radius = 10.0f;
			Color3B greyColor = Color3B(150, 150, 150);
			Sprite* circleSprite = position.createCircleSprite(greyColor, radius);

			//Position the circle sprite on the intersections
			circleSprite->setPosition(intersections.getIntersectionPosition(row, column));

			//Add the sprite to the scene
			addChild(circleSprite);
		}
	}

	return true;
}