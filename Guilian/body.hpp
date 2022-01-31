#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class body {
    public:
        body next();
        void print();
        int *getCoo();
    private:
        int coordonates[2];
};