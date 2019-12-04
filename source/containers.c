#include <stdbool.h>
#include <SDL2/SDL.h>



//a struct containing a frame for an animation and a pointer to the next frame
struct FrameStruct{

    SDL_Surface *frameSurface;

    struct FrameStruct *next;

};

typedef struct FrameStruct Frame;



//a struct containing an animation and all nesecary data for it
struct AnimationStruct{

    Frame *frames;

    int frameDelay;

};

typedef struct AnimationStruct Animation;



//a struct containing a character -> this may be the player's character, an enemy or any other NPC
struct CharacterStruct{

    double speed;
    double currentSpeed;
    bool movingRight;
    bool movingLeft;
    bool moveLeft;
    bool moveRight;
    SDL_Rect *rect;
    double xPos;
    double yPos;

    bool jumping;
    double jumpStrength;
    double verticalSpeed;
    bool falling;

    int weight;
    int health;
    bool aggressive;

    SDL_Texture *sprite;
    Animation *runningAnimation;


    struct CharacterStruct *next;

};

typedef struct CharacterStruct Character;





//a struct containing RECTANGULAR chunks of the landscape of a level / world
struct ChunkStruct{

    SDL_Texture *sprite;

    SDL_Rect *worldPosition;
    SDL_Rect *screenPosition;


    struct ChunkStruct *next;

};

typedef struct ChunkStruct Chunk;



//a struct containing a world -> example: Level 1, Testlevel or Farm etc.
struct WorldStruct{

    //the actual world / landscape
    Chunk *chunks;
    SDL_Texture *landscape;


    //stuff that is in the world
    Character *enemies;


    //image -> playerLayer
    //background
    //position
    //past scores

};

typedef struct WorldStruct World;



//the struct containing every variable the game needs
struct InformationStruct{

    //local elements
    Character *player;
    World *world;


    //graphic elements
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowSurface;
    SDL_Texture *scrollBase;
    SDL_Rect *viewPort;


    //other utilities
    double timeStep;
    int *GameState;

};

typedef struct InformationStruct Information;
