#include "Scene.hpp"
#include "object.hpp"
#include "globals.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

static MovableObject player;
static std::vector<Scene> scenes;
unsigned short amountOfBlocks;

void Scene::SortThis(unsigned short& index, unsigned short& indexOnLine, unsigned short& currentLine){
	if (indexOnLine >= 13){
		indexOnLine = 0;
		currentLine++;
	}
	blocks[index]->rect.y = currentLine * 30;
	blocks[index]->rect.x = indexOnLine * 50;
	indexOnLine++;
	
	std::cout << "Moved object at index " << index << " to position (X,Y) (" << blocks[index]->rect.x << "," << blocks[index]->rect.y << ")" << std::endl;
}

void Scene::SetupObjects(){
	unsigned short indexOnLine = 0;
	unsigned short currentLine = 0;
	for (unsigned short i = 0; i < amountOfBlocks; i++){
		SortThis(i, indexOnLine, currentLine);
	}
}

Scene::Scene(unsigned short sizeOfArray){
	amountOfBlocks = sizeOfArray;
	blocks.resize(amountOfBlocks);
	for(auto& ptr : blocks){
		ptr = new Object();
	}
	Scene::SetupObjects();
}

Scene::~Scene(){
	for(Object* block : blocks){
		delete block;
	}
	blocks.clear();
}
