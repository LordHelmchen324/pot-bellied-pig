#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"
#include "game.h"
#include "mainmenu.h"
#include "levelmenu.h"
#include "startscreen.h"
#include "deathscreen.h"
#include "winscreen.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6



int Update(Information *info){


    //check the GameState and execute the corresponding updates
    switch(info -> GameState){

        case QUIT:
            return 1;
            break;

        case STARTSCREEN:
            if(startScreenUpdate(info) == 1)
                return 1;
            break;

        case MAINMENU:
            if(updateMainMenu(info) == 1)
                return 1;
            break;

        case LEVELMENU:
            if(updateLevelMenu(info) == 1)
                return 1;
            break;

        case INGAME:
            if(updateGame(info) == 1)
                return 1;
            break;

        case DEATHSCREEN:
            if(deathScreenUpdate(info) == 1)
                return 1;
            break;

        case WINSCREEN:
            if(winScreenUpdate(info) == 1)
                return 1;
            break;

        default:
            break;

    }


    return 0;

}
