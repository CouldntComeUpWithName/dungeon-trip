#pragma once
#include "layer.hpp"

namespace events {
  struct play_sound;
  struct stop_sound;
  struct music_event;
}

class audio_layer final : public layer {
public:
  audio_layer();

  void update(float) override;
  
  ~audio_layer() override = default;

private:
  void on_sound_play(events::play_sound);
  void on_music(events::music_event);
  
private:
};