#include <SDL2/SDL_events.h>
#include <cstdio>
#include "../include/window.hpp"
#include "../include/update.hpp"
#include "../include/globals.hpp"
#include "../include/object.hpp"
#include "../include/Scene.hpp"


bool running = true;
Scene* scene = new Scene(26);
int main(){
	printf("Hello world from cpp\n");
	mainWindow->Setup();
	Update();
	if (scene) delete scene;
	delete mainWindow;
}
