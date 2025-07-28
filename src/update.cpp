#include "globals.hpp"
#include "update.hpp"
#include "object.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <ostream>

Window* mainWindow = new Window();

void PollEvents(){
	SDL_Event e;
	while(SDL_PollEvent(&e) >= 1){
		switch (e.type){
			case SDL_QUIT:
				running = false;
				break;
		}	
	}
}


void Update(){
	while(running){
		PollEvents();
		mainWindow->Render();
		for(Object* obj : Object::totalObjects){
			obj->Update();
		}
	}
}
