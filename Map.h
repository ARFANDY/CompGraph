#ifndef MAIN_MAP_H
#define MAIN_MAP_H


class Map {
public:
    Map(const std::string &map_path);
    char map_array[4][5];
};

#endif //MAIN_MAP_H