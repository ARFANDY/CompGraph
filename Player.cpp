#include "Player.h"


bool Player::Moved() const
{
  if(coords.x == old_coords.x && coords.y == old_coords.y)
    return false;
  else
    return true;
}

void Player::ProcessInput(MovementDir dir)
{
  int move_dist = move_speed * 1;
  switch(dir)
  {
      case MovementDir::ENTER_ROOM:
          flag = true;
          break;
    case MovementDir::UP:
        flag = false;
      old_coords.y = coords.y;
      coords.y += move_dist;
      break;
    case MovementDir::DOWN:
        flag = false;
      old_coords.y = coords.y;
      coords.y -= move_dist;
      break;
    case MovementDir::LEFT:
        flag = false;
      old_coords.x = coords.x;
      coords.x -= move_dist;
      break;
    case MovementDir::RIGHT:
        flag = false;
      old_coords.x = coords.x;
      coords.x += move_dist;
      break;
    default:
      break;
  }
}

void Player::Draw(Image &screen, Engine &engine)
{
    if (flag) {
        Level tmp = engine.level_link;
        for (int i = 0; i < 4; ++i) {
            if ((tmp.doors_direction[i] != 0) && (coords.x - tmp.doors_coord[i][1] < 20) && (coords.y - tmp.doors_coord[i][0] < 20)) {
                switch (i) {
                    case 0:
                        engine.Install_level(engine.curr_level[0] - 1 , engine.curr_level[1]);
                        break;
                    case 1:
                        engine.Install_level(engine.curr_level[0] , engine.curr_level[1] + 1);
                        break;
                    case 2:
                        engine.Install_level(engine.curr_level[0] + 1 , engine.curr_level[1]);
                        break;
                    case 3:
                        engine.Install_level(engine.curr_level[0] , engine.curr_level[1] - 1);
                        break;
                }
            }
        }
    }

    if (Moved()) {
        for (int y = old_coords.y; y <= old_coords.y + tileSize; ++y) {
            for (int x = old_coords.x; x <= old_coords.x + tileSize; ++x) {
                screen.PutPixel(x, y, backgroundColor);
            }
        }
        old_coords = coords;
    }

    for(int y = coords.y; y <= coords.y + tileSize; ++y) {
        for(int x = coords.x; x <= coords.x + tileSize; ++x) {
            screen.PutPixel(x, y, color);
        }
    }

}

