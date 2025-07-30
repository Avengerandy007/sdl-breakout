#include "../include/object.hpp"
#include "../include/globals.hpp"
#include "../include/Scene.hpp"
#include <vector>

std::vector<Object*> Object::totalObjects;

//Object class definition
void Object::Update(){
	Render();
}

Object::Object(){
	SetColors();
	totalObjects.push_back(this);
	if (IsColorBlack()){
		SetColors();
	}
}

Object::~Object(){
	int i = FindIndexOf<Object>(this, &totalObjects); //Find the index of this object in the list
	if (i == -1) return;
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
void Ball::ReflectHor(){
	dir.Y = -dir.Y;
}

void Ball::ReflectVer(){
	dir.X = -dir.X;
}

	
bool checkingCollision = false;
bool Ball::CheckCollisionHorizontal(Object* obj){
	int Ymax = pos.Y + rect.h;
	int Xmax = pos.X + rect.w;
	int objYmax = obj->rect.y + obj->rect.h;
	int objXmax = obj->rect.x + obj->rect.w;

	return (((pos.Y <= objYmax && pos.Y >= obj->rect.y) || (Ymax >= obj->rect.y && Ymax <= objYmax)) && (pos.X < objXmax && Xmax > obj->rect.x));
}

bool Ball::CheckCollisionVertical(Object* obj){
	int Ymax = pos.Y + rect.h;
	int Xmax = pos.X + rect.w;
	int objYmax = obj->rect.y + obj->rect.h;
	int objXmax = obj->rect.x + obj->rect.w;

	return ((pos.X <= objXmax && pos.X >= obj->rect.x) || (Xmax >= obj->rect.x && Xmax <= objXmax)) && (pos.Y < objYmax && Ymax > obj->rect.y);
}

Ball::Ball(){
	speed = 1;
	dir.X = 1;
	dir.Y = 1;
}

void Ball::CheckForWalls(){
	if (pos.X >= 625){
		dir.X = -1;
	}else if(pos.X <= 0){
		dir.X = 1;
	}else if (pos.Y <= 0){
		dir.Y = 1;
	}else if(pos.Y >= 450){
		scene->OnExit();
		scene = new Scene(26);
		player->pos.X = 250;
	}
}

void Ball::Update(){
	CheckForWalls();
	if (pos.Y >= 450) return;
	Move();
	if (CheckCollisionHorizontal(player) && !checkingCollision){
		checkingCollision = true;
		ReflectHor();
	}else if(CheckCollisionVertical(player) && !checkingCollision){
		checkingCollision = true;
		ReflectVer();
	}
	for(Object* block : scene->blocks){
		if (checkingCollision) break;
		if (CheckCollisionHorizontal(block)){
			checkingCollision = true;
			int i = FindIndexOf<Object>(block, &scene->blocks);
			delete block;
			scene->blocks.erase(scene->blocks.begin() + i);
			ReflectHor();
		}else if (CheckCollisionVertical(block)){
			checkingCollision = true;
			int i = FindIndexOf<Object>(block, &scene->blocks);
			delete block;
			scene->blocks.erase(scene->blocks.begin() + i);
			ReflectVer();
		}
	}
	if (checkingCollision) checkingCollision = false;
	MovableObject::Update();
}
