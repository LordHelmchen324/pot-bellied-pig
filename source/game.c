#include <SDL2/SDL.h>
#include <stdio.h>

#include "gameobject.h"

#include "game.h"

#define IS_FPS_LIMITED 1
#define TARGET_FPS 60

GameState makeGameState(SDL_Window *window, SDL_Renderer *renderer) {
    GameState state;
    state.window = window;
    state.renderer = renderer;
    state.camera.x = 0; state.camera.y = 0; 
    SDL_GetWindowSize(window, &state.camera.w, &state.camera.h);
    for (int i = 0; i < N_GAMEOBJECTS; i++) state.objects[i] = nullObject();
    return state;
}

void runGame(SDL_Window *window, SDL_Renderer *renderer) {
    GameState state = makeGameState(window, renderer);

    int quit = 0; double dt = 0;
    while (!quit) {
        dt = timing();
        quit = updateGameState(&state, dt);
        drawGameState(&state);
    }
}

double timing() {
    static int lastTime = 0;
    int currentTime = SDL_GetTicks();
    double dt = (double)(currentTime - lastTime);

    if (IS_FPS_LIMITED && dt < 1000/TARGET_FPS) {
        SDL_Delay(1000/TARGET_FPS - dt);
        dt = 1000/TARGET_FPS;
    }

    lastTime = currentTime;
    return dt;
}

int updateGameState(GameState *state, double dt) {
    for (int i = 0; i < N_GAMEOBJECTS; i++) {
        GameObject o = state->objects[i];
        o.update(o.self, state, dt);
    }
    return 0;
}

void drawGameState(GameState *state) {
    for (int i = 0; i < N_GAMEOBJECTS; i++) {
        GameObject o = state->objects[i];
        o.draw(o.self, state->renderer);
    }
}
