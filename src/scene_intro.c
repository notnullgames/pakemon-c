#include "scene_intro.h"
#include "pakemon.h"

Sprite cat;

void scene_intro_load() {
  cat.texture = LoadTexture(ASSETS_PATH"/cat.png");
  cat.frameSize = (Vector2){ 32, 32 };
  cat.maxFrame = 6;
  cat.framesWide = 6;
  cat.origin = (Vector2){ 0, 0 };
  cat.frameDelay = 15;
}

void scene_intro_update() {
  if (pakemon_button_down(BUTTON_A) == true || pakemon_button_down(BUTTON_B) == true || pakemon_button_down(BUTTON_START) == true) {
    pakemon_scene(SCENE_LIST_SYSTEMS);
  }

  BeginDrawing();
  ClearBackground(BLACK);
  DrawSprite(&cat, 140, 200, 0, 1, WHITE);
  EndDrawing();
}

void scene_intro_unload() {}