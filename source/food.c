#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "containers.h"



bool checkIfEaten(Food *food, Character *player){


    if(SDL_HasIntersection(food -> rect, player -> rect) == SDL_TRUE){

        return true;

    }



    return false;
}



void deleteFood(Food *food, Food *previousFood, Information *info){


    //if the food that has to be deleted is the first element of the list of foods
    if(previousFood == NULL){

        info -> world -> food = food -> next;

        free(food -> rect);
        SDL_DestroyTexture(food -> sprite);
        free(food);

    } else {    //all other positions in the list of foods

        previousFood -> next = food -> next;

        free(food -> rect);
        SDL_DestroyTexture(food -> sprite);
        free(food);


    }



    return;
}



void foodUpdate(Food *food, Character *player, Information *info){

    Food *previousFood = NULL;


    //update for all foods in the list until there is non left
    while(food != NULL){

        if(checkIfEaten(food, player) == true){

            player -> weight = (player -> weight) + (food -> weight);

            deleteFood(food, previousFood, info);

        }




        //go on to the next piece of food
        previousFood = food;
        food = food -> next;

    }



    return;
}
