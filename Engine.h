#ifndef MAIN_MAP_H
#define MAIN_MAP_H

#include "Levels.h"
#include <string>

class Engine {
public:
    explicit Engine(Image &screen, Level &level, const std::string &map_path);
    std::string Curr_level_str();
    void Install_level(int coord_level_x, int coord_level_y);
    int curr_level[2]; //[строка, столбец]
    char map_array[4][5];
    Level& level_link;

private:
    Image& curr_screen;

};

#endif //MAIN_MAP_H