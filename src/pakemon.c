#include "pakemon.h"

void ParallaxLayerScroll(struct ParallaxLayer* layer, float offset) {
    layer->scroll += offset;
    if (layer->scroll <= -layer->texture.width) layer->scroll = 0;
}

void DrawSprite(Sprite* sprite, float x, float y, float ang, float scale, Color c) {
    double time = GetTime();
    if ((int)time % sprite->frameDelay == 0) {
        sprite->frame++;
    } 
    float ox, oy;
    ox = (sprite->frame % sprite->framesWide) * sprite->frameSize.x;
    oy = (int)(sprite->frame / sprite->framesWide) * sprite->frameSize.y;
    DrawTexturePro(
        sprite->texture,
        (Rectangle){ox, oy, sprite->frameSize.x,sprite->frameSize.y}, 
        (Rectangle){x, y, sprite->frameSize.x * scale, sprite->frameSize.y * scale}, 
        (Vector2){sprite->origin.x * scale, sprite->origin.y * scale},
        ang,
        c
    );
}

// switch current scene
void pakemon_scene(enum Scene scene) {
    switch(SCENE_CURRENT) {
        case SCENE_BRANDING: scene_branding_unload(); break;
        case SCENE_INTRO: scene_intro_unload(); break;
        case SCENE_LIST_SYSTEMS: scene_list_systems_unload(); break;
        case SCENE_LIST_GAMES: scene_list_games_unload(); break;
    }
    
    SCENE_CURRENT = scene;
    
    switch(SCENE_CURRENT) {
        case SCENE_BRANDING: scene_branding_load(); break;
        case SCENE_INTRO: scene_intro_load(); break;
        case SCENE_LIST_SYSTEMS: scene_list_systems_load(); break;
        case SCENE_LIST_GAMES: scene_list_games_load(); break;
    }
}

double lastTime = 0;


// mapped input that supports gamepad and keys
// TODO: this only handles keyboard right now
bool pakemon_button_down(enum MappedInput button) {
    double now = GetTime();

    if ((now - lastTime) < DEBOUCE_THRESHOLD) {
        return false;
    }

    switch(button) {
        case BUTTON_A:
            if (IsKeyDown(KEY_Z)){
                lastTime = now;
                return true;
            }
        case BUTTON_B:
            if (IsKeyDown(KEY_X)){
                lastTime = now;
                return true;
            }
        case BUTTON_X:
            if (IsKeyDown(KEY_A)){
                lastTime = now;
                return true;
            }
        case BUTTON_Y:
            if (IsKeyDown(KEY_S)){
                lastTime = now;
                return true;
            }
        case BUTTON_R:
            if (IsKeyDown(KEY_Q)){
                lastTime = now;
                return true;
            }
        case BUTTON_L:
            if (IsKeyDown(KEY_W)){
                lastTime = now;
                return true;
            }
        case BUTTON_START:
            if (IsKeyDown(KEY_ENTER)){
                lastTime = now;
                return true;
            }
        case BUTTON_SELECT:
            if (IsKeyDown(KEY_TAB)){
                lastTime = now;
                return true;
            }
        case BUTTON_UP:
            if (IsKeyDown(KEY_UP)){
                lastTime = now;
                return true;
            }
        case BUTTON_DOWN:
            if (IsKeyDown(KEY_DOWN)){
                lastTime = now;
                return true;
            }
        case BUTTON_LEFT:
            if (IsKeyDown(KEY_LEFT)){
                lastTime = now;
                return true;
            }
        case BUTTON_RIGHT:
            if (IsKeyDown(KEY_RIGHT)){
                lastTime = now;
                return true;
            }
    }
    return false;
}

// mapped input that supports gamepad and keys
// TODO: this only handles keyboard right now
bool pakemon_button_up(enum MappedInput button) {
    switch(button) {
        case BUTTON_A:
            if (IsKeyUp(KEY_Z)){
                return true;
            }
        case BUTTON_B:
            if (IsKeyUp(KEY_X)){
                return true;
            }
        case BUTTON_X:
            if (IsKeyUp(KEY_A)){
                return true;
            }
        case BUTTON_Y:
            if (IsKeyUp(KEY_S)){
                return true;
            }
        case BUTTON_R:
            if (IsKeyUp(KEY_Q)){
                return true;
            }
        case BUTTON_L:
            if (IsKeyUp(KEY_W)){
                return true;
            }
        case BUTTON_START:
            if (IsKeyUp(KEY_ENTER)){
                return true;
            }
        case BUTTON_SELECT:
            if (IsKeyUp(KEY_TAB)){
                return true;
            }
        case BUTTON_UP:
            if (IsKeyUp(KEY_UP)){
                return true;
            }
        case BUTTON_DOWN:
            if (IsKeyUp(KEY_DOWN)){
                return true;
            }
        case BUTTON_LEFT:
            if (IsKeyUp(KEY_LEFT)){
                return true;
            }
        case BUTTON_RIGHT:
            if (IsKeyUp(KEY_RIGHT)){
                return true;
            }
    }
    return false;
}

