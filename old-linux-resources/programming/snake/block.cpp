#include "block.hpp"

Block::Block() {
	x = 0;
	y = 0;
}

Block::Block(int xPos, int yPos) {
	x = xPos;
	y = yPos;
}

int Block::getX() { return x; }
int Block::getY() { return y; }

void Block::setPos(int xPos, int yPos) {
	x = xPos;
	y = yPos;
}
