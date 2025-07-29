#include "../include/object.hpp"
#include "../include/Scene.hpp"
#include <cmath>
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
	dir.Y = -dir.Y;
}

bool checkingCollision = false;
bool Ball::CheckCollsion(Object* obj){
	int Ymax = pos.Y + rect.h;
	int Xmax = pos.X + rect.w;
	int objYmax = obj->rect.y + obj->rect.h;
	int objXmax = obj->rect.x + obj->rect.w;
	if(((pos.Y <= objYmax && pos.Y >= obj->rect.y) || (Ymax >= obj->rect.y && Ymax <= objYmax)) && ((pos.X >= obj->rect.x && pos.X <= objXmax) || (Xmax >= obj->rect.x && Xmax <= objXmax))){
		return true;
	}else{
		return false;
	}
}

Ball::Ball(){
	speed = 1;
	dir.X = 1;
	dir.Y = 1;
}

void Ball::CheckForWalls(){
	if (pos.X >= 650){
		dir.X = -1;
	}else if(pos.X <= 0){
		dir.X = 1;
	}else if (pos.Y <= 0){
		dir.Y = 1;
	}else if(pos.Y >= 450){
		scene->OnExit();
		scene = new Scene(20);
		player->pos.X = 250;
	}
}
void Ball::Update(){
	Move();
	MovableObject::KeepRectAtPos();
	Object::Render();
	if (CheckCollsion(player) && !checkingCollision){
		checkingCollision = true;
		Reflect();
	}
	for(Object* block : scene->blocks){
		if (CheckCollsion(block) && !checkingCollision){
			checkingCollision = true;
			delete block;
			Reflect();
		}
	}
	CheckForWalls();
	if (checkingCollision) checkingCollision = false;
}
