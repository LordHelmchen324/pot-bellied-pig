#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "containers.h"
#include "utilities.h"
#include "graphics/graphic.h"
#include "../maps/worlds.h"

#define QUIT        0
#define STARTSCREEN 1
#define MAINMENU    2
#define LEVELMENU   3
#define INGAME      4
#define DEATHSCREEN 5
#define WINSCREEN   6

#define PLAYER_WEIGHT  60
#define PLAYER_HEALTH  1



void initFood(Food *food, int newPosX, int newPosY, int newWeight, SDL_Renderer *renderer){


    food -> sprite = LoadImage(renderer, "image/food_apple.png");



    food -> rect = malloc(sizeof(SDL_Rect));
    food -> rect -> x = newPosX;
    food -> rect -> y = newPosY;
    food -> rect -> w = 24;
    food -> rect -> h = 32;


    food -> weight = newWeight;


    food -> next = NULL;



    return;
}



void initCharacter(Character *character, SDL_Rect newRect, SDL_Texture *newSprite, int newSpeed, int newJumpStrength, int newWeight, int newHealth, bool newAgressive){


    character -> speed = newSpeed;
    character -> currentSpeed = 0;
    character -> movingLeft = false;
    character -> movingRight = false;
    character -> moveLeft = false;
    character -> moveRight = false;

    character -> rect = malloc(sizeof(SDL_Rect));
    character -> rect -> x = newRect.x;
    character -> rect -> y = newRect.y;
    character -> rect -> w = newRect.w;
    character -> rect -> h = newRect.h;

    character -> xPos = (double)newRect.x;
    character -> yPos = (double)newRect.y;

    character -> jumping = false;
    character -> jumpStrength = newJumpStrength;
    character -> realVerticalSpeed = 0.0;
    character -> verticalSpeed = 0.0;
    character -> falling = false;

    character -> weight = newWeight;
    character -> health = newHealth;
    character -> aggressive = newAgressive;

    character -> weakSpot = malloc(sizeof(SDL_Rect));
    character -> weakSpot -> x = newRect.x + 8;
    character -> weakSpot -> y = newRect.y - 1;
    character -> weakSpot -> w = newRect.w - 16;
    character -> weakSpot -> h = 1;


    character -> sprite = newSprite;


    character -> idle = NULL;
    character -> runningLeft = NULL;
    character -> runningRight = NULL;


    character -> next = NULL;


    return;
}



void initPlayer(Information *info){


    //get memory for the player
    info -> player = malloc(sizeof(Character));


    SDL_Rect playerRect = {0, 0, 52, 95};
    SDL_Texture *playerTexture = LoadImage(info -> renderer, "image/pig_idle.png");


    initCharacter(info -> player, playerRect, playerTexture, 300.0, 1600.0, PLAYER_WEIGHT, PLAYER_HEALTH, false);


    //load idle
    info -> player -> idle = malloc(sizeof(Frame));
    info -> player -> idle -> frameTexture = LoadImage(info -> renderer, "image/pig_idle.png");
    info -> player -> idle -> time = 0;
    info -> player -> idle -> startTime = 0;
    info -> player -> idle -> next = NULL;


    //load runningLeft
    info -> player -> runningLeft = malloc(sizeof(Frame));
    info -> player -> runningLeft -> frameTexture = LoadImage(info -> renderer, "image/pig_runLeft_1.png");
    info -> player -> runningLeft -> time = 250;
    info -> player -> runningLeft -> startTime = 0;

    info -> player -> runningLeft -> next = malloc(sizeof(Frame));
    info -> player -> runningLeft -> next -> frameTexture = LoadImage(info -> renderer, "image/pig_runLeft_3.png");
    info -> player -> runningLeft -> next -> time = 250;
    info -> player -> runningLeft -> next -> startTime = 0;
    info -> player -> runningLeft -> next -> next = info -> player -> runningLeft;


    //load runningRight
    info -> player -> runningRight = malloc(sizeof(Frame));
    info -> player -> runningRight -> frameTexture = LoadImage(info -> renderer, "image/pig_runRight_1.png");
    info -> player -> runningRight -> time = 250;
    info -> player -> runningRight -> startTime = 0;

    info -> player -> runningRight -> next = malloc(sizeof(Frame));
    info -> player -> runningRight -> next -> frameTexture = LoadImage(info -> renderer, "image/pig_runRight_3.png");
    info -> player -> runningRight -> next -> time = 250;
    info -> player -> runningRight -> next -> startTime = 0;
    info -> player -> runningRight -> next -> next = info -> player -> runningRight;



    return;
}



void spawnPlayer(Character *player, int x, int y){


    player -> currentSpeed = 0;

    player -> movingLeft = false;
    player -> movingRight = false;
    player -> moveLeft = false;
    player -> moveRight = false;

    player -> rect -> x = x;
    player -> rect -> y = y;
    player -> xPos = (double)x;
    player -> yPos = (double)y;

    player -> jumping = false;
    player -> realVerticalSpeed = 0.0;
    player -> verticalSpeed = 0;
    player -> falling = false;

    player -> weight = PLAYER_WEIGHT;
    player -> health = PLAYER_HEALTH;



    return;
}



void initChunk(Chunk *chunk, SDL_Texture *newSprite, int newPosX, int newPosY, int newWidth, int newHeight, SDL_Renderer *renderer){


    chunk -> sprite = newSprite;


    //create the chunk's rects for collision detection and drawing
    chunk -> worldPosition = malloc(sizeof(SDL_Rect));
    chunk -> worldPosition -> x = newPosX;
    chunk -> worldPosition -> y = newPosY;
    chunk -> worldPosition -> w = newWidth;
    chunk -> worldPosition -> h = newHeight;



    chunk -> next = NULL;



    return;
}



