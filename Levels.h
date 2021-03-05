#ifndef MAIN_LEVELS_H
#define MAIN_LEVELS_H


#include "Player.h"


struct Level
{
    explicit Level(const std::string &a_path);
    void Install(Image &screen);

private:
    char double_array[64][64];
    int doors[4] = {0, 0, 0, 0};

};

#endif //MAIN_LEVELS_H