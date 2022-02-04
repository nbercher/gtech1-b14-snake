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
        int **getBlacklist();
        void eat(fruit fruit);
        int colision();
        body head;
        body tail;
    private:
        int dir;
        int **blackList;
};   