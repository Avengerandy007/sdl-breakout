#include "object.hpp"
#include <vector>
#pragma once

class Scene{
	static MovableObject player;
	static std::vector<Scene> scenes;

public:
	std::vector<Object*> blocks;//Array of all blocks in scene

	void SortThis(unsigned short& index, unsigned short& indexOnLine, unsigned short& currentLine);
	void SetupObjects();

	Scene(unsigned short sizeOfArray);
	~Scene();
};
