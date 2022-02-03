#pragma once

class body {
    public:
        body();
        ~body();
        void setPrev(body);
        void print();
        int getCoo();
        int **getAllCoo();
        void move();
        void setx(int a);
        void sety(int b);
        void setPrev(body);
    private:
        int x;
        int y;
        body *prev;
};