#include "app.hpp"
#include <raylib.h>

#include "scene_layer.hpp"
#include "audio_layer.hpp"
#include "assets/sounds.hpp"
#include "events/event.hpp"

#include <span>

app::app()
{
  assert(!singleton::exists());
  singleton::initialize(this);
  init();
}

void app::init()
{
  InitWindow(1280, 720, "dungeon-trip");
  main_window_ = GetWindowHandle();
  //SetTargetFPS(60);
  
  layers_.push_back(std::make_unique<scene_layer>());
  layers_.push_back(std::make_unique<audio_layer>());
}

void app::run()
{
  while (!WindowShouldClose())
  {
    float dt = GetFrameTime();

    for (auto& layer : layers_)
    {
      layer->update(dt);
    }
    
    dispatcher_.run();
  }
  
  CloseWindow();
}

std::unique_ptr<layer>& app::push_layer(layer* l)
{
  return layers_.emplace_back(std::unique_ptr<::layer>{l});
}
