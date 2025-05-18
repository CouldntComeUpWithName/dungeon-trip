#pragma once

template<typename T>
class singleton
{
public:
  static bool exists() { return instance_; }
  static T& instance() { return *instance_; }
  
  singleton()  = default;
  ~singleton() = default;
  
  static void initialize(T* instance) { instance_ = instance; }
  static void release() { if (instance_) instance_ = nullptr; }

private:
  inline static T* instance_ = nullptr;
};