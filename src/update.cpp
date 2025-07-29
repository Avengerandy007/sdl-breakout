#include "../include/Scene.hpp"
#include "../include/update.hpp"
#include "../include/object.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
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
			case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_LEFT){
					player->dir.X = -1;
					player->Move();
				}else if(e.key.keysym.sym == SDLK_RIGHT){
					player->dir.X = 1;
					player->Move();
				}
				break;
		}	
	}
}

void CheckIfAllBlocksDestroyed(){
	if (scene->blocks.size() == 0){
		scene->OnExit();
		scene = new Scene(26);
		player->pos.X = 250;
	}
}

void Update(){
	while(running){
		PollEvents();
		mainWindow->Render();
		for(Object* obj : Object::totalObjects){
			obj->Update();
		}
		SDL_RenderPresent(mainWindow->renderer);
		CheckIfAllBlocksDestroyed();
		SDL_Delay(6);
	}
}
