#include <SDL2/SDL.h>
#include <stdio.h>

#include "containers.h"
#include "graphic.h"
#include "ingame.h"

#define IS_FPS_LIMITED 1
#define TARGET_FPS 60

int update(double dt, Information *info) {
    info->timeStep = dt / 1000;
    return updateGame(info);
}

void draw(Information *info) {
    GraphicUpdate(info);
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

void gameLoop(SDL_Window *window, SDL_Renderer* renderer, Information *info) {
    int quit = 0; double dt = 0;
    while (!quit) {
        dt = timing();
        quit = update(dt, info);
        draw(info);
    }
}
