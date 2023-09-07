#pragma once
bool InitWindow(SDL_Window *window);
bool InitRenderer(SDL_Window *window, SDL_Renderer *renderer);

bool Input();
void Draw(SDL_Renderer *renderer);

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int FRAMERATE = 60;