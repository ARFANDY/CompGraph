#include "Map.h"
#include <iostream>
#include <fstream>


Map::Map(const std::string &map_path) {
    std::ifstream fmap(map_path);
    if (!fmap.is_open())
        std::cout << "I can't found map file!" << std::endl;

    int i = 0;
    while (!fmap.eof()) {
        fmap.getline(map_array[i], 100);
        ++i;
    }
    fmap.close();
}