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
    case MovementDir::UP:
      old_coords.y = coords.y;
      coords.y += move_dist;
      break;
    case MovementDir::DOWN:
      old_coords.y = coords.y;
      coords.y -= move_dist;
      break;
    case MovementDir::LEFT:
      old_coords.x = coords.x;
      coords.x -= move_dist;
      break;
    case MovementDir::RIGHT:
      old_coords.x = coords.x;
      coords.x += move_dist;
      break;
    default:
      break;
  }
}

void Player::Draw(Image &screen)
{
    Image img("./resources/tex.png");
    Image door_img("./resources/door.png");
    Image wall_img("./resources/wall.png");
    Image fall_img("./resources/fall.png");
    Image ground_img("./resources/ground.png");

//    for(int y = 0; y <= 1024; ++y)
//    {
//        for(int x = 0; x <= 1024; ++x)
//        {
//            Pixel checkPixel{uint8_t(x % 255), uint8_t(y % 255), uint8_t(((x + y) / 2) % 255), 255};
//            screen.PutPixel(x, y, checkPixel);
//        }
//    }

    for (int y = 0; y <= 16; ++y)
        for (int x = 0; x <= 16; ++x) {
            Pixel tmp = ground_img.GetPixel(x, y);
            screen.PutPixel(400 + x, 400 + y, tmp);
        }

  if(Moved())
  {
    for(int y = old_coords.y; y <= old_coords.y + tileSize; ++y)
    {
      for(int x = old_coords.x; x <= old_coords.x + tileSize; ++x)
      {
        screen.PutPixel(x, y, backgroundColor);
      }
    }
    old_coords = coords;
  }

  for(int y = coords.y; y <= coords.y + tileSize; ++y)
  {
    for(int x = coords.x; x <= coords.x + tileSize; ++x)
    {
      screen.PutPixel(x, y, color);
    }
  }

}

