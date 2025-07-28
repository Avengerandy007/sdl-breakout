#include <SDL2/SDL_events.h>
#include <cstdio>
#include "window.hpp"
#include "update.hpp"
#include "globals.hpp"
#include "object.hpp"
#include "Scene.hpp"


bool running = true;
Scene* scene = new Scene(26);
int main(){
	printf("Hello world from cpp\n");
	mainWindow->Setup();
	Update();
	if (scene) delete scene;
	delete mainWindow;
}
