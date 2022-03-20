#include "raylib.h"

#include "pakemon.h"

int main(void) {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pakémon");
    SetTargetFPS(60);
    InitAudioDevice();
    
    pakemon_scene(SCENE_BRANDING);

    while (!WindowShouldClose()) {
        switch(SCENE_CURRENT) {
            case SCENE_BRANDING: scene_branding_update(); break;
            case SCENE_INTRO: scene_intro_update(); break;
            case SCENE_LIST_SYSTEMS: scene_list_systems_update(); break;
            case SCENE_LIST_GAMES: scene_list_games_update(); break;
        }
    }

    // unload current scene
    switch(SCENE_CURRENT) {
        case SCENE_BRANDING: scene_branding_unload(); break;
        case SCENE_INTRO: scene_intro_unload(); break;
        case SCENE_LIST_SYSTEMS: scene_list_systems_unload(); break;
        case SCENE_LIST_GAMES: scene_list_games_unload(); break;
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
