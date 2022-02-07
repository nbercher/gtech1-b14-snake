#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "body.hpp"

#define NBL 16
#define NBC 32

int main()
{
    printf("salut");
    srand((unsigned int)time(0));
    MainSDLWindow window;
    window.init("Snake", 1200, 600);
    
    Snake snk;
    fruit fruit;
    fruit.summon(&snk);

    int GameIsRunning = 1;


    int frame_delay;
    Uint32 frame_start;

    do
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                GameIsRunning = 0;
            }
        }

        snk.keyboard();
        snk.move();
        SDL_Delay(1000);
        
        cout << "test1" << endl;

        int test = 0;
        //test = snk.colision();
        if (test == 1)
        {
            GameIsRunning = 0;
        }

        cout << "GameIsRunning" << GameIsRunning << endl;
        if (GameIsRunning == 0) break;
        continue;
        
        cout << "test2" << endl;
        int a, b = fruit.getCoo();
        if (snk.eat(a, b) == 1)
        {
            fruit.summon(&snk);
        }

        frame_delay = 20 - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0)
        SDL_Delay(frame_delay);

    } while (GameIsRunning == 1);
}