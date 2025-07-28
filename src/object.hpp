#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include "vector.hpp"
#include "globals.hpp"
#include "color.hpp"
#include "window.hpp"
#pragma once

class Object{
public:
	SDL_Rect rect;
	const Color color;
	static std::vector<Object*> totalObjects; 
	
private:
	void Render(){
		SDL_SetRenderDrawColor(mainWindow->renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawRect(mainWindow->renderer, &rect);
		SDL_RenderFillRect(mainWindow->renderer, &rect);
	}

public:
	virtual void Update(){
		Render();
	}

	Object(){
		totalObjects.push_back(this);	
		rect.x = 0;
		rect.y = 0;
		rect.w = 30;
		rect.h = 30;
	}

	virtual ~Object(){
		int i = FindIndexOf<Object>(this, &totalObjects); //Find the index of this object in the list
		totalObjects.erase(totalObjects.begin() + i); //And remove it
	}
};

class MovableObject : Object{
public:
	Vector2 pos;
	Vector2 dir;
	int speed;

	void Move(){
		pos.X += speed * dir.X;
		pos.Y += speed * dir.Y;
	}

	void KeepRectAtPos(){
		rect.x = pos.X;
		rect.y = pos.Y;
	}

	void Update() override{
		KeepRectAtPos();
	}
};

void SetCorrectPossition(Object* array[]);
