#ifndef MAIN_LEVELS_H
#define MAIN_LEVELS_H


#include "Player.h"

struct Level
{
    explicit Level(const std::string &a_path);
    void Install(Image &screen);
    void Make_doors_coord();

    int doors_coord[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    int doors_direction[4] = {0, 0, 0, 0};
    char type;

private:
    char double_array[64][64];

};

#endif //MAIN_LEVELS_H