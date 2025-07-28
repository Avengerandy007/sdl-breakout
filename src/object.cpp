#include "../include/object.hpp"
#include "../include/globals.hpp"
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

void MovableObject::Update(){
	KeepRectAtPos();
}

void MovableObject::KeepRectAtPos(){
	rect.x = pos.X;
	rect.y = pos.Y;
}
