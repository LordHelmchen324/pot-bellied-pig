#include <stdbool.h>
#include <stdint.h>
#include <SDL.h>
#include <SDL_ttf.h>



//a struct containing a frame for an animation and a pointer to the next frame
struct FrameStruct{
    
    SDL_Texture *frameTexture;
    
    uint32_t time;
    uint32_t startTime;
    
    
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
    double realVerticalSpeed;
    double verticalSpeed;
    bool falling;
    
    int weight;
    int health;
    bool aggressive;
    
    SDL_Rect *weakSpot;
    
    
    SDL_Texture *sprite;
    
    
    Frame *idle;
    Frame *runningLeft;
    Frame *runningRight;
    
    
    struct CharacterStruct *next;
    
};

typedef struct CharacterStruct Character;



//a struct containing a piece of food that can be collected by the player to increase his weight (score)
struct FoodStruct{
    
    SDL_Rect *rect;
    SDL_Texture *sprite;
    
    int weight;
    
    
    struct FoodStruct *next;
    
};

typedef struct FoodStruct Food;



//a struct containing RECTANGULAR chunks of the landscape of a level / world
struct ChunkStruct{
    
    SDL_Texture *sprite;
    
    SDL_Rect *worldPosition;
    
    
    
    struct ChunkStruct *next;
    
};

typedef struct ChunkStruct Chunk;



//a struct containing a world -> example: Level 1, Testlevel or Farm etc.
struct WorldStruct{
    
    //the actual world / landscape
    Chunk *chunks;
    SDL_Texture *landscape;
    int width;
    int height;
    int finishLine;
    
    
    //stuff that is in the world
    Character *enemies;
    Food *food;
    
    
    char *recordPath;
    int record;
    
    
    //image -> playerLayer
    //background
    //position
    //past scores
    
};

typedef struct WorldStruct World;



//a struct holding a button in a menu or so
struct ButtonStruct{
    
    SDL_Rect *rect;
    
    SDL_Texture *texture_default;
    SDL_Texture *texture_hover;
    SDL_Texture *texture_pressed;
    
    
    bool hover;
    bool pressed;
    bool released;
    
};

typedef struct ButtonStruct Button;



//a struct containing the main menu
struct MainMenuStruct{
    
    SDL_Texture *background;
    SDL_Texture *header;
    
    
    Button *selectedButton;
    
    Button *playButton;
    Button *quitButton;
    
};

typedef struct MainMenuStruct MainMenu;



struct LevelMenuStruct{
    
    SDL_Texture *background;
    SDL_Texture *header;
    
    
    Button *selectedButton;
    
    Button *backButton;
    Button *demoLevel;
    
};

typedef struct LevelMenuStruct LevelMenu;



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
    
    
    //menu and screen elements
    MainMenu *mainMenu;
    LevelMenu *levelMenu;
    SDL_Texture *startScreen;
    SDL_Texture *deathScreen;
    SDL_Texture *winScreen;
    
    SDL_Texture *weightIcon;
    
    TTF_Font *font;
    
    
    //other utilities
    double timeStep;
    int GameState;
    uint32_t timer;
    
};

typedef struct InformationStruct Information;