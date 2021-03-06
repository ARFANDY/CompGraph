#include "Levels.h"
#include <iostream>
#include <fstream>


Level::Level(const std::string &a_path): double_array(), doors_coord(), doors_direction() {
    std::ifstream fin(a_path);

    if (!fin.is_open())
        std::cout << "I can't found file!" << std::endl;

    int k = 0;
    while (!fin.eof()) {
        fin.getline(double_array[k], 100);
        ++k;
    }
    fin.close();

    switch (a_path[a_path.length() - 5]) {
        case 'A':
            doors_direction[1] = doors_direction[2] = 1;
            type = 'A';

            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            break;
        case 'B':
            doors_direction[1] = doors_direction[2] = doors_direction[3] = 1;
            type = 'B';

            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'C':
            doors_direction[2] = doors_direction[3] = 1;
            type = 'C';

            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'F':
            doors_direction[0] = doors_direction[1] = doors_direction[2] = 1;
            type = 'F';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            break;
        case 'H':
            doors_direction[0] = doors_direction[1] = doors_direction[2] = doors_direction[3] = 1;
            type = 'H';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'V':
            doors_direction[0] = doors_direction[2] = doors_direction[3] = 1;
            type = 'V';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'Q':
            doors_direction[0] = doors_direction[2] = doors_direction[3] = 1;
            type = 'Q';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int j = 0; j < 64; ++j) { //2
                if (double_array[63][j] == 'x') {
                    doors_coord[2][0] = j * 16;
                    doors_coord[2][1] = 16;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'K':
            doors_direction[0] = doors_direction[1] = 1;
            type = 'K';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            break;
        case 'T':
            doors_direction[0] = doors_direction[1] = doors_direction[3] = 1;
            type = 'T';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int i = 0; i < 64; ++i) { //1
                if (double_array[i][63] == 'x') {
                    doors_coord[1][0] = 1008;
                    doors_coord[1][1] = (1024 - i * 16);
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
            break;
        case 'J':
            doors_direction[0] = doors_direction[3] = 1;
            type = 'J';

            for (int j = 0; j < 64; ++j) { //0
                if (double_array[0][j] == 'x') {
                    doors_coord[0][0] = j * 16;
                    doors_coord[0][1] = 1008;
                }
            }
            for (int i = 0; i < 64; ++i) { //3
                if (double_array[i][0] == 'x') {
                    doors_coord[3][0] = 16;
                    doors_coord[3][1] = (1024 - i * 16);
                }
            }
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

void Level::Make_doors_coord() {


}
