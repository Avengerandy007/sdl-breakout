#include "object.hpp"
#include <vector>
#pragma once

class Scene{
public:
	std::vector<Object*> blocks;//Array of all blocks in scene
	Ball* ball;

	void SortBlocks(unsigned short& index, unsigned short& indexOnLine, unsigned short& currentLine);
	void SortBalls();
	void SetupObjects();
	void OnExit();

	Scene(unsigned short sizeOfArray);
	~Scene();
};
