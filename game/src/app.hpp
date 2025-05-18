#pragma once
#include <ges/dispatcher.hpp>
#include "layer.hpp"
#include "singleton.hpp"

#include <memory>

class app : public singleton<app> {
public:
  app();
  
  void init();
  
  void run();
  
  static auto dispatcher() 
    -> ges::dispatcher&
  {
    return instance().dispatcher_;
  }
  
  std::unique_ptr<layer>& push_layer(layer* layer);

private:
  std::vector<std::unique_ptr<layer>> layers_;
  ges::dispatcher dispatcher_;
  void* main_window_ = nullptr;
};