void initWorld(Information *info, char *worldName){


    //---------------------------------------------------------------------------------------------
    //definitions of the names of all the levels in the game
    //char *testLevel = "testLevel";
    //---------------------------------------------------------------------------------------------


    //allocate memory for the world
    info -> world = malloc(sizeof(World));



    //load the world depending on which world was asked to be loaded
    if(strcmp(worldName, "testLevel") == 0)
        load_TestLevel(info);
    else if(strcmp(worldName, "demoLevel") == 0)
        load_DemoLevel(info);



    //create the scrollBase with the same size as the landscape texture of the world
    info -> scrollBase = SDL_CreateTexture(info -> renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, info -> world -> width, info -> world -> height);




    return;
}



void initButton(Button *button, char *defaultPath, char *hoverPath, char *pressedPath, int positionX, int positionY, int width, int height, bool startsHovered, SDL_Renderer *renderer){


    button -> rect = malloc(sizeof(SDL_Rect));
    button -> rect -> x = positionX;
    button -> rect -> y = positionY;
    button -> rect -> w = width;
    button -> rect -> h = height;


    button -> texture_default = NULL;
    button -> texture_default = LoadImage(renderer, defaultPath);

    button -> texture_hover = NULL;
    button -> texture_hover = LoadImage(renderer, hoverPath);

    button -> texture_pressed = NULL;
    button -> texture_pressed = LoadImage(renderer, pressedPath);



    button -> hover = startsHovered;
    button -> pressed = false;
    button -> released = false;



    return;
}



void initMainMenu(Information *info){


    //get memory for the mainMenu and make a direct pointer
    info -> mainMenu = malloc(sizeof(MainMenu));
    MainMenu *mainMenu = info -> mainMenu;



    //load the mainMenu's textures
    mainMenu -> background = LoadImage(info -> renderer, "image/bg_mainMenu.png");
    mainMenu -> header = LoadImage(info -> renderer, "image/mainMenu_header.png");



    //load the mainMenu's buttons
    mainMenu -> playButton = malloc(sizeof(Button));
    initButton(mainMenu -> playButton, "image/mainMenu_playButtonDefault.png", "image/mainMenu_playButtonHover.png", "image/mainMenu_playButtonPressed.png", 407, 212, 225, 225, true, info -> renderer);

    mainMenu -> quitButton = malloc(sizeof(Button));
    initButton(mainMenu -> quitButton, "image/mainMenu_quitButtonDefault.png", "image/mainMenu_quitButtonHover.png", "image/mainMenu_quitButtonPressed.png", 787, 530, 233, 100, false, info -> renderer);


    mainMenu -> selectedButton = mainMenu -> playButton;




    return;
}



void initLevelMenu(Information *info){


    //get memory for the levelMenu and make a direct pointer
    info -> levelMenu = malloc(sizeof(MainMenu));
    LevelMenu *levelMenu = info -> levelMenu;



    //load the mainMenu's textures
    levelMenu -> background = LoadImage(info -> renderer, "image/bg_mainMenu.png");
    levelMenu -> header = LoadImage(info -> renderer, "image/mainMenu_header.png");



    //load the mainMenu's buttons
    levelMenu -> backButton = malloc(sizeof(Button));
    initButton(levelMenu -> backButton, "image/levelMenu_backButtonDefault.png", "image/levelMenu_backButtonHover.png", "image/levelMenu_backButtonPressed.png", 20, 530, 100, 100, false, info -> renderer);

    levelMenu -> demoLevel = malloc(sizeof(Button));
    initButton(levelMenu -> demoLevel, "image/levelMenu_demoLevelDefault.png", "image/levelMenu_demoLevelHover.png", "image/levelMenu_demoLevelPressed.png", 394, 175, 252, 300, true, info -> renderer);


    levelMenu -> selectedButton = levelMenu -> demoLevel;



    return;
}



void initMenus(Information *info){


    initMainMenu(info);

    initLevelMenu(info);



    return;
}



void initGraphics(Information *info, SDL_Window *newWindow, SDL_Renderer *newRenderer){

    //attach the window to info
    info -> window = newWindow;


    //attach the render to info
    info -> renderer = newRenderer;


    //initialize the scrollBase surface -> at this point NULL, as the scrollBase will be initialized with the world because its size is the same as the landscape's size
    info -> scrollBase = NULL;


    //load screens
    info -> startScreen = LoadImage(info -> renderer, "image/sdlScreen.png");
    info -> winScreen = LoadImage(info -> renderer, "image/winScreen.png");
    info -> deathScreen = LoadImage(info -> renderer, "image/deathScreen.png");


    //load the weight icon
    info -> weightIcon = LoadImage(info -> renderer, "image/weightIcon.png");


    //load the font
    info -> font = TTF_OpenFont("font.ttf", 104);




    return;
}



void initInfo(Information *info, SDL_Window *window, SDL_Renderer *renderer){


    //initialize utilities
    initGraphics(info, window, renderer);


    info -> timeStep = 0.0;
    info -> GameState = STARTSCREEN;


    //---------------------------------------------------------------------------------------------

    initPlayer(info);

    //---------------------------------------------------------------------------------------------

    info -> world = NULL;

    //---------------------------------------------------------------------------------------------

    initMenus(info);

    //---------------------------------------------------------------------------------------------

    info -> timer = SDL_GetTicks();



    return;
}
