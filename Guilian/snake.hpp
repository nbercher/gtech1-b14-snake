#pragma once
#include "body.hpp"
#include "fruit.hpp"

class Snake {
    public:
        Snake();
        ~Snake();
        void keyboard();
        void move();
        void newTail();
        int getDir();
        int testBody(int a, int b);
        void eat(fruit fruit, Snake snk);
        int colision();
        body head;
        body tail;
    private:
        int dir;
};   