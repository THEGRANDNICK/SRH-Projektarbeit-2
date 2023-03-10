#include "Pharaoh.h"

Game::Pharaoh::Pharaoh() : GameCharacter("Pharaoh",20, c_MaxHP, 2, 12)
{

}

auto Game::Pharaoh::attack() -> std::vector<int>
{
  currentFrame = 2;
  s_currentFrame = 2;
  State = state::ATTACK;
  std::vector<int> vector;
  vector.push_back(c_STR);
  vector.push_back(0);
  return vector;
}

void Game::Pharaoh::getDamage(std::vector<int> damage)
{
  if (damage[0] - c_DEF > 0)
  {
    c_HP -= damage[0] - c_DEF;
  }
  //Sets the HP Automatically to 0. HP will not go Negative
  if (c_HP <= 0)
  {
    c_HP = 0;
  }
}

void Game::Pharaoh::updateCharacter()
{
  if (c_HP <= 0)
  {
    DrawText("You WON!", 500, 320, 40, GREEN);
  }
}

auto Game::Pharaoh::get_rec() -> Rectangle { return this->rec; }

auto Game::Pharaoh::set_rec() -> Rectangle {
  this->rec = { 780, 370, 50, 50 };
  return rec;
}
auto Game::Pharaoh::get_turnnumb() -> int { return turnnumb; }

auto Game::Pharaoh::getStrength() -> int { return c_STR; }

auto Game::Pharaoh::getDefense() -> int { return c_DEF; }

void Game::Pharaoh::draw() {

  // Draw Enemy
  pharaohrec = { get_rec().x - 15, get_rec().y - 60, get_rec().width, get_rec().height };
  DrawRectangleRec(pharaohrec, Color {});
  DrawTextureRec(spr_pharaoh, frameRec, { get_rec().x - 15, get_rec().y - 60 }, WHITE);

  shadowrec = {get_rec().x - 30, get_rec().y - 15, get_rec().width, get_rec().height};
  DrawRectangleRec(shadowrec, Color {});
  DrawTextureRec(shadow,s_frameRec, {get_rec().x - 30, get_rec().y - 28}, WHITE);
  // animation
  framesCounter++;
  s_framesCounter++;

  switch (State) {
  case GameCharacter::state::IDLE:
    if (framesCounter >= (60 / framesSpeed)) {
      framesCounter = 0;
      currentFrame++;

      if (currentFrame > 1)
        currentFrame = 0;

      frameRec.x = (float)currentFrame * (float)spr_pharaoh.width / 4;

      if (s_framesCounter >= (60 / s_framesSpeed)){
        s_framesCounter = 0;
        s_currentFrame++;

        if (s_currentFrame > 1)
          s_currentFrame = 0;

        s_frameRec.x = (float)s_currentFrame * (float)shadow.width / 4;
      }
      break;

    case GameCharacter::state::ATTACK:
      if (framesCounter >= (60 / framesSpeed)) {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 3) {
          State        = state::IDLE;
          currentFrame = 0;
        }

        frameRec.x = (float)currentFrame * (float)spr_pharaoh.width / 4;

        if (s_framesCounter >= (60 / s_framesSpeed)){
          s_framesCounter = 0;
          s_currentFrame++;

          if (s_currentFrame > 3){
            State = state::IDLE;
            s_currentFrame = 0;
          }

          s_frameRec.x = (float)s_currentFrame * (float)shadow.width / 4;
        }
        break;

      default: State = GameCharacter::state::IDLE; break;
      }
    }
  }

  // enemy Draw
  healthrec = { 0, 0, static_cast<float>(192 * ((float)c_HP / (float)c_MaxHP)), 96 };

  DrawTexture(healthbar, set_rec().x - 20, set_rec().y - 177, WHITE);
  DrawTextureRec(health, healthrec, { set_rec().x - 20, set_rec().y - 180 }, WHITE);
  DrawText(TextFormat("%i/%i", c_HP, c_MaxHP), set_rec().x + 50, set_rec().y - 140, 20, BLACK);

}
