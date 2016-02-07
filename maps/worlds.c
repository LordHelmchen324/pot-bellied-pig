#include <stdio.h>
#include <SDL.h>

#include "../source/containers.h"
#include "../source/utilities.h"
#include "../source/init.h"
#include "../source/graphics/graphic.h"
#include "../source/record.h"



void chunks_TestLevel(World *world, SDL_Renderer *renderer){
    /*
    
    //initialize landscape -> chunks
    Chunk *chunk = NULL;
    
    world -> chunks = malloc(sizeof(Chunk));
    initChunk(world -> chunks, 0, 450, 200, 200, renderer);
    
    chunk = world -> chunks;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 200, 350, 10, 300, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 210, 450, 250, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 560, 450, 250, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 610, 400, 200, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 660, 350, 150, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 710, 300, 100, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 860, 300, 100, 350, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1060, 350, 100, 300, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1260, 350, 150, 300, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1260, 300, 10, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1410, 400, 50, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1410, 450, 550, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 1950, 400, 10, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2010, 450, 100, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2110, 550, 150, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2260, 450, 450, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2360, 400, 350, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2410, 350, 300, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2460, 300, 250, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2860, 350, 10, 200, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 2860, 550, 300, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3210, 550, 50, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3310, 550, 50, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3410, 550, 800, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3505, 500, 10, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3660, 480, 200, 10, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3710, 410, 150, 10, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 3760, 340, 100, 10, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 4110, 440, 150, 10, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 4360, 550, 750, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 4610, 500, 500, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 4710, 450, 400, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 4810, 400, 250, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 5160, 450, 50, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 5160, 500, 100, 50, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 5160, 550, 600, 100, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, 5760, 0, 100, 650, renderer);
    
    */
    
    return;
}



