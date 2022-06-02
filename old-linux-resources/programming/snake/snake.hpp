#pragma once
#include <vector>
#include "block.hpp"

class Snake {
	private:
		std::vector<Block> blocks;

	public:
		Snake(int xPos, int yPos);

		int getXIndex(int xIndex);
		int getYIndex(int yIndex);

		void updateBlock(int index, int xPos, int yPos);
};
