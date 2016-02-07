#include <stdio.h>
#include <SDL.h>

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



int handleLevelMenuEvents(Information *info){
    
    SDL_Event event;
    
    
    //pull events from the event queue until there is non left
    while(SDL_PollEvent(&event) == 1){
        
        if(event.type == SDL_QUIT){     //the user asked the game to quit
            
            return 1;
            
        } else if(event.type == SDL_KEYDOWN){    //a key was pressed down
            
            //check which key was pressed and act accordingly
            switch(event.key.keysym.scancode){
                    
                case SDL_SCANCODE_A:    //left in the menu (at end of levels left to backButton)
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> demoLevel)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> backButton;
                    break;
                    
                case SDL_SCANCODE_LEFT:    //left in the menu (at end of levels left to backButton)
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> demoLevel)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> backButton;
                    break;
                    
                case SDL_SCANCODE_D:    //right in the menu
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> backButton)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> demoLevel;
                    break;
                    
                case SDL_SCANCODE_RIGHT:    //right in the menu
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> backButton)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> demoLevel;
                    break;
                    
                case SDL_SCANCODE_W:    //up (from back to leftmost level)
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> backButton)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> demoLevel;
                    break;
                    
                case SDL_SCANCODE_UP:    //up (from back to leftmost level)
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> backButton)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> demoLevel;
                    break;
                    
                case SDL_SCANCODE_S:    //down any level to backButton
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> demoLevel)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> backButton;
                    break;
                    
                case SDL_SCANCODE_DOWN:    //down any level to backButton
                    if(info -> levelMenu -> selectedButton == info -> levelMenu -> demoLevel)
                        info -> levelMenu -> selectedButton = info -> levelMenu -> backButton;
                    break;
                    
                case SDL_SCANCODE_RETURN:
                    pressButton(info -> levelMenu -> selectedButton);
                    
                default:
                    break;
                                        
            }
            
        } else if(event.type == SDL_KEYUP){
            
            //check which key was released and act accordingly
            switch(event.key.keysym.scancode){
                    
                case SDL_SCANCODE_RETURN:
                    releaseButton(info -> levelMenu -> selectedButton);
                    
                default:
                    break;
                    
            }
            
        }
        
    }
    
    
    
    
    return 0;
}



void handleLevelMenuUpdates(Information *info){
    
    
    //mark the currently selected button as hovered over and all others as not hovered over
    info -> levelMenu -> backButton -> hover = false;
    info -> levelMenu -> demoLevel -> hover = false;
    
    info -> levelMenu -> selectedButton -> hover = true;
    
    
    
    //check all the buttons for the released case and maybe execute the corresponding action
    if(info -> levelMenu -> demoLevel -> released){
        
        initWorld(info, "demoLevel");
        info -> GameState = INGAME;
        
        info -> levelMenu -> demoLevel -> released = false;
        
    } else if(info -> levelMenu -> backButton -> released){
        
        info -> GameState = MAINMENU;
        
        info -> levelMenu -> backButton -> released = false;
        info -> levelMenu -> selectedButton = info -> levelMenu -> demoLevel;
        
    }
    
    
    
    return;
}



int updateLevelMenu(Information *info){
    
    
    //handle events
    if(handleLevelMenuEvents(info) == 1)
        return 1;
    
    
    //handle main menu updates
    handleLevelMenuUpdates(info);
    
    
    
    return 0;
}