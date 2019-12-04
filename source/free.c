#include <stdbool.h>
#include <SDL2/SDL.h>

#include "containers.h"

#define DELETE_TEXTURE    true
#define KEEP_TEXTURE      false
#define DELETE_FOLLOWING  true
#define DELETE_ONLY_THIS  false



void freeCharacter(Character *character, bool deleteTexture, bool deleteFollowing){


    free(character -> rect);
    character -> rect = NULL;

    free(character -> weakSpot);
    character -> weakSpot = NULL;



    if(deleteTexture == true)
        SDL_DestroyTexture(character -> sprite);
    else
        character -> sprite = NULL;

    if(deleteFollowing == true && character -> next != NULL)
        freeCharacter(character -> next, deleteTexture, DELETE_FOLLOWING);



    free(character);
    character = NULL;



    return;
}



void freePlayer(Information *info){


    freeCharacter(info -> player, DELETE_TEXTURE, DELETE_ONLY_THIS);
    info -> player = NULL;



    return;
}



void freeChunks(Chunk *chunk){


    if(chunk -> next != NULL)
        freeChunks(chunk -> next);

    SDL_DestroyTexture(chunk -> sprite);

    free(chunk -> worldPosition);
    chunk -> worldPosition = NULL;



    free(chunk);
    chunk = NULL;



    return;
}







void freeWorld(World *world){


    freeChunks(world -> chunks);
    world -> chunks = NULL;

    SDL_DestroyTexture(world -> landscape);

    freeCharacter(world -> enemies, DELETE_TEXTURE, DELETE_FOLLOWING);




    return;
}
