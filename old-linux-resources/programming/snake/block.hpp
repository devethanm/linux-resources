#pragma once

class Block {
	private:
		int x, y;

	public:
		Block();
		Block(int xPos, int yPos);

		int getX();
		int getY();

		void setPos(int xPos, int yPos);
};
