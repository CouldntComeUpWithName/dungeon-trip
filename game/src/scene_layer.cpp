#include "scene_layer.hpp"
#include "scenes/game_level.hpp"

scene_layer::scene_layer()
{
  scene_ = std::make_unique<game_level>();
  scene_->init();
}

void scene_layer::update(float dt)
{
  scene_->update(dt);

  scene_->render();
}