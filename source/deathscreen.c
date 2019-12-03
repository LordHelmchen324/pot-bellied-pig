#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6



int handleDeathScreenInput(Information *info){


    SDL_Event event;


    //pull events from the event queue until there is non left
    while(SDL_PollEvent(&event) == 1){

        if(event.type == SDL_QUIT){     //the user asked the game to quit

            return 1;

        } else if(event.type == SDL_KEYDOWN){    //a key was pressed down

            //check which key was pressed and act accordingly
            switch(event.key.keysym.scancode){

                case SDL_SCANCODE_RETURN:
                    info -> GameState = LEVELMENU;
                    break;

                default:
                    break;

            }

        }
    }




    return 0;
}



int deathScreenUpdate(Information *info){


    if(handleDeathScreenInput(info) == 1)
        return 1;



    return 0;
}
