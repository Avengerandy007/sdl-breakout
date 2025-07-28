#include <SDL2/SDL_events.h>
#include <cstdio>
#include "../include/window.hpp"
#include "../include/update.hpp"
#include "../include/object.hpp"
#include "../include/Scene.hpp"


bool running = true;
Scene* scene = new Scene(26);
MovableObject* player = new MovableObject(); 

void SetPlayer(){
	player->rect.w = 75;
	player->rect.h = 25;
	player->pos.X = 250;
	player->pos.Y = 400;
}

int main(){
	printf("Hello world from cpp\n");
	mainWindow->Setup();
	SetPlayer();
	Update();
	delete player;
	if (scene) delete scene;
	delete mainWindow;
	return 0;
}
