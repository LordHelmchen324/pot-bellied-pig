#include <stdint.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#define FPS 120



void limitFPS(uint32_t startTick){
    
    
    if((1000 / FPS) > SDL_GetTicks() - startTick){
        
        SDL_Delay((1000 / FPS) - (SDL_GetTicks() - startTick));

    } else {
        
        printf("slowFrame\n");
        
    }
    
}



SDL_Texture *LoadImage(SDL_Renderer *renderer, char *path){
    
    
    SDL_Texture *texture = NULL;
    SDL_Surface *temp = NULL;
    
    
    temp = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    
    
    SDL_FreeSurface(temp);
    temp = NULL;
    
    
    
    return texture;
}