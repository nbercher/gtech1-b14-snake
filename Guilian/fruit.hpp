#pragma once
#include "snake.hpp"

class fruit{
    public:
        fruit();
        ~fruit();
        int getCoo();
        int getType(); 
        void summon(Snake snk);
    private:
        int x;
        int y;
        int type;
};