#include "../include/Scene.hpp"
#include "../include/object.hpp"
#include "../include/globals.hpp"
#include <algorithm>
#include <cstdint>
#include <iterator>
#include <vector>

static std::vector<Scene> scenes;
unsigned short amountOfBlocks;

void Scene::SortBlocks(unsigned short& index, unsigned short& indexOnLine, unsigned short& currentLine){
	if (indexOnLine >= 13){
		indexOnLine = 0;
		currentLine++;
	}
	blocks[index]->rect.y = currentLine * 30;
	blocks[index]->rect.x = indexOnLine * 50;
	indexOnLine++;
	
	std::cout << "Moved object at index " << index << " to position (X,Y) (" << blocks[index]->rect.x << "," << blocks[index]->rect.y << ")" << std::endl;
}

void Scene::SortBalls(){
	uint32_t startLine = 350;
	for(uint32_t i = 0; i < 3; i++){
		balls[i]->pos.Y = startLine + i * 25;
	}
}

void Scene::SetupObjects(){
	unsigned short indexOnLine = 0;
	unsigned short currentLine = 0;
	for(auto& ptr : blocks){
		ptr = new Object();
	}
	for (unsigned short i = 0; i < amountOfBlocks; i++){
		SortBlocks(i, indexOnLine, currentLine);
	}
	
	for(auto& ptr : balls){
		ptr = new MovableObject();
		ptr->pos.X = 600;
	}
	SortBalls();
}

Scene::Scene(unsigned short sizeOfArray){
	amountOfBlocks = sizeOfArray;
	blocks.resize(amountOfBlocks);
	balls.resize(3);
	Scene::SetupObjects();
}

Scene::~Scene(){
	for(Object* block : blocks){
		delete block;
	}
	blocks.clear();
	for(MovableObject* ball : balls){
		delete ball;
	}
	balls.clear();
}
