#include "Engine.h"
#include <iostream>
#include <fstream>


Engine::Engine(Image &screen, Level &level, const std::string &map_path): map_array(), curr_level(), curr_screen(screen), level_link(level) {
    std::ifstream file_map(map_path);
    if (!file_map.is_open())
        std::cout << "I can't found map file!" << std::endl;

    int i = 0;
    while (!file_map.eof()) {
        file_map.getline(map_array[i], 10);
        ++i;
    }
    file_map.close();

    this->Install_level(0, 0);
}

std::string Engine::Curr_level_str() {
    std::string temp = "./resources/X.txt";
    temp[12] = map_array[curr_level[0]][curr_level[1]];
    return temp;
}

void Engine::Install_level(int coord_level_x, int coord_level_y) {
    curr_level[0] = coord_level_x; curr_level[1] = coord_level_y;

    Level tmp(Curr_level_str());
    level_link = tmp;

    level_link.Install(curr_screen);
}
