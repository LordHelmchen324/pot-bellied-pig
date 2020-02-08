#pragma once

#define N_GAMEOBJECTS 256

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect camera;
    GameObject objects[N_GAMEOBJECTS];
} GameState;

GameState makeGameState(SDL_Window *window, SDL_Renderer *renderer);
void runGame(SDL_Window *window, SDL_Renderer *renderer);
double timing();
int updateGameState(GameState *state, double dt);
void drawGameState(GameState *state);