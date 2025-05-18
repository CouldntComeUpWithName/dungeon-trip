#pragma once
#include "layer.hpp"
#include "scenes/scene.hpp"
#include <memory>

class scene_layer final : public layer {
public:
  scene_layer();
  
  void update(float dt) override;

  ~scene_layer() override = default;
private:
  std::unique_ptr<scene> scene_;
};