#ifndef MAIN_LEVELS_H
#define MAIN_LEVELS_H


#include "Image.h"

struct Level
{
    explicit Level(const std::string &a_path);
    void Install(Image &screen);

    int doors_coord[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}; //[y,x]
    int doors_direction[4] = {0, 0, 0, 0};
    char type;

private:
    char double_array[64][64];

};

#endif //MAIN_LEVELS_H