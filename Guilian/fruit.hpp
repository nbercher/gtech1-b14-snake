#pragma once

class fruit{
    public:
        fruit();
        ~fruit();
        int getCoo();
        int getType(); 
        void summon(int **);
    private:
        int x;
        int y;
        int type;
};