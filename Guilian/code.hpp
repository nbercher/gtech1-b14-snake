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
        SDL_Rect rect;
    private:
        SDL_Window * window;
        SDL_Renderer * renderer;
};

class Snake {
    public:
    Snake();
    ~Snake();
    void keyboard(void);
    int length;
    int head[2];
    string dir;
};