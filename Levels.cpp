#include "Levels.h"
#include <iostream>
#include <fstream>


Level::Level(const std::string &a_path): Double_array() {
    std::ifstream fin(a_path);

    if (!fin)
        std::cout << "I can't found file!" << std::endl;

    number = static_cast<int>(static_cast<unsigned char>(a_path[0]));
    type = a_path[1];

    for (int i = 0; i < 64; ++i)
        fin.getline(Double_array[i], 63, '\n');

    std::cout << "Constructor good" << std::endl;

    fin.close();
}

void Level::Install(Image &screen) {
    Image door_img("./resources/door.png");
    Image wall_img("./resources/wall.png");
    Image fall_img("./resources/fall.png");
    Image quit_img("./resources/quit.png");
    Image gold_img("./resources/gold.png");
    Image person_img("./resources/person.png");
    Image ground_img("./resources/ground.png");
    Image temp_img(0, 0, 4);
    std::cout << "Begin install" << std::endl;

    std::cout << sizeof(Double_array[0]) << sizeof(Double_array[63]) << std::endl;

    int y = 1008;
    for (int i = 0; i < 64; ++i) {
        int x = 0;
        for (int j = 0; j < 64; ++j) {

            switch (Double_array[i][j]) {
                case '#':
                    temp_img = wall_img;
                    break;
                case ' ':
                    temp_img = fall_img;
                    break;
                case '.':
                    temp_img = ground_img;
                    break;
                case '@':
                    temp_img = person_img;
                    break;
                case 'x':
                    temp_img = door_img;
                    break;
                case 'Q':
                    temp_img = quit_img;
                    break;
                case 'G':
                    temp_img = gold_img;
                    break;
                default:
                    break;
            }

            for (int s = 0; s < 16; ++s)
                for (int t = 0; t < 16; ++t) {
                    Pixel temp_pixel = temp_img.GetPixel(t, s);
                    screen.PutPixel(x + t, y + s, temp_pixel);
                }

            x += 16;
        }
        y -= 16;
    }
    std::cout << "End install" << std::endl;
}