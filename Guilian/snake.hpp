#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include "body.hpp"

using namespace std;

class Snake {
    public:
        Snake();
        ~Snake();
        void keyboard();
        void move();
        int getLength();
        string getDir();
        body head;
        body tail;
    private:
        int length;
        string dir;

};   