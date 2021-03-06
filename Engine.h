#ifndef MAIN_MAP_H
#define MAIN_MAP_H

#include "Levels.h"
#include <string>

class Engine {
public:
    explicit Engine(Image &screen, const std::string &map_path);
    std::string Curr_level_str();
    void Install_level();

private:
    char map_array[4][5];
    int curr_level[2];
    Image& curr_screen;
};

#endif //MAIN_MAP_H