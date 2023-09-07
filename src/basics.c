#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "init.h"

bool InitWindow(SDL_Window *window)
{
    if(window == NULL)
    {
        printf("Unable to create window: %s\n", SDL_GetError());
        return false;
    } else if (window!=NULL)
    {
        printf("Window Created\n");
    }
    return true;
}
bool InitRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
    if(window == NULL)
    {
        printf("Window does not exist: %s\n", SDL_GetError());
    }
    if(renderer == NULL)
    {
        printf("Unable to create renderer: %s\n", SDL_GetError());
        return false;
    } else 
    {
        printf("Renderer Created\n");
    }
    return true;
}

bool input()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return true;
                break;
        }
    }

    return false;
}

void CleanQuit(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}