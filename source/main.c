#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "game.h"

#define WINDOW_WIDTH 1040
#define WINDOW_HEIGHT 650

int main(int argc, char *args[]) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Quit();
    } else {
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
		SDL_Window *window = SDL_CreateWindow("Hängebauchschwein-Simulator",
								  			  SDL_WINDOWPOS_UNDEFINED,
								  			  SDL_WINDOWPOS_UNDEFINED,
								  			  WINDOW_WIDTH,
								  			  WINDOW_HEIGHT,
								  			  SDL_WINDOW_SHOWN);
        SDL_Renderer *renderer = SDL_CreateRenderer(window,
													-1,
													SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

		if (window && renderer) runGame(window, renderer);

		TTF_Quit();
    	IMG_Quit();
		SDL_Quit();
	}

	return 0;
}
