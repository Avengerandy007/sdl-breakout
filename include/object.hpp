#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include "vector.hpp"
#include "globals.hpp"
#include "color.hpp"
#include "window.hpp"
#include "dirVector.hpp"

class Object{
public:
	SDL_Rect rect = {0, 0, 50, 30};
	Color color;
	static std::vector<Object*> totalObjects; 
	
	virtual void Update();
	Object();
	virtual ~Object();

protected:
	void Render();
private:
	void SetColors(){
		color.r = randomInt(0, 255);
		color.g = randomInt(0, 255);
		color.b = randomInt(0, 255);
		color.a = 255;
	}

	bool IsColorBlack(){
		if (color.r == 0 && color.g == 0 && color.b == 0){
			return true;
		}else{
			return false;
		}
	}

};

class MovableObject : public Object{
public:
	Vector2 pos;
	DirVector2 dir;
	int speed;

	void Move();
	MovableObject();
	void Update() override;

protected:
	void KeepRectAtPos();
};

class Ball : public MovableObject{
	
	void ReflectHor();
	void ReflectVer();
	bool CheckCollisionHorizontal(Object* obj);
	bool CheckCollisionVertical(Object* obj);
	void CheckForWalls();
public:
	Ball();
	void Update() override;
};
