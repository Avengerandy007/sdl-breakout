#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <cstdio>
#pragma once

class Window{
	SDL_Window* window;

public:
	SDL_Renderer* renderer;

	void Render();
	int Setup();
	~Window();
};
