#include "game_level.hpp"
#include <raylib.h>
#include <raymath.h>
#include <array>
#include <span>

#include "../events/event.hpp"
#include "../app.hpp"
#include "../assets/sounds.hpp"

Texture2D tiles;

void game_level::init()
{
  tiles = LoadTexture("../../res/textures/tiles.png");
}

void game_level::fixed_update(float dt)
{

}

void game_level::update(float dt)
{
  if (IsKeyPressed(KEY_SPACE))
    app::instance().dispatcher()
      .enqueue<events::play_sound>(sound_type::jump_land);
}

void game_level::render()
{
  BeginDrawing();

  ClearBackground(LIGHTGRAY);

  DrawTexture(tiles, 0, 5, LIGHTGRAY);
  EndDrawing();
}

void game_level::shutdown()
{

}
