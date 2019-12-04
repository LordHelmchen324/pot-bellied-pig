#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "containers.h"



//draws a character onto a renderer
void drawCharacter(Character *character, SDL_Renderer *renderer){


    SDL_RenderCopy(renderer, character -> sprite, NULL, character -> rect);



    return;
}



void updateAnimation(Character *character, Information *info){


    //check if character is animated
    if(character -> idle != NULL && character -> runningLeft != NULL && character -> runningRight != NULL){


        if(character -> movingRight == false && character -> movingLeft == false){

        character -> sprite = character -> idle -> frameTexture;

        } else if(character -> movingLeft == true){

            if(character -> sprite != character -> runningLeft -> frameTexture)
                character -> runningLeft -> startTime = SDL_GetTicks();


            if(SDL_GetTicks() - character -> runningLeft -> startTime > character -> runningLeft -> time)
                character -> runningLeft = character -> runningLeft -> next;


            character -> sprite = character -> runningLeft -> frameTexture;

        } else if(character -> movingRight == true){

            if(character -> sprite != character -> runningRight -> frameTexture)
                character -> runningRight -> startTime = SDL_GetTicks();


            if(SDL_GetTicks() - character -> runningRight -> startTime > character -> runningRight -> time)
                character -> runningRight = character -> runningRight -> next;


            character -> sprite = character -> runningRight -> frameTexture;

        }


    }




    return;
}



//draws a chunk texture onto a renderer
void drawChunk(Chunk *chunk, SDL_Renderer *renderer){


    SDL_RenderCopy(renderer, chunk -> sprite, NULL, chunk -> worldPosition);



    return;
}



//draws a landscape texture to a renderer
void drawLandscape(SDL_Texture *landscape, SDL_Renderer *renderer){


    SDL_RenderCopy(renderer, landscape, NULL, NULL);



    return;
}



//draws a scrollBase texture to a renderer -> including computations what part of the scrollBase needs to be shown
void drawScrollBase(SDL_Texture *scrollBase, Information *info, SDL_Renderer *renderer){


    SDL_Rect scrollBaseSize;
    SDL_QueryTexture(scrollBase, NULL, NULL, &scrollBaseSize.w, &scrollBaseSize.h);


    //viewPort -> area of the landscape /scrollBase that is visible in the window
    SDL_Rect viewPort;
    viewPort.x = (info -> player -> rect -> x) - 300;
    viewPort.y = 0;
    viewPort.w = 1040;
    viewPort.h = 650;

    //handle the cases of the viewPort reaching either the left of the right end of the scrollBase
    if(viewPort.x < 0)
        viewPort.x = 0;
    else if(viewPort.x + viewPort.w > scrollBaseSize.w)
        viewPort.x = scrollBaseSize.w - viewPort.w;


    //position and size scrollBase that is to be seen in the window -> usually 0, 0 and the window's size
    SDL_Rect position;

    position.x = 0;
    position.y = 0;

    SDL_GetRendererOutputSize(renderer, &position.w, &position.h);


    //go ahead and actually draw the extract to the screen
    SDL_RenderCopy(renderer, scrollBase, &viewPort, &position);




    return;
}

//handles all the in game drawing for GameState = INGAME
void graphicsGame(Information *info){

    SDL_Renderer *renderer = info -> renderer;
    SDL_Texture *scrollBase = info -> scrollBase;


    //---------------------------------------------------------------------------------------------


    //Set tehe renderer's target to the scrollBase
    SDL_SetRenderTarget(renderer, scrollBase);



    //draw the landscape
    drawLandscape(info -> world -> landscape, renderer);



    //draw the player
    updateAnimation(info -> player, info);

    drawCharacter(info -> player, renderer);


    //---------------------------------------------------------------------------------------------


    //reset renderer target to window
    SDL_SetRenderTarget(renderer, NULL);


    //draw the suitable part of the scollBase to the screen
    drawScrollBase(scrollBase, info, renderer);



}

//general handler for the all graphic updates -> redirects to specific graphic updates for ingame, menu etc.
void GraphicUpdate(Information *info){
    SDL_Renderer *renderer = info -> renderer;

    SDL_RenderClear(renderer);
    graphicsGame(info);
    SDL_RenderPresent(info -> renderer);
}
