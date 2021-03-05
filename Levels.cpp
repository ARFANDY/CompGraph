#include "Levels.h"
#include <iostream>
#include <fstream>


Level::Level(const std::string &a_path): double_array() {
    std::ifstream fin(a_path);

    if (!fin.is_open())
        std::cout << "I can't found file!" << std::endl;

    int i = 0;
    while (!fin.eof()) {
        fin.getline(double_array[i], 100);
        ++i;
    }
    fin.close();

    switch (a_path[a_path.length() - 5]) {
        case 'A':
            doors[1] = doors[2] = 1;
            break;
        case 'B':
            doors[1] = doors[2] = doors[3] = 1;
            break;
        case 'C':
            doors[2] = doors[3] = 1;
            break;
        case 'F':
            doors[1] = doors[2] = 1;
            break;
        case 'H':
            doors[0] = doors[1] = doors[2] = doors[3] = 1;
            break;
        case 'V':
            doors[0] = doors[2] = doors[3] = 1;
            break;
        case 'Q':
            doors[0] = doors[2] = doors[3] = 1;
            doors[1] = 2;
            break;
        case 'K':
            doors[0] = doors[1] = 1;
            break;
        case 'T':
            doors[0] = doors[1] = doors[3] = 1;
            break;
        case 'J':
            doors[0] = doors[3] = 1;
            break;
        default:
            std::cout << "Incorrect file name!" << std::endl;
    }
}

void Level::Install(Image &screen) {
    Image door_img("./resources/door.png");
    Image wall_img("./resources/wall.png");
    Image fall_img("./resources/fall.png");
    Image quit_img("./resources/quit.png");
    Image gold_img("./resources/gold.png");
    Image player_img("./resources/player.png");
    Image ground_img("./resources/ground.png");

    int y = screen.Height() - 16;
    for (int i = 0; i < 64; ++i) {
        int x = 0;
        for (int j = 0; j < 64; ++j) {

            for (int s = 0; s < 16; ++s)
                for (int t = 0; t < 16; ++t) {
                    Pixel temp_pixel{0 ,0, 0, 0};
                    switch (double_array[i][j]) {
                        case '#': {
                            temp_pixel = wall_img.GetPixel(t, s);
                            break;
                        }
                        case ' ': {
                            temp_pixel = fall_img.GetPixel(t, s);
                            break;
                        }
                        case '.': {
                            temp_pixel = ground_img.GetPixel(t, s);
                            break;
                        }
                        case '@': {
                            temp_pixel = player_img.GetPixel(t, s);
                            break;
                        }
                        case 'x': {
                            temp_pixel = door_img.GetPixel(t, s);
                            break;
                        }
                        case 'Q': {
                            temp_pixel = quit_img.GetPixel(t, s);
                            break;
                        }
                        case 'G': {
                            temp_pixel = gold_img.GetPixel(t, s);
                            break;
                        }
                    }
                    screen.PutPixel(x + t, y + s, temp_pixel);
                }

            x += 16;
        }
        y -= 16;
    }
}