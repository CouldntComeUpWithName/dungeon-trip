#pragma once
#include <cstdint>

#include "../assets/sounds.hpp"

namespace events {
  struct close_event { };
  
  struct play_sound {
    sound_type sound;
  };
  
  struct stop_sound {
    sound_type sound;
  };
  
  struct music_event {
    uint32_t music;
    enum class action {
      play,
      restart,
      pause,
      resume
    } act;
  };
}