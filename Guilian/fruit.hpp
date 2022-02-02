#pragma once

class fruit{
    public:
        fruit();
        ~fruit();
        int getCoo();
        int getType(); 
        void summon();
    private:
        int x;
        int y;
        int type;
};