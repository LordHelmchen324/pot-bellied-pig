#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "containers.h"
#include "graphic.h"
#include "init.h"
#include "update.h"
#include "utilities.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6

void run(SDL_Window *window, SDL_Renderer *renderer) {
    bool quit = false;

    uint32_t lastTick = 0;
    uint32_t currentTick = 0;

    Information *info = malloc(sizeof(Information));
    initInfo(info, window, renderer);

    while(quit == false){

        //----------------------------------------------------------------------------------------------
        //gets the current runtime of SDL in order to limit the framerate at the end of the loop
        lastTick = currentTick;
        currentTick = SDL_GetTicks();

        info -> timeStep = (double)(currentTick - lastTick) / 1000.0;
        //----------------------------------------------------------------------------------------------




        quit = Update(info);


        GraphicUpdate(info);




        //----------------------------------------------------------------------------------------------
        //limits the framerate if the computer was able to run the game faster than the given framerate
        //limitFPS(currentTick);
        //----------------------------------------------------------------------------------------------

    }



    free(info);
    info = NULL;




    return;
}
