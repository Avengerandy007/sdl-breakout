#pragma once
#include <vector>
#include "window.hpp"

extern Window* mainWindow;
class Object;
extern Object* testObj;

template<typename T>
int FindIndexOf(T *myObj, std::vector<T*>* list){
	int i = 0;
	for(T* obj : *list){
		if (obj == myObj){
			return i; 
		}
		i++;
	}

	return -1;
}
