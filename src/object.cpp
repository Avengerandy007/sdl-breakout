#include "../include/object.hpp"
#include "../include/Scene.hpp"
#include "../include/globals.hpp"
#include <iostream>
#include <vector>

std::vector<Object*> Object::totalObjects;

//Object class definition
void Object::Update(){
	Render();
}

Object::Object(){
	SetColors();
	totalObjects.push_back(this);	
	rect.x = 0;
	rect.y = 0;
	rect.w = 50;
	rect.h = 30;
	if (IsColorBlack()){
		SetColors();
	}
}

Object::~Object(){
	int i = FindIndexOf<Object>(this, &totalObjects); //Find the index of this object in the list
	totalObjects.erase(totalObjects.begin() + i); //And remove it
	scene->blocks.erase(scene->blocks.begin() + FindIndexOf<Object>(this, &scene->blocks));
}

void Object::Render(){
	SDL_SetRenderDrawColor(mainWindow->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(mainWindow->renderer, &rect);
	SDL_RenderFillRect(mainWindow->renderer, &rect);

}

//MovableObject class definition
void MovableObject::Move(){
	pos.X += speed * dir.X;
	pos.Y += speed * dir.Y;
}

MovableObject::MovableObject(){
	speed = 1;
	rect.w = 25;
	rect.h = 25;
}

void MovableObject::Update(){
	KeepRectAtPos();
	Object::Update();
}

void MovableObject::KeepRectAtPos(){
	rect.x = pos.X;
	rect.y = pos.Y;
}

//Ball class defs
void Ball::Reflect(){
	dir.X = -dir.X;
	dir.Y = -dir.Y;
}

bool Ball::CheckCollsion(Object* obj){
	if ((((obj->rect.x <= pos.X) && (pos.X <= obj->rect.x + obj->rect.w)) || (pos.X + rect.w >= obj->rect.x)) && ((pos.X + rect.w <= obj->rect.x + obj->rect.w)) && (pos.Y + rect.h <= obj->rect.y + obj->rect.h) && (pos.Y + rect.h >= obj->rect.y)){
		return true;
	}else{
		return false;
	}
}

Ball::Ball(){
	dir.X = 0;
	dir.Y = -1;
}

void Ball::Update(){
	Move();
	MovableObject::KeepRectAtPos();
	Object::Render();
	if (CheckCollsion(player)){
		Reflect();
	}
	for(Object* block : scene->blocks){
		if (CheckCollsion(block)){
			delete block;
			Reflect();
		}
	}
}
