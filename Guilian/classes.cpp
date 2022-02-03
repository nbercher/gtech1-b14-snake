#include <ctime>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "body.hpp"
#include "fruit.hpp"

#define NBL 16
#define NBC 32

// MAINSDLWINDOWS : création de fenêtre

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

//BODY : classe pour un morceau de serpent

body::body(){
    this -> x = NULL;
    this -> y = NULL;
    this -> prev = NULL;
}

body::~body(){}

void body::setPrev(body a){
    *prev = a;
}

int body::getCoo(){
    return x, y;
}

void body::setx(int a){
    x = a;
}

void body::sety(int b){
    x = b;
}

void body::move(){
    if (prev != NULL){
        int a, b = prev->getCoo();
        x = a;
        y = b;
        prev->move();
    }
}

int **body::getAllCoo(){
    int **mytab;
    if (prev != NULL){
        int **tab = prev->getAllCoo();

        mytab[0][0]=x;
        mytab[0][1]=y;

        int **newTab[(sizeof(tab)/sizeof(tab[0]))+1];

        std::copy(tab, tab + sizeof(tab)/sizeof(tab[0]), newTab);
        std::copy(mytab, mytab + 1, newTab + sizeof(tab)/sizeof(tab[0]));
 
        return *newTab;

    }else{
        mytab[0][0]=x;
        mytab[0][1]=y;
        return mytab;
    }

}

//SNAKE : class pour une entitée "serpent"

Snake::Snake(){
    head.setx(NBC/2);
    head.sety(NBL/2);
    tail = head;
    dir = "r";
}

Snake::~Snake(){
}

void Snake::move(void){

    tail.move();

    int x, y = head.getCoo();
    
    if ( dir == "d") {
        head.setx(x+1);
    }
    else if ( dir == "u") {
        head.setx(x-1);
    }
    else if ( dir == "r") {
        head.sety(y+1);
    }
    else if ( dir == "l") {
        head.sety(y-1);
    }
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

void Snake::eat(fruit fruit){
    int a, b = fruit.getCoo();
    int c, d = head.getCoo();
    if (a==c && b==d){
        int **tab = getBlacklist();
        fruit.summon(tab);
        newTail();
    }
}

void Snake::newTail(){
    body newTail;
    tail.getCoo();

}

string Snake::getDir(){
    return dir;
}

int **Snake::getBlacklist(){
    int **tab = tail.getAllCoo();
    return tab;
}

// FRUIT : objet fruit du jeu

fruit::fruit(){
    this -> x = NULL;
    this -> y = NULL;
    this -> type = 1;
}

fruit::~fruit(){}

int fruit::getCoo(){
    return x, y;
}

int fruit::getType(){
    return type;
}

void fruit::summon(int **blackList){

    int isOkay;
    do{
        srand((unsigned int)time(0));

        int a = rand()%NBC -1;
        int b = rand()%NBL -1;

        for(int i = sizeof(blackList)/sizeof(blackList[0]); i == 0; i-- ){
            if (a == blackList[i][0] && a == blackList[i][0]){
                isOkay = 2;
            }
        }
        if (isOkay == 0){isOkay = 1;}
        else{isOkay = 0;}

    }while(isOkay != 1);
}