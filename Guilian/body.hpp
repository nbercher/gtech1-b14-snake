#pragma once

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