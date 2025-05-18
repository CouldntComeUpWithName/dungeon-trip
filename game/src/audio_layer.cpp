#include "audio_layer.hpp"
#include "events/event.hpp"
#include "assets/sounds.hpp"

#include <iostream>

#include <raylib.h>
#include "app.hpp"

Sound sound_bank[(int)sound_type::SOUNDS_COUNT]{ };

Sound current_sound{};

audio_layer::audio_layer()
{
  using namespace events;
  
  InitAudioDevice();
  
  sound_bank[int(sound_type::jump_land)] = LoadSound("../../res/sounds/land2-43790.mp3");

  app::dispatcher()
    .listen<play_sound, &audio_layer::on_sound_play>(this);
  
  app::dispatcher()
    .listen<music_event, &audio_layer::on_music>(this);
}

void audio_layer::update(float dt)
{
  
}

void audio_layer::on_sound_play(events::play_sound event)
{
  PlaySound(sound_bank[int(event.sound)]);
}

void audio_layer::on_music(events::music_event event)
{
  //switch (event.act)
  //{
  //case events::music_event::action::play:
  //  PlayMusicStream(music);
  //  return;
  //case events::music_event::action::resume:
  //  ResumeMusicStream(music);
  //  return;
  //case events::music_event::action::pause:
  //  PauseMusicStream(music);
  //  return;
  //case events::music_event::action::restart:
  //  StopMusicStream(music);
  //  PlayMusicStream(music);
  //  return;
  //}
}