void enemies_TestLevel(Information *info){
    
    
    SDL_Rect enemyRect = {0, 0, 30, 50};
    SDL_Surface *enemySurface = SDL_CreateRGBSurface(0, 30, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(enemySurface, NULL, SDL_MapRGB(enemySurface -> format, 180, 0, 0));
    SDL_Texture *enemyTexture = SDL_CreateTextureFromSurface(info -> renderer, enemySurface);
    SDL_FreeSurface(enemySurface);
    
    
    //initialize enemies
    enemyRect.x = 400;
    enemyRect.y = 400;
    info -> world -> enemies = malloc(sizeof(Character));
    initCharacter(info -> world -> enemies, enemyRect, enemyTexture, 300.0, 600.0, 12, 1, false);
    
    enemyRect.x = 333;
    enemyRect.y = 100;
    info -> world -> enemies -> next = malloc(sizeof(Character));
    initCharacter(info -> world -> enemies -> next, enemyRect, enemyTexture, 300.0, 1300.0, 12, 1, false);
    
    
    
    
    return;
}



void food_TestLevel(Information *info){
    
    
    //initialize food
    info -> world -> food = malloc(sizeof(Food));
    initFood(info -> world -> food, 730, 265, 8, info -> renderer);
    
    info -> world -> food -> next = malloc(sizeof(Food));
    initFood(info -> world -> food -> next, 922, 200 - 15 - 35, 4, info -> renderer);
    
    
    
    
    return;
}



void load_TestLevel(Information *info){
    
    
    World *world = info -> world;
    
    //---------------------------------------------------------------------------------------------
    
    //size of the landscape and therefore also of the scrollBase
    world -> width = 5850;
    world -> height = 650;
    
    //---------------------------------------------------------------------------------------------
    
    //load the chunks
    chunks_TestLevel(world, info -> renderer);
    
    //---------------------------------------------------------------------------------------------
    
    //create the landscape texture
    world -> landscape = SDL_CreateTexture(info -> renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, world -> width, world -> height);
    
    //---------------------------------------------------------------------------------------------
    
    //draw the background onto the landscape texture
    SDL_SetRenderTarget(info -> renderer, info -> world -> landscape);
    SDL_RenderClear(info -> renderer);
    SDL_SetRenderDrawColor(info -> renderer, 0x87, 0xCE, 0xEB, 0x00);   // <- colour: skyblue
    SDL_RenderFillRect(info -> renderer, NULL);
    
    //---------------------------------------------------------------------------------------------
    
    //draw all the chunks onto the landscape surface
    Chunk *chunk = info -> world -> chunks;
    
    while(chunk != NULL){
        
        drawChunk(chunk, info -> renderer);
        
        chunk = chunk -> next;
        
    }
    
    
    SDL_SetRenderTarget(info -> renderer, NULL);
    
    //---------------------------------------------------------------------------------------------
    
    //load the enemies
    enemies_TestLevel(info);
    
    //---------------------------------------------------------------------------------------------
    
    //load the food
    food_TestLevel(info);
    
    //---------------------------------------------------------------------------------------------
    
    //set the player's start position
    spawnPlayer(info -> player, 50, 400);
    
    //---------------------------------------------------------------------------------------------
    
    
    
    return;
}



void chunks_DemoLevel(World *world, SDL_Renderer *renderer){
    
    
    //load chunks sprites
    SDL_Texture *ground = LoadImage(renderer, "image/chunk_basicGround.png");
    SDL_Texture *box = LoadImage(renderer, "image/chunk_box.png");
    
    
    //initialize landscape -> chunks
    Chunk *chunk = NULL;
    
    world -> chunks = malloc(sizeof(Chunk));
    initChunk(world -> chunks, ground, 0, 485, 153, 285, renderer);
    
    chunk = world -> chunks;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 151, 485, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 302, 485, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 452, 429, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 603, 429, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 874, 429, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1025, 429, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1175, 369, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1325, 445, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1476, 445, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1627, 445, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1778, 445, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 1929, 373, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 2080, 373, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 3252, 454, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 3402, 388, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 3553, 388, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 3704, 388, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 3854, 388, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4005, 388, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4155, 474, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4306, 474, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4457, 474, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4607, 368, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4758, 368, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 4908, 580, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5059, 580, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5210, 580, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5361, 580, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5667, 580, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5817, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 5968, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6119, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6270, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6421, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6572, 400, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6722, 585, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 6873, 585, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 7024, 585, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 7175, 585, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 7326, 369, 153, 285, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, ground, 7477, 369, 153, 285, renderer);
    
    //---------------------------------------------------------------------------------------------
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 0, 185, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 60, 185, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 0, 245, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 60, 245, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 0, 305, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 60, 305, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 0, 365, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 60, 365, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 0, 425, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 60, 425, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2452, 451, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2452, 511, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2452, 571, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2452, 631, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2512, 451, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2512, 511, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2512, 571, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2512, 631, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2677, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2737, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2797, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2857, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2917, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2977, 537, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2704, 597, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2774, 597, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2869, 597, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 2960, 597, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4158, 414, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4158, 354, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4158, 294, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4218, 294, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4278, 294, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 4338, 294, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5029, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5089, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5149, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5209, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5269, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5329, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5389, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5449, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5509, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5569, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5629, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5689, 368, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5329, 248, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5389, 248, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5449, 248, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5329, 308, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5389, 308, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 5449, 308, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6485, 340, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6545, 340, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6485, 340, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6605, 340, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6665, 340, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6545, 280, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6605, 280, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6665, 280, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6605, 220, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 6665, 220, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7326, 309, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7386, 309, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7446, 309, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7326, 249, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7386, 249, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7446, 249, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7326, 189, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7386, 189, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 7446, 189, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 3030, 597, 60, 60, renderer);
    
    chunk = chunk -> next;
    
    chunk -> next = malloc(sizeof(Chunk));
    initChunk(chunk -> next, box, 3037, 537, 60, 60, renderer);
    
    
    
    
    return;
}



