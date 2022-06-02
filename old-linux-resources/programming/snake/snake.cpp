#include "snake.hpp"

Snake::Snake(int xVal, int yVal) {
	Block temp(xVal, yVal);
	blocks.push_back(temp);
}

int Snake::getXIndex(int xIndex) {
	return blocks[xIndex].getX();
}


int Snake::getYIndex(int yIndex) {
	return blocks[yIndex].getY();
}

void Snake::updateBlock(int index, int xPos, int yPos) {
	blocks[index].setPos(xPos, yPos);
}
