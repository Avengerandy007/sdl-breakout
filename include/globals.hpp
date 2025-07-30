#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "window.hpp"

class MovableObject;
class Scene;

extern Window* mainWindow;
extern Scene* scene;
extern MovableObject* player;
extern bool running;

template<typename T>
int FindIndexOf(T* myObj, std::vector<T*>* list){
	int i = 0;
	for(T* obj : *list){
		if (obj == myObj){
			return i; 
		}
		i++;
	}

	return -1;
}

int randomInt(int min, int max);
