#include "Player.h"
#include "Levels.h"


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
    Level level("./resources/1A.txt");
    level.Install(screen);
    Image wall_img("./resources/wall.png");

//    for (int s = 0; s < wall_img.Height(); ++s)
//        for (int t = 0; t < wall_img.Width(); ++t) {
//            Pixel temp_pixel = wall_img.GetPixel(t, s);
//            screen.PutPixel(0 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(16 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(32 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(48 + t, 1008 + s, temp_pixel);
//
//            screen.PutPixel(0 + t, 992 + s, temp_pixel);
//            screen.PutPixel(16 + t, 992 + s, temp_pixel);
//            screen.PutPixel(32 + t, 992 + s, temp_pixel);
//            screen.PutPixel(48 + t, 992 + s, temp_pixel);
//
//            screen.PutPixel(64 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(80 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(96 + t, 1008 + s, temp_pixel);
//            screen.PutPixel(112 + t, 1008 + s, temp_pixel);
//        }

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

