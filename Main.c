#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Declarations.h"

void hello(){
	printf("THE ACTION IS REAL");
}

int main(int argv, char* args[]){

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("BOOTLEG PAINT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 480, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	ButtonsArray buttonsArr;

	buttonsArr_init(&buttonsArr, 1);
	createButton(&buttonsArr, 200, 200, 50, 50, hello);
	printf("Hello!");

	int gameLoop = 1;
	SDL_Event event;

	while (gameLoop) {

		SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    	SDL_RenderClear(renderer);
		renderButtons(&buttonsArr, renderer);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)!=0) {
			if (event.type == SDL_QUIT){
                gameLoop = 0;
            }
			buttonClickHandler(&event, &buttonsArr);
		}

		SDL_Delay(100);
	}
	 
	freeButtonArray(&buttonsArr);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}