#pragma once

#include "scene.hpp"

class main_menu : public scene {
public:
  void init() override;
  void fixed_update(float) override;
  void update(float) override;
  void render() override;
  void shutdown() override;
  
private:

};