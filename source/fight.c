#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "containers.h"



//checks if the player collides with the enemy weakSpot and therefore beats the enemy
bool enemyLoses(Character *enemy, Character *player){


    if(SDL_HasIntersection(enemy -> weakSpot, player -> rect) == SDL_TRUE)
        return true;



    return false;
}



//cheks if the player collides with the enemies rectangle and therefore loses health / his whole life
bool playerLoses(Character *enemy, Character *player){


    if(SDL_HasIntersection(enemy -> rect, player -> rect) == SDL_TRUE)
        return true;



    return false;
}



//deletes an enemy from the list of enemies in the world
void deleteEnemy(Character *enemy, Character *previousEnemy, Information *info){


    //the element that is to be deleted is the first in the list
    if(previousEnemy == NULL){

        info -> world -> enemies = enemy -> next;

    } else {    //the element has any position but the first in the list

        previousEnemy -> next = enemy -> next;

    }



    free(enemy -> rect);
    free(enemy -> weakSpot);
    //SDL_DestroyTexture(enemy -> sprite);


    free(enemy);



    return;
}



//updates all sort of player vs. enemy contact
void fightUpdate(Information *info){


    Character *previousEnemy = NULL;
    Character *thisEnemy = info -> world -> enemies;


    //go through all enemies
    while(thisEnemy != NULL){

        if(enemyLoses(thisEnemy, info -> player) == true){

            deleteEnemy(thisEnemy, previousEnemy, info);

        } else if(playerLoses(thisEnemy, info -> player) == true){

            info -> player -> health = (info -> player -> health) - 1;

        }



        previousEnemy = thisEnemy;
        thisEnemy = thisEnemy -> next;

    }



    return;
}
