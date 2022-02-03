#pragma once
#include "body.hpp"

class Snake {
    public:
        Snake();
        ~Snake();
        void keyboard();
        void move();
        void newTail();
        string getDir();
        int **getBlacklist();
        void eat(fruit fruit);
        body head;
        body tail;
    private:
        string dir;
        int **blackList;
};   