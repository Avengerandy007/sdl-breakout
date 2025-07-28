#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include "vector.hpp"
#include "globals.hpp"
#include "color.hpp"
#include "window.hpp"

class Object{
public:
	SDL_Rect rect;
	Color color;
	static std::vector<Object*> totalObjects; 
	
	virtual void Update();
	Object();
	virtual ~Object();

private:
	void Render();

};

class MovableObject : public Object{
public:
	Vector2 pos;
	Vector2 dir;
	int speed;

	void Move();


	void Update() override;

private:
	void KeepRectAtPos();
};
