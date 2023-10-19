#include "MainScene.h"

#include "Intersections.h"
#include "Position.h"

bool MainScene::init() {
	if (!Scene::init()) {
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	cocos2d::log("Visible size: %.2f, %.2f", visibleSize.width, visibleSize.height);

	//Create an instance of BackgroundLayer
	auto backgroundLayer = BackgroundLayer::create();
	if (backgroundLayer) {
		this->addChild(backgroundLayer);
	}

	//TODO: add other game scene elements

	//Create intersections and positions
	Intersections intersections(visibleSize, 7, 7);
	Position position(intersections);

	// Define positions for the rings
	std::vector<std::pair<int, int>> ringOuter = { {0, 0}, {0, 3}, {0, 6}, {6, 0}, {6, 3}, {6, 6} };
	std::vector<std::pair<int, int>> ringMiddle = { {1, 1}, {1, 3}, {1, 5}, {5, 1}, {5, 3}, {5, 5} };
	std::vector<std::pair<int, int>> ringInner = { {2, 2}, {2, 3}, {2, 4}, {4, 2}, {4, 3}, {4, 4} };
	std::vector<std::pair<int, int>> lineMiddle = { {3, 0}, {3, 1}, {3, 2}, {3, 4}, {3, 5}, {3, 6} };

	for (const auto& pos : ringOuter) {
		//Create a circle sprite with grey color
		float radius = 10.0f;
		Color3B greyColor = Color3B(150, 150, 150);
		Sprite* circleSprite = position.createCircleSprite(greyColor, radius);

		//Position the circle sprite on the intersections
		circleSprite->setPosition(intersections.getIntersectionPosition(pos.first, pos.second));

		//Add the sprite to the scene
		addChild(circleSprite);
	}

	for (const auto& pos : ringMiddle) {
		//Create a circle sprite with grey color
		float radius = 10.0f;
		Color3B greyColor = Color3B(150, 150, 150);
		Sprite* circleSprite = position.createCircleSprite(greyColor, radius);

		//Position the circle sprite on the intersections
		circleSprite->setPosition(intersections.getIntersectionPosition(pos.first, pos.second));

		//Add the sprite to the scene
		addChild(circleSprite);
	}

	for (const auto& pos : ringInner) {
		//Create a circle sprite with grey color
		float radius = 10.0f;
		Color3B greyColor = Color3B(150, 150, 150);
		Sprite* circleSprite = position.createCircleSprite(greyColor, radius);

		//Position the circle sprite on the intersections
		circleSprite->setPosition(intersections.getIntersectionPosition(pos.first, pos.second));

		//Add the sprite to the scene
		addChild(circleSprite);
	}

	for (const auto& pos : lineMiddle) {
		//Create a circle sprite with grey color
		float radius = 10.0f;
		Color3B greyColor = Color3B(150, 150, 150);
		Sprite* circleSprite = position.createCircleSprite(greyColor, radius);

		//Position the circle sprite on the intersections
		circleSprite->setPosition(intersections.getIntersectionPosition(pos.first, pos.second));

		//Add the sprite to the scene
		addChild(circleSprite);
	}

	//Connect positions with neighbours
	//Create a DrawNode to draw lines
	DrawNode* drawNode = DrawNode::create();
	addChild(drawNode);

	//Set line color
	Color4F lineColor = Color4F::BLUE;

	//Iterate through game board positions
	for (int row = 0; row < 7; row++) {
		for (int column = 0; column < 7; column++) {
			//Get the valid neighbour positions for the current position
			std::vector<Vec2> neighbours = position.getNeighbours(row, column);

			//Draw lines for valid neighbours
			for (const auto& neighbour : neighbours) {
				drawNode->drawSegment(intersections.getIntersectionPosition(row, column), neighbour, 2, lineColor);
			}
		}
	}

	return true;
}