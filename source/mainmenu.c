#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"
#include "init.h"
#include "free.h"
#include "button.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5



int handleMainMenuEvents(Information *info){

    SDL_Event event;


    //pull events from the event queue until there is non left
    while(SDL_PollEvent(&event) == 1){

        if(event.type == SDL_QUIT){     //the user asked the game to quit

            return 1;

        } else if(event.type == SDL_KEYDOWN){    //a key was pressed down

            //check which key was pressed and act accordingly
            switch(event.key.keysym.scancode){

                case SDL_SCANCODE_A:    //left (from quit to play)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> quitButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> playButton;
                    break;

                case SDL_SCANCODE_LEFT:    //left (from quit to play)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> quitButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> playButton;
                    break;

                case SDL_SCANCODE_W:    //up (from quit to play)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> quitButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> playButton;
                    break;

                case SDL_SCANCODE_UP:    //up (from quit to play)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> quitButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> playButton;
                    break;

                case SDL_SCANCODE_D:    //right (from play to quit)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> playButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> quitButton;
                    break;

                case SDL_SCANCODE_RIGHT:    //right (from play to quit)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> playButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> quitButton;
                    break;

                case SDL_SCANCODE_S:    //down (from play to quit)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> playButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> quitButton;
                    break;

                case SDL_SCANCODE_DOWN:    //down (from play to quit)
                    if(info -> mainMenu -> selectedButton == info -> mainMenu -> playButton)
                        info -> mainMenu -> selectedButton = info -> mainMenu -> quitButton;
                    break;

                case SDL_SCANCODE_RETURN:   //select / execute currently chosed button
                    pressButton(info -> mainMenu -> selectedButton);
                    break;

                default:
                    break;

            }

        } else if(event.type == SDL_KEYUP){

            //check which key was released and act accordingly
            switch(event.key.keysym.scancode){

                case SDL_SCANCODE_RETURN:
                    releaseButton(info -> mainMenu -> selectedButton);

                default:
                    break;

            }

        }

    }




    return 0;
}



int handleMainMenuUpdates(Information *info){


    /*if(info -> world != NULL){

        //delete the loaded world
        freeWorld(info -> world);
        info -> world = NULL;

    }*/



    //mark the currently selected button as hovered over and all others as not hovered over
    info -> mainMenu -> playButton -> hover = false;
    info -> mainMenu -> quitButton -> hover = false;

    info -> mainMenu -> selectedButton -> hover = true;



    //check all the buttons for the released case and maybe execute the corresponding action
    if(info -> mainMenu -> playButton -> released){

        info -> GameState = LEVELMENU;

        info -> mainMenu -> playButton -> released = false;

    } else if(info -> mainMenu -> quitButton -> released){

        return 1;

    }




    return 0;
}



int updateMainMenu(Information *info){


    //handle events
    if(handleMainMenuEvents(info) == 1)
        return 1;


    //handle main menu updates
    if(handleMainMenuUpdates(info) == 1)
        return 1;



    return 0;
}
