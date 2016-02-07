void freeCharacter(Character *character, bool deleteTexture);
void freePlayer(Information *info);
void freeChunks(Chunk *chunk);
void freeFood(Food *food, bool deleteTexture, bool deleteFollowing);
void freeWorld(World *world);