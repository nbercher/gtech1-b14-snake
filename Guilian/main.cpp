#include <ctime>
#include "classes.cpp"

#define NBL 16
#define NBC 32

int main (){
    MainSDLWindow window;
    window.init("Snake",1200,600);
    Snake snk;
    fruit fruit;
    int **tab = snk.getBlacklist();
    fruit.summon(tab);

    int GameIsRunning = 1;

    SDL_Event event;     
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);  

    do
    {     
        while(SDL_PollEvent(&event)){         
            if(event.type == SDL_QUIT){             
                GameIsRunning = 0;         
                }     
            } 
    snk.keyboard();
    snk.move();
    snk.eat(fruit);
    snk.colision();



    } 
    while (GameIsRunning = 1);
    

}