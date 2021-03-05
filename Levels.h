#ifndef MAIN_LEVELS_H
#define MAIN_LEVELS_H


#include "Player.h"


struct Level
{
    explicit Level(const std::string &a_path);
    void Install(Image &screen);

    char Double_array[64][64];


private:
    int number;
    char type;

};

#endif //MAIN_LEVELS_H