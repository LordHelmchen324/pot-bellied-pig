#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"
#include "init.h"
#include "free.h"
#include "character.h"


int handleGameEvents(Information *info){

    SDL_Event event;


    //pull events from the event queue until there is non left
    while(SDL_PollEvent(&event) == 1){

        if(event.type == SDL_QUIT){     //the user asked the game to quit

            return 1;

        } else if(event.type == SDL_KEYDOWN){    //a key was pressed down

            //check which key was pressed and act accordingly
            switch(event.key.keysym.scancode){

                case SDL_SCANCODE_D:    //start to move player right
                    characterMoveRight(info -> player);
                    break;

                case SDL_SCANCODE_RIGHT:    //start to move player right
                    characterMoveRight(info -> player);
                    break;

                case SDL_SCANCODE_A:    //start to move player left
					characterMoveLeft(info -> player);
                    break;

                case SDL_SCANCODE_LEFT:    //start to move player left
					characterMoveLeft(info -> player);
                    break;

                case SDL_SCANCODE_SPACE:    //player jump
                    characterJump(info -> player, info);
                    break;

                case SDL_SCANCODE_W:    //player jump
                    characterJump(info -> player, info);
                    break;

                case SDL_SCANCODE_UP:    //player jump
                    characterJump(info -> player, info);
                    break;

                default:
                    break;

            }


        } else if(event.type == SDL_KEYUP){     //a key was released

            //check which key was released and act accordingly
            switch(event.key.keysym.scancode){

                case SDL_SCANCODE_D:    //stop to move player right
                    characterStopRight(info -> player);
                    break;

                case SDL_SCANCODE_RIGHT:    //stop to move player right
                    characterStopRight(info -> player);
                    break;

                case SDL_SCANCODE_A:    //stop to move player left
                    characterStopLeft(info -> player);
                    break;

                case SDL_SCANCODE_LEFT:    //stop to move player left
                    characterStopLeft(info -> player);
                    break;

                default:
                    break;

            }


        }

    }


    return 0;
}


void handleUpdates(Information *info){


    //check for updates on player
    characterUpdates(info -> player, info);





    //check updates for the world / landscape
    // TODO



    return;
}



int updateGame(Information *info){

    //handle events
    if(handleGameEvents(info) == 1)
        return 1;



    //handle updates
    handleUpdates(info);





    return 0;

}
