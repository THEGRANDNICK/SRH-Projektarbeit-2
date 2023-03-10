#pragma once

#include "../INCLUDES.h"

namespace GameAudio {
  extern Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem, buttonpress,
    titlescreenmusic, pausemenu, indungeon, outdungeon, battlemusic, epanoxsfx, teleport, dooropen, dooropen2, credits,
    gameover;

  void Load();
  void StopMusic();
  void Unload();
} // namespace GameAudio

