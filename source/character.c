#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "containers.h"

#define CHARACTER_X     (character -> rect -> x)
#define CHARACTER_Y     (character -> rect -> y)
#define CHARACTER_WIDTH (character -> rect -> w)
#define CHARACTER_HEIGHT (character -> rect -> h)

#define CHUNK_X         (chunk -> worldPosition -> x)
#define CHUNK_Y         (chunk -> worldPosition -> y)
#define CHUNK_WIDTH     (chunk -> worldPosition -> w)
#define CHUNK_HEIGHT    (chunk -> worldPosition -> h)



//starts moving the character to the left
void characterMoveLeft(Character *character){


    character -> moveLeft = true;



	return;
}



//starts moving the character to the right
void characterMoveRight(Character *character){


    character -> moveRight = true;



    return;
}



//stops the character from moving to the left
void characterStopLeft(Character *character){


    character -> moveLeft = false;



    return;
}



//stops the character from moving to the left
void characterStopRight(Character *character){


    character -> moveRight = false;



    return;
}



//check if the character collides with the world on its right side and stop the character, if that's the case
bool checkCollisionLeft(Character *character, World *world, Information *info){


    bool collision = false;

    Chunk *chunk = world -> chunks;
    int xNext = (int)((double)CHARACTER_X + (character -> currentSpeed));



    while(chunk != NULL){

        //check if the character is next to the chunk -> vertically within its range
        if(CHARACTER_Y < CHUNK_Y + CHUNK_HEIGHT && CHARACTER_Y + CHARACTER_HEIGHT > CHUNK_Y){

            //check if the character is currently colliding with the chunk(the chunk being to the character's right) ... or will collide in the next frame
            if(CHARACTER_X <= CHUNK_X + CHUNK_WIDTH && CHARACTER_X + CHARACTER_WIDTH >= CHUNK_X + CHUNK_WIDTH){

                character -> movingLeft = false;
                character -> xPos = (double)(CHUNK_X + CHUNK_WIDTH);
                collision = true;

            } else if(xNext <= CHUNK_X + CHUNK_WIDTH && CHARACTER_X + CHARACTER_WIDTH >= CHUNK_X + CHUNK_WIDTH){

                character -> movingLeft = false;
                character -> xPos = (double)(CHUNK_X + CHUNK_WIDTH);
                collision = true;

            }

        }



        //move on to the next chunk
        chunk = chunk -> next;

    }



    return collision;
}



//check if the character collides with the world on its right side and stop the character, if that's the case
bool checkCollisionRight(Character *character, World *world, Information *info){


    bool collision = false;

    Chunk *chunk = world -> chunks;
    int xNext = (int)((double)CHARACTER_X + (character -> currentSpeed));



    while(chunk != NULL){

        //check if the character is next to the chunk -> vertically within its range
        if(CHARACTER_Y < CHUNK_Y + CHUNK_HEIGHT && CHARACTER_Y + CHARACTER_HEIGHT > CHUNK_Y){

            //check if the character is currently colliding with the chunk(the chunk being to the character's right) ... or will collide in the next frame
            if(CHARACTER_X + CHARACTER_WIDTH >= CHUNK_X && CHARACTER_X <= CHUNK_X){

                character -> movingRight = false;
                character -> xPos = (double)(CHUNK_X - CHARACTER_WIDTH);
                collision = true;

            } else if(xNext + CHARACTER_WIDTH >= CHUNK_X && CHARACTER_X <= CHUNK_X){

                character -> movingRight = false;
                character -> xPos = (double)(CHUNK_X - CHARACTER_WIDTH);
                collision = true;

            }

        }



        //move on to the next chunk
        chunk = chunk -> next;

    }



    return collision;
}



//lets the character jump
void characterJump(Character *character, Information *info){


    if(character -> jumping == false){

        character -> jumping = true;
        character -> realVerticalSpeed = (-1.0) * (character -> jumpStrength);
        character -> verticalSpeed = (character -> realVerticalSpeed) * (info -> timeStep);

    }


    return;
}



