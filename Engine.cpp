#include "Engine.h"
#include <iostream>
#include <fstream>


Engine::Engine(Image &screen, const std::string &map_path): map_array(), curr_level(), curr_screen(screen) {
    std::ifstream file_map(map_path);
    if (!file_map.is_open())
        std::cout << "I can't found map file!" << std::endl;

    int i = 0;
    while (!file_map.eof()) {
        file_map.getline(map_array[i], 10);
        ++i;
    }
    file_map.close();

    curr_level[0] = 0; curr_level[1] = 0; // init level A
}

std::string Engine::Curr_level_str() {
    std::string temp = "./resources/X.txt";
    temp[12] = map_array[curr_level[0]][curr_level[1]];
    return temp;
}

void Engine::Install_level() {
    Level level(Curr_level_str());
    level.Install(curr_screen);
}
