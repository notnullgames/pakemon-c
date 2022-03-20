#include "scene_branding.h"

void scene_branding_load() {
  image_branding = LoadTexture(ASSETS_PATH"/logo-white.png");
  sound_branding = LoadSound(ASSETS_PATH"/notnullgames.ogg");
  PlaySound(sound_branding);
}

void scene_branding_update() {
  if (pakemon_button_down(BUTTON_A) == true || pakemon_button_down(BUTTON_B) == true || pakemon_button_down(BUTTON_START) == true) {
    pakemon_scene(SCENE_INTRO);
  }
  
  BeginDrawing();
  
  ClearBackground(BLACK);
  DrawTexture(
    image_branding,
    (SCREEN_WIDTH/2) - (image_branding.width/2),
    (SCREEN_HEIGHT/2) - (image_branding.height/2),
    WHITE
  );

  EndDrawing();
}

void scene_branding_unload() {
  UnloadTexture(image_branding);
  UnloadSound(sound_branding);
}