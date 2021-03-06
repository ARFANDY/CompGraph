#ifndef MAIN_MAP_H
#define MAIN_MAP_H

#include <string>

class Engine {
public:
    explicit Engine(const std::string &map_path);
    std::string Currently_level_str();

private:
    char map_array[4][5];
    int currently_level[2];
    std::string currently_level_str;
};

#endif //MAIN_MAP_H