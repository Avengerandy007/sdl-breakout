#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "window.hpp"

extern Window* mainWindow;
class Scene;
extern Scene* scene;
class MovableObject;
extern MovableObject* player;

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

template<typename T>
void AppendToArray(T* myObj, T* array[]){
	for(int i = 0; sizeof(*array); i++){
		if(array[i] == NULL){
			array[i] = myObj;
			std::cout << "Added " << myObj << " to " << array << std::endl;
	 		break;
		}
	}
}

int randomInt(int min, int max);
