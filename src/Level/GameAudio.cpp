#include "GameAudio.h"

namespace GameAudio {
  Sound collision, walking, attack, openchest, dialoge, trapdoor, unlockdoor, pickupitem, buttonpress, titlescreenmusic,
    pausemenu, indungeon, outdungeon, battlemusic;

  void Load() {
    // sfx
    collision   = LoadSound("assets/audio/sfx/41_Cling_climb_02_.wav");
    walking     = LoadSound("assets/audio/sfx/12_Step_wood_03.wav");
    attack      = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    openchest   = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    dialoge     = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    trapdoor    = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    unlockdoor  = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    pickupitem  = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    buttonpress = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet

    // music
    titlescreenmusic = LoadSound("assets/audio/sfx/Forever Lost.wav");    
    pausemenu        = LoadSound("assets/audio/sfx/12_Step_wood_03.wav"); // not right sound yet
    indungeon        = LoadSound("assets/audio/sfx/cave_theme_2.wav");    
    outdungeon       = LoadSound("assets/audio/sfx/Beginning of time.wav"); // not right sound yet
    battlemusic      = LoadSound("assets/audio/sfx/chibi-robot-b.ogg");   
  }

  void Unload() {
    UnloadSound(collision);
    UnloadSound(walking);
    UnloadSound(attack);
    UnloadSound(openchest);
    UnloadSound(dialoge);
    UnloadSound(trapdoor);
    UnloadSound(unlockdoor);
    UnloadSound(pickupitem);
    UnloadSound(buttonpress);
    UnloadSound(titlescreenmusic);
    UnloadSound(pausemenu);
    UnloadSound(indungeon);
    UnloadSound(outdungeon);
  }
} // namespace GameAudio
