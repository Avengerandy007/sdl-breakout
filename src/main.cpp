#include <SDL2/SDL_events.h>
#include <cstdio>
#include "window.hpp"
#include "update.hpp"
#include "globals.hpp"
#include "object.hpp"


bool running = true;
int main(){
	printf("Hello world from cpp\n");
	mainWindow->Setup();
	Update();
	delete mainWindow;
}
