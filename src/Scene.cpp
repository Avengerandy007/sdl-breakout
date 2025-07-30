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
	ball = new Ball();
	ball->pos.X = 250;;
	ball->pos.Y = 225;
}

Scene::Scene(unsigned short sizeOfArray){
	amountOfBlocks = sizeOfArray;
	blocks.resize(amountOfBlocks);
	Scene::SetupObjects();
}

void Scene::OnExit(){
	for(Object*& block : blocks){
		if(block) delete block;
		block = nullptr;
	}
	blocks.clear();
	if(ball) delete ball;
	ball = nullptr;
	player->speed = 10;
}

Scene::~Scene(){
	OnExit();
}
