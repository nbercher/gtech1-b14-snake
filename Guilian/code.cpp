#include "code.hpp"

#define NBL 16
#define NBC 32

MainSDLWindow fenetre;
Snake snk;
int **tab = NULL;


MainSDLWindow::MainSDLWindow(){
    this-> window, renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Rect MainSDLWindow::GetRect(){
    return rect;
}

int MainSDLWindow::Init(const char nom[], int width, int height){
    window = SDL_CreateWindow(nom,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width , height , SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        cout << "Erreur lors de la creation d'une fenetre :" << SDL_GetError();
        return EXIT_FAILURE;
    } 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        cout << "Erreur lors de la creation d'un renderer :" << SDL_GetError();
        return EXIT_FAILURE;
    }
    rect.x = 300;
    rect.y = 300;
    rect.h = 20;
    rect.w = 20;
    return EXIT_SUCCESS;
}

SDL_Renderer *MainSDLWindow::GetRenderer(void){
    return renderer;
}

Snake::Snake(){
    head[2];
    length = 2;
    dir = "r";
}

Snake::~Snake(){
}

void Snake::keyboard(void) {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP] && dir != "d") {
    dir = "u";
  }
  if (keystates[SDL_SCANCODE_DOWN] && dir != "u") {
    dir = "d";
  }
  if (keystates[SDL_SCANCODE_LEFT] && dir != "r") {
    dir = "l";
  }
  if (keystates[SDL_SCANCODE_RIGHT] && dir != "l") {
    dir = "r";
  }
}

int **tab_malloc() {
  int **tab_ = (int**)malloc(NBL * sizeof(int*));
  for(int l=0; l<NBL; l++)
    tab_[l] = (int*)malloc(NBC * sizeof(int));
  return tab_;
}

void initTab(){
    tab = tab_malloc();
    for (int l=0; l<NBL; l++) {
        for (int c=0; c<NBC; c++) {
	  tab[l][c] = 0; 
        }
    }
    tab[NBL/2][NBC/2] = 3;
    snk.head[0] = NBL/2;
    snk.head[1] = NBC/2;
}

void move(void){
    if ( snk.dir == "d") {
        snk.head[0] += 1;
    }
    else if ( snk.dir == "u") {
        snk.head[0] -= 1;
    }
    else if ( snk.dir == "r") {
        snk.head[1] += 1;
    }
    else if ( snk.dir == "l") {
        snk.head[1] -= 1;
    }
    tab[snk.head[0]][snk.head[1]] = snk.length+1;
}
   
void printTab(SDL_Renderer *renderer, SDL_Rect sprite_snake){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (int l=0; l<NBL; l++) {
        for (int c=0; c<NBC; c++) {
            if(tab[l][c] > 2){
                tab[l][c] -= 1;
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &sprite_snake);
                SDL_RenderPresent(renderer);
            }
            else if(tab[l][c] = 0){
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &sprite_snake);
                SDL_RenderPresent(renderer);
            }
            else if(tab[l][c] < 0){

            }else{
                tab[l][c] -= 1;
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawRect(renderer, &sprite_snake);
                SDL_RenderPresent(renderer);
            }
        }
    }
}

int main(){
    initTab();
    bool IsGameRunning = true;
    SDL_Rect square = fenetre.GetRect();
    fenetre.Init("une fenêtre", 600, 600);
    SDL_Renderer *renderer = fenetre.GetRenderer();
    SDL_Event event;
    
    
    while (IsGameRunning)
    {
        while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT){
            IsGameRunning = false;
        }
    }
    move();
    snk.keyboard();
    printTab(renderer,square);
    /*
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &square);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    */
    SDL_Delay(500);

    }
}
