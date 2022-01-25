#include "code.hpp"

MainSDLWindow fenetre;
string dir = "r";

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

void keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
     dir = "u";
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    dir = "d";
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    dir = "l";
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    dir = "r";
  }
}

void move(void){
    SDL_Rect square = fenetre.GetRect();
    if (dir == "r"){
        square.x += 20;
    }
    if (dir == "l"){
        square.x -= 20;
    }
    if (dir == "u"){
        square.y += 20;
    }
    if (dir == "d"){
        square.x -= 20;
    }
}

int main(){
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
    keyboard();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &square);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);


    }
}
