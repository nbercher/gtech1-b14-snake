#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class body {
    public:
        void setNext(body);
        void print();
        int getCoo();
        void setCoo(int x, int y);
    private:
        int x;
        int y;
        body *next;
};