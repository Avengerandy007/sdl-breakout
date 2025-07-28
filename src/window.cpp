#include "../include/window.hpp"

void Window::Render(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

int Window::Setup(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("Could not init SDL video!");
		return -1;
	}

	window = SDL_CreateWindow("Shitty breakout", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 650, 450, SDL_WINDOW_SHOWN);
	
	if (window == NULL){
		printf("Could not create SDL window!");
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL){
		printf("Could not create SDL renderer!");
		return -1;
	}
	
	return 0;
}

Window::~Window(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
