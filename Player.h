#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Levels.h"
#include "Engine.h"

struct Point
{
    int x;
    int y;
};

enum class MovementDir
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER_ROOM
};

struct Player
{
    explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

    bool Moved() const;
    void ProcessInput(MovementDir dir);
    void Draw(Image &screen, Engine &engine);

private:
    Point coords {.x = 10, .y = 10};
    Point old_coords {.x = 10, .y = 10};
    Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 4;
    bool flag = false;
};

#endif //MAIN_PLAYER_H
