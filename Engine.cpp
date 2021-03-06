#include "Engine.h"
#include <iostream>
#include <fstream>


Engine::Engine(const std::string &map_path): map_array(), currently_level(), currently_level_str() {
    std::ifstream file_map(map_path);
    if (!file_map.is_open())
        std::cout << "I can't found map file!" << std::endl;

    int i = 0;
    while (!file_map.eof()) {
        file_map.getline(map_array[i], 10);
        ++i;
    }
    file_map.close();

    currently_level[0] = 0; currently_level[1] = 0; // init level A
}

std::string Engine::Currently_level_str() {
    std::string temp = "./resources/X.txt";
    temp[12] = map_array[currently_level[0]][currently_level[1]];
    currently_level_str = temp;
    return currently_level_str;
}