#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        int init(const char name[], int width, int height);
        SDL_Renderer *GetRenderer();
        SDL_Rect GetRect();
        SDL_Rect rect;
    private:
        SDL_Window * window;
        SDL_Renderer * renderer;
};
