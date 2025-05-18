#pragma once

class scene {
public:
  virtual void init()              = 0;
  virtual void fixed_update(float) = 0;
  virtual void update(float)       = 0;
  virtual void render()            = 0;
  virtual void shutdown()          = 0;
};