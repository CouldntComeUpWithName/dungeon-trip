#pragma once

class layer {
public:
  layer() = default;
  
  virtual void update(float) = 0;
  
  virtual ~layer() = default;
};