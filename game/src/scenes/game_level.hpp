#pragma once

#include "scene.hpp"

class game_level : public scene {
public:
  void init() override;
  void fixed_update(float) override;
  void update(float) override;
  void render() override;
  void shutdown() override;
  
private:
};