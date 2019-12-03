#include <SDL2/SDL.h>

#include "containers.h"



void pressButton(Button *button){


    button -> pressed = true;



    return;
}



void releaseButton(Button *button){


    if(button -> pressed)
        button -> released = true;


    button -> pressed = false;



    return;
}
