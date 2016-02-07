#include <stdio.h>
#include <SDL.h>

#include "containers.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6



int handleStartScreenInput(Information *info){
    
    
    SDL_Event event;
    
    
    //pull events from the event queue until there is non left
    while(SDL_PollEvent(&event) == 1){
        
        if(event.type == SDL_QUIT){     //the user asked the game to quit
            
            return 1;
            
        }
        
    }
    
    
    
    
    return 0;
}



int startScreenUpdate(Information *info){
    
    
    if(handleStartScreenInput(info) == 1)
        return 1;
    
    
    if(SDL_GetTicks() > (info -> timer) + 4000)
        info -> GameState = MAINMENU;
    
    
    
    return 0;
}