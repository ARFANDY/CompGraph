#ifndef MAIN_MAP_H
#define MAIN_MAP_H

#include "Levels.h"
#include <string>

class Engine {
public:
    explicit Engine(Image &screen, Level &level, const std::string &map_path);
    std::string Curr_level_str();
    void Install_level(int coord_level_x, int coord_level_y);
    int curr_level[2];

private:
    char map_array[4][5];
    Image& curr_screen;
    Level& level_link;

};

#endif //MAIN_MAP_H