//check if the character collides with the ground or is mid-air, ergo falling -> also check if the character WOULD collide with the ground in the next frame
void checkIfFalling(Character *character, World *world, Information *info){

    Chunk *chunk = world -> chunks;
    int yNext = (int)((double)CHARACTER_Y + (character -> verticalSpeed));

    character -> jumping = true;



    while(chunk != NULL){     //loop through all chunks in the world

        //sort out cases of the character moving upwards at the time of the collision check -> collision when falling down
        if(character -> verticalSpeed >= 0){

            //check if the character is over the chunk -> horizontally within its range
            if(CHARACTER_X + CHARACTER_WIDTH > CHUNK_X && CHARACTER_X < CHUNK_X + CHUNK_WIDTH){

                //check if current position is on ... or next position is lower or on ... the chunk
                if(CHARACTER_Y + CHARACTER_HEIGHT >= CHUNK_Y && CHARACTER_Y <= CHUNK_Y){

                    character -> jumping = false;
                    character -> yPos = (double)(CHUNK_Y - CHARACTER_HEIGHT);

                } else if(yNext + CHARACTER_HEIGHT >= CHUNK_Y && CHARACTER_Y <= CHUNK_Y){

                    character -> jumping = false;
                    character -> yPos = (double)(CHUNK_Y - CHARACTER_HEIGHT);

                }

            }

        } else {    //otherwise check for collsion when jumping up and against a chunk above the character

            //check if the character is over the chunk -> horizontally within its range
            if(CHARACTER_X + CHARACTER_WIDTH > CHUNK_X && CHARACTER_X < CHUNK_X + CHUNK_WIDTH){

                //check if current position is on ... or next position is lower or on ... the chunk
                if(CHARACTER_Y <= CHUNK_Y + CHUNK_HEIGHT && CHARACTER_Y + CHARACTER_HEIGHT > CHUNK_Y + CHUNK_HEIGHT){

                    character -> verticalSpeed = 0.0;
                    character -> realVerticalSpeed = 0.0;
                    character -> yPos = (double)(CHUNK_Y + CHUNK_HEIGHT);

                } else if(yNext <= CHUNK_Y + CHUNK_HEIGHT && CHARACTER_Y + CHARACTER_HEIGHT > CHUNK_Y + CHUNK_HEIGHT){

                    character -> verticalSpeed = 0.0;
                    character -> realVerticalSpeed = 0.0;
                    character -> yPos = (double)(CHUNK_Y + CHUNK_HEIGHT);

                }

            }

        }



        chunk = chunk -> next;

    }



    return;
}



//handles horizontal movement
void horizontalMovement(Character *character, Information *info){


    //translate the urge to move to the actual fact of moving -> the latter can be falsified again in the follwing functions
    character -> movingLeft = character -> moveLeft;
    character -> movingRight = character -> moveRight;

    if(character -> movingLeft && character ->movingRight){

        character -> movingLeft = false;
        character -> movingRight = false;

    }



    checkCollisionLeft(character, info -> world, info);
    checkCollisionRight(character, info -> world, info);


    //check if the character is moving any direction and update its current speed
    if(character -> movingLeft == true){

        character -> currentSpeed = (-1.0) * (character -> speed) * (info -> timeStep);

    } else if(character -> movingRight == true){

        character -> currentSpeed = (character -> speed) * (info -> timeStep);

    } else {

        character -> currentSpeed = 0.0;

    }


    //update the current horizontal position
    if(character -> currentSpeed != 0.0){

        character -> xPos = (character -> xPos) + (character -> currentSpeed);

    }




    return;
}



//handles vertical movement
void verticalMovement(Character *character, Information *info){


    checkIfFalling(character, info -> world, info);



    if(character -> jumping == true){

        //moves character according to vertical speed and collision with ground
        character -> yPos = (character -> yPos) + (character -> verticalSpeed);

        //takes care of gravitational acceleration / deceleration
        character -> verticalSpeed = (character -> realVerticalSpeed) * (info -> timeStep);
        character -> realVerticalSpeed = (character -> realVerticalSpeed) + (6000.0 * (info -> timeStep));

    } else {

        character -> verticalSpeed = 0.0;
        character -> realVerticalSpeed = 0.0;

    }




    return;
}



//check the character for updates
void characterUpdates(Character *character, Information *info){


    //handle the character's movement on both axis
    horizontalMovement(character, info);
    verticalMovement(character, info);

    //translate floating point values to the pixels saved in the character's rectangle
    character -> rect -> x = (int)(character -> xPos);
    character -> rect -> y = (int)(character -> yPos);

    //update the position of the character's weakSpot
    character -> weakSpot -> x = character -> rect -> x + 8;
    character -> weakSpot -> y = character -> rect -> y - 1;



    return;
}
