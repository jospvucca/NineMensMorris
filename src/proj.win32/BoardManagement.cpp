#include "BoardManagement.h"

USING_NS_CC;

BoardManagement::BoardManagement() { }

std::vector<std::unique_ptr<Position>> BoardManagement::createPositions(cocos2d::Size& visibleSize, cocos2d::Vec2& origin) {
	//// First row of positions
	//Position pos0 = Position::Position(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 0)); // Top-left
	//Position pos1 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 0)); // Top-center
	//Position pos2 = Position::Position(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 0)); // Top-right

	//// Second row of positions
	//Position pos3 = Position::Position(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 1)); // Middle-left
	//Position pos4 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 1)); // Middle-center
	//Position pos5 = Position::Position(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 1)); // Middle-right

	//// Third row of positions
	//Position pos6 = Position::Position(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 2)); // Bottom-left
	//Position pos7 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 2)); // Bottom-center
	//Position pos8 = Position::Position(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 2)); // Bottom-right

	//// Fourth row of positions
	//Position pos9 = Position::Position(Vec2(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(0, 3)); // Top-left
	//Position pos10 = Position::Position(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(1, 3)); // Top-center
	//Position pos11 = Position::Position(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(2, 3)); // Top-right
	//Position pos12 = Position::Position(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(3, 3)); // Top-right
	//Position pos13 = Position::Position(Vec2(visibleSize.width / 1.53 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(4, 3)); // Top-right
	//Position pos14 = Position::Position(Vec2(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(5, 3)); // Top-right

	//// Fifth row of positions
	//Position pos15 = Position::Position(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(0, 4)); // Middle-left
	//Position pos16 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(1, 4)); // Middle-center
	//Position pos17 = Position::Position(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(2, 4)); // Middle-right

	//// Sixth row of positions
	//Position pos18 = Position::Position(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(0, 5)); // Bottom-left
	//Position pos19 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(1, 5)); // Bottom-center
	//Position pos20 = Position::Position(Vec2(visibleSize.width / 1.539 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(2, 5)); // Bottom-right

	//// Seventh row of positions
	//Position pos21 = Position::Position(Vec2(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(0, 6)); // Top-left
	//Position pos22 = Position::Position(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(1, 6)); // Top-center
	//Position pos23 = Position::Position(Vec2(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(2, 6)); // Top-right

	std::vector<std::unique_ptr<Position>> positions;

	// First row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 0)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 0)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 0)));

	// Second row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 1)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 1)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 1)));

	// Third row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(0, 2)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(1, 2)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 2.55 + origin.y), Vec2(2, 2)));

	// Fourth row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(0, 3)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(1, 3)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(2, 3)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(3, 3)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.53 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(4, 3)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.92 + origin.y), Vec2(5, 3)));

	// Fifth row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.33 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(0, 4)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(1, 4)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.734 + origin.x, visibleSize.height / 1.55 + origin.y), Vec2(2, 4)));

	// Sixth row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2.85 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(0, 5)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(1, 5)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.539 + origin.x, visibleSize.height / 1.255 + origin.y), Vec2(2, 5)));

	// Seventh row of positions
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 3.8 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(0, 6)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(1, 6)));
	positions.push_back(std::make_unique<Position>(Vec2(visibleSize.width / 1.355 + origin.x, visibleSize.height / 1.078 + origin.y), Vec2(2, 6)));

	return positions;
}
