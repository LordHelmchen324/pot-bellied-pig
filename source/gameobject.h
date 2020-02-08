#pragma once

typedef struct {
    char *type;
    void *self;
    int (*update)(void*, GameState*, double);
    int (*draw)(void*, SDL_Renderer*);
} GameObject;

GameObject nullObject();