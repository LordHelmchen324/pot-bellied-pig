#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"
#include "init.h"
#include "free.h"
#include "character.h"
#include "food.h"
#include "fight.h"
#include "record.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6



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



void handleAI(Information *info){


    Character *thisEnemy = info -> world -> enemies;

    while(thisEnemy != NULL){

        int distanceToPlayer = (thisEnemy -> rect -> x) - (info -> player -> rect -> x);

        if(distanceToPlayer < 200 && distanceToPlayer > -200 && thisEnemy -> aggressive == true){

            if(distanceToPlayer > 0)
                characterMoveLeft(thisEnemy);
            else if(distanceToPlayer < 0)
                characterMoveRight(thisEnemy);

        } else if(thisEnemy -> aggressive == false){

            if(checkCollisionRight(thisEnemy, info -> world, info) == true){

                characterStopRight(thisEnemy);
                characterMoveLeft(thisEnemy);

            } else if(checkCollisionLeft(thisEnemy, info -> world, info) == true){

                characterStopLeft(thisEnemy);
                characterMoveRight(thisEnemy);

            } else if(thisEnemy -> moveLeft == false && thisEnemy -> moveRight == false) {

                characterMoveLeft(thisEnemy);

            }

        }


        thisEnemy = thisEnemy -> next;

    }



    return;
}



void handleUpdates(Information *info){


    //check for updates on player
    characterUpdates(info -> player, info);

    fightUpdate(info);

    if(info -> player -> health <= 0 || info -> player -> yPos > 2000.0 || info -> player -> xPos > (double)(info -> world -> finishLine)){

        if(info -> player -> health <= 0 || info -> player -> yPos > 2000.0){

            info -> GameState = DEATHSCREEN;

        } else {

            if(checkRecord(info -> world, info -> player) == true)
                saveRecord(info -> world, info -> player);

            info -> GameState = WINSCREEN;

        }

        SDL_Delay(400);

    }



    //check for updates on the enemies
    Character *thisEnemy = info -> world -> enemies;

    while(thisEnemy != NULL){

        characterUpdates(thisEnemy, info);

        thisEnemy = thisEnemy -> next;

    }



    //check for updates for the food -> each food checks (not player / character) because food applies to the player only
    foodUpdate(info -> world -> food, info -> player, info);



    //check updates for the world / landscape
    // TODO



    return;
}



int updateGame(Information *info){

    //handle events
    if(handleGameEvents(info) == 1)
        return 1;


    //handle AI
    handleAI(info);


    //handle updates
    handleUpdates(info);





    return 0;

}
