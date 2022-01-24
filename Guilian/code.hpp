#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        int Init(const char name[], int width, int height);
        SDL_Renderer *GetRenderer();
        SDL_Rect GetRect();
    private:
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Rect rect;
};