#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "src/basics.c"
#include "src/init.h"

int main(int argc, char**argv)
{
    (void)argc;
    (void)argv;
    
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        printf("Unable to initilize SDL2: %s\n", SDL_GetError());
    }
    
    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    bool running;

    if(InitWindow(window))
    {
        if(InitRenderer(window, renderer))
        {
            running = true;
        } else running = false;
    }
    while (running)
    {
        if(Input())
        {
            running = false;
        }
        SDL_RenderClear(renderer);
        Draw(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(FRAMERATE);
    }
    CleanQuit(window, renderer);
    return 0;
}