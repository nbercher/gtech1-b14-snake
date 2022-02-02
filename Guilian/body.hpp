#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class body {
    public:
        body();
        ~body();
        void setPrev(body);
        void print();
        int getCoo();
        void move();
        void setx(int a);
        void sety(int b);
    private:
        int x;
        int y;
        body *next;
        body *prev;
};