void enemies_DemoLevel(Information *info){
    
    info -> world -> enemies = NULL;
    
    
    SDL_Rect enemyRect = {0, 0, 59, 90};
    SDL_Surface *enemySurface = SDL_CreateRGBSurface(0, 30, 50, 32, 0, 0, 0, 0);
    SDL_FillRect(enemySurface, NULL, SDL_MapRGB(enemySurface -> format, 180, 0, 0));
    SDL_Texture *enemyTexture = SDL_CreateTextureFromSurface(info -> renderer, enemySurface);
    SDL_FreeSurface(enemySurface);
    
    
    //initialize enemies
    enemyRect.x = 1400;
    enemyRect.y = 330;
    info -> world -> enemies = malloc(sizeof(Character));
    initCharacter(info -> world -> enemies, enemyRect, enemyTexture, 150.0, 1300.0, 12, 1, false);
    
    enemyRect.x = 3330;
    enemyRect.y = 270;
    info -> world -> enemies -> next = malloc(sizeof(Character));
    initCharacter(info -> world -> enemies -> next, enemyRect, enemyTexture, 300.0, 1300.0, 12, 1, true);
    
    
    
    //give all enemies the chicken texture / animation
    Character *thisEnemy = info -> world -> enemies;
    
    while(thisEnemy != NULL){
        
        //load idle
        thisEnemy -> idle = malloc(sizeof(Frame));
        thisEnemy -> idle -> frameTexture = LoadImage(info -> renderer, "image/chicken_idle.png");
        thisEnemy -> idle -> time = 0;
        thisEnemy -> idle -> startTime = 0;
        thisEnemy -> idle -> next = NULL;
        
        
        //load runningLeft
        thisEnemy -> runningLeft = malloc(sizeof(Frame));
        thisEnemy -> runningLeft -> frameTexture = LoadImage(info -> renderer, "image/chicken_runLeft_1.png");
        thisEnemy -> runningLeft -> time = 250;
        thisEnemy -> runningLeft -> startTime = 0;

        thisEnemy -> runningLeft -> next = malloc(sizeof(Frame));
        thisEnemy -> runningLeft -> next -> frameTexture = LoadImage(info -> renderer, "image/chicken_runLeft_2.png");
        thisEnemy -> runningLeft -> next -> time = 250;
        thisEnemy -> runningLeft -> next -> startTime = 0;
        thisEnemy -> runningLeft -> next -> next = thisEnemy -> runningLeft;

    
        //load runningRight
        thisEnemy -> runningRight = malloc(sizeof(Frame));
        thisEnemy -> runningRight -> frameTexture = LoadImage(info -> renderer, "image/chicken_runRight_1.png");
        thisEnemy -> runningRight -> time = 250;
        thisEnemy -> runningRight -> startTime = 0;

        thisEnemy -> runningRight -> next = malloc(sizeof(Frame));
        thisEnemy -> runningRight -> next -> frameTexture = LoadImage(info -> renderer, "image/chicken_runRight_2.png");
        thisEnemy -> runningRight -> next -> time = 250;
        thisEnemy -> runningRight -> next -> startTime = 0;
        thisEnemy -> runningRight -> next -> next = thisEnemy -> runningRight;
        
        
        
        thisEnemy = thisEnemy -> next;
        
    }
    
    
    
    
    return;
}



void food_DemoLevel(Information *info){
    
    
    
    //initialize landscape -> chunks
    Food *food = NULL;
    
    info -> world -> food = malloc(sizeof(Food));
    initFood(info -> world -> food, 347, 432, 1, info -> renderer);
    
    food = info -> world -> food;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 575, 234, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 1122, 378, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 2030, 318, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 2501, 393, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 2915, 489, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 4238, 425, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 4251, 425, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 5039, 528, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 5049, 528, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 5060, 528, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 5621, 325, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 5689, 535, 1, info -> renderer);
    
    food = food -> next;
    
    food -> next = malloc(sizeof(Food));
    initFood(food -> next, 6787, 117, 1, info -> renderer);
    
    
    
    
    
    return;
}



void load_DemoLevel(Information *info){
    
    
    World *world = info -> world;
    
    //---------------------------------------------------------------------------------------------
    
    //load the level record
    world -> recordPath = "maps/record_DemoLevel.rcd";
    
    loadRecord(world);    
    
    //---------------------------------------------------------------------------------------------
    
    //size of the landscape and therefore also of the scrollBase
    world -> width = 7500;
    world -> height = 650;
    world -> finishLine = 7100;
    
    //---------------------------------------------------------------------------------------------
    
    //load the chunks
    chunks_DemoLevel(world, info -> renderer);
    
    //---------------------------------------------------------------------------------------------
    
    //create the landscape texture
    world -> landscape = SDL_CreateTexture(info -> renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, world -> width, world -> height);
    
    //---------------------------------------------------------------------------------------------
    
    //draw the background onto the landscape texture
    SDL_SetRenderTarget(info -> renderer, info -> world -> landscape);
    SDL_RenderClear(info -> renderer);
    SDL_SetRenderDrawColor(info -> renderer, 0x87, 0xCE, 0xEB, 0x00);   // <- colour: skyblue
    SDL_RenderFillRect(info -> renderer, NULL);
    
    //---------------------------------------------------------------------------------------------
    
    //draw all the chunks onto the landscape surface
    Chunk *chunk = info -> world -> chunks;
    
    while(chunk != NULL){
        
        drawChunk(chunk, info -> renderer);
        
        chunk = chunk -> next;
        
    }
    
    
    SDL_SetRenderTarget(info -> renderer, NULL);
    
    //---------------------------------------------------------------------------------------------
    
    //load the enemies
    enemies_DemoLevel(info);
    
    //---------------------------------------------------------------------------------------------
    
    //load the food
    food_DemoLevel(info);
    
    //---------------------------------------------------------------------------------------------
    
    //set the player's start position
    spawnPlayer(info -> player, 165, 390);
    
    //---------------------------------------------------------------------------------------------
    
    
    
    return;
}