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

bool Input()
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

    return false; // check if the player has quit the game. if not return false.
}

void DrawRect(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    SDL_FRect rect;
    rect.w = w; rect.h = h;
    int xPos = ((WINDOW_WIDTH/2)+x)-(rect.w/2); // i have no idea why but using the other constants doesn't work if i have a settings.h file
    int yPos = ((WINDOW_HEIGHT/2)+y)-(rect.h/2); // i have no idea why but using the other constants doesn't work if i have a settings.h file
    rect.x = xPos; rect.y = yPos;
    SDL_RenderFillRectF(renderer, &rect);
}

void Draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Draw Player block
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    DrawRect(renderer, 0, 120, 65, 20);
    // Draw ball thing
    // Draw the cubes that break
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void CleanQuit(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}