#include "Scene.hpp"
#include "object.hpp"
#include "globals.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

static MovableObject player;
static std::vector<Scene> scenes;
unsigned short amountOfBlocks;

void Scene::SortThis(int index){
	blocks[index].rect.x = index * 50;
	if (blocks[index].rect.x >= 450){
		blocks[index].rect.y -= 50;
		blocks[index].rect.x = 0;
	}
	std::cout << "Moved object at index " << index << " to position (X,Y) (" << blocks[index].rect.x << "," << blocks[index].rect.y << ")" << std::endl;
}

void Scene::SetupObjects(){
	for (unsigned short i = 0; i < amountOfBlocks; i++){
		//AppendToArray<Object>(new Object(), &blocks);
		SortThis(i);
	}
}

Scene::Scene(unsigned short sizeOfArray){
	amountOfBlocks = sizeOfArray;
	blocks = new Object[amountOfBlocks];
	Scene::SetupObjects();
}
