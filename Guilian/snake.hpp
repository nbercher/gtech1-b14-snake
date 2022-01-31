#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Snake {
    public:
        Snake();
        ~Snake();
        void keyboard();
        void move();
        int getLength();
        int *getHead();
        string getDir();
        void setHead(int *);
    private:
        int length;
        int head[2];
        string dir;

};   