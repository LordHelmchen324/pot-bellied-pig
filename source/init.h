void initFood(Food *food, int newPosX, int newPosY, int newWeight, SDL_Renderer *renderer);
void initCharacter(Character *character, SDL_Rect newRect, SDL_Texture *newSprite, int newSpeed, int newJumpStrength, int newWeight, int newHealth, bool newAgressive);
void initPlayer(Information *info);
void spawnPlayer(Character *player, int x, int y);
void initChunk(Chunk *chunk, SDL_Texture *newSprite, int newPosX, int newPosY, int newWidth, int newHeight, SDL_Renderer *renderer);
void thisWorld(World *world, SDL_Renderer *renderer);
void initWorld(Information *info, char *worldName);
void initGraphics(Information *info, SDL_Window *newWindow, SDL_Renderer *newRenderer);
void initInfo(Information *info, SDL_Window *window, SDL_Renderer *renderer);