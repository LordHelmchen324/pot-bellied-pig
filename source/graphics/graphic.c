#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "../containers.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6



SDL_Texture *drawText(TTF_Font *font, char *string, SDL_Color colour, SDL_Renderer *renderer){


    SDL_Surface *temp = TTF_RenderUTF8_Blended(font, string, colour);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, temp);


    SDL_FreeSurface(temp);


    return textTexture;
}



//draws food onto a renderer
void drawFood(Food *food, SDL_Renderer *renderer){


    SDL_RenderCopy(renderer, food -> sprite, NULL, food -> rect);



    return;
}



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



void drawButton(Button *button, SDL_Renderer *renderer){


    if(button -> pressed){

        SDL_RenderCopy(renderer, button -> texture_pressed, NULL, button -> rect);

    } else if(button -> hover){

        SDL_RenderCopy(renderer, button -> texture_hover, NULL, button -> rect);

    } else {

        SDL_RenderCopy(renderer, button -> texture_default, NULL, button -> rect);

    }



    return;
}



void graphicsMainMenu(Information *info){


    SDL_RenderCopy(info -> renderer, info -> mainMenu -> background, NULL, NULL);

    SDL_Rect headerRect = {119, 30, 801, 50};
    SDL_RenderCopy(info -> renderer, info -> mainMenu -> header, NULL, &headerRect);

    drawButton(info -> mainMenu -> playButton, info -> renderer);
    drawButton(info -> mainMenu -> quitButton, info -> renderer);



    return;
}



void graphicsLevelMenu(Information *info){


    SDL_RenderCopy(info -> renderer, info -> levelMenu -> background, NULL, NULL);

    SDL_Rect headerRect = {119, 30, 801, 50};
    SDL_RenderCopy(info -> renderer, info -> levelMenu -> header, NULL, &headerRect);

    drawButton(info -> levelMenu -> backButton, info -> renderer);
    drawButton(info -> levelMenu -> demoLevel, info -> renderer);



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



    //draw the food
    Food *thisFood = info -> world -> food;

    while(thisFood != NULL){

        drawFood(thisFood, renderer);

        thisFood = thisFood -> next;

    }



    //draw the enemies
    Character *thisEnemy = info -> world -> enemies;

    while(thisEnemy != NULL){

        updateAnimation(thisEnemy, info);

        drawCharacter(thisEnemy, renderer);

        thisEnemy = thisEnemy -> next;

    }



    //draw the player
    updateAnimation(info -> player, info);

    drawCharacter(info -> player, renderer);


    //---------------------------------------------------------------------------------------------


    //reset renderer target to window
    SDL_SetRenderTarget(renderer, NULL);


    //draw the suitable part of the scollBase to the screen
    drawScrollBase(scrollBase, info, renderer);


    //draw weightIcon to the screen
    SDL_Rect weightIconRect = {925, 15, 102, 100};
    SDL_RenderCopy(renderer, info -> weightIcon, NULL, &weightIconRect);

    //write to the weight icon
    SDL_Color weightFontColour = {120, 120, 122};
    SDL_Rect weightTextPosition = {950, 40, 52, 52};
    char weightString[3];
    sprintf(weightString, "%u", info -> player -> weight);
    SDL_RenderCopy(renderer, drawText(info -> font, weightString, weightFontColour, renderer), NULL, &weightTextPosition);



    return;
}



void graphicsStart(Information *info){


    SDL_RenderCopy(info -> renderer, info -> startScreen, NULL, NULL);



    return;
}



void graphicsDeath(Information *info){


    SDL_RenderCopy(info -> renderer, info -> deathScreen, NULL, NULL);



    return;
}



void graphicsWin(Information *info){


    SDL_RenderCopy(info -> renderer, info -> winScreen, NULL, NULL);



    return;
}



//general handler for the all graphic updates -> redirects to specific graphic updates for ingame, menu etc.
void GraphicUpdate(Information *info){

    SDL_Renderer *renderer = info -> renderer;



    //Clear the renderer before beginngin to draw
    SDL_RenderClear(renderer);


    //check the GameState and execute the corresponding updates
    switch(info -> GameState){

        case STARTSCREEN:
            graphicsStart(info);
            break;

        case MAINMENU:
            graphicsMainMenu(info);
            break;

        case LEVELMENU:
            graphicsLevelMenu(info);
            break;

        case INGAME:
            graphicsGame(info);
            break;

        case DEATHSCREEN:
            graphicsDeath(info);
            break;

        case WINSCREEN:
            graphicsWin(info);
            break;

        default:
            break;

    }


    //present the updates of the renderer
    SDL_RenderPresent(info -> renderer);



    return;

}
