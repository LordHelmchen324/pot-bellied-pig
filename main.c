#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "source/run.h"



int main(int argc, char *args[]){

	int windowWidth = 1040;
    int windowHeight = 650;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;



	//start up SDL and react if it could not start for some reason
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){

		SDL_Quit();

    } else {	//Initialization was successful

        //initialize SDL_image
        IMG_Init(IMG_INIT_PNG);

        //initialize SDL_ttf
        TTF_Init();


		//open the window for the game
		window = SDL_CreateWindow("Hängebauchschwein-Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

        //create the renderer for the game
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);

		//check if the window and the renderer were successfully opened
		if(window == NULL || renderer == NULL){

            SDL_Quit();

        } else {	//the windows was successfully opened

			//open the game's main loop
			run(window, renderer);

        }

	}



    //shut everything down when the game is ended
    TTF_Quit();
    IMG_Quit();
	SDL_Quit();


	return 0;
}
