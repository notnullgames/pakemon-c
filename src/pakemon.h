#ifndef PAKEMON_H
#define PAKEMON_H

#include "raylib.h"
#include <stdbool.h>
#include "scene_branding.h"
#include "scene_intro.h"
#include "scene_list_systems.h"
#include "scene_list_games.h"

#define SUPPORT_FILEFORMAT_MOD
#define SCREEN_WIDTH (320)
#define SCREEN_HEIGHT (240)
#define DEBOUCE_THRESHOLD 0.5

enum Scene {
    SCENE_BRANDING,
    SCENE_INTRO,
    SCENE_LIST_SYSTEMS,
    SCENE_LIST_GAMES
};

enum MappedInput {
    BUTTON_A,
    BUTTON_B,
    BUTTON_X,
    BUTTON_Y,
    BUTTON_L,
    BUTTON_R,
    BUTTON_START,
    BUTTON_SELECT,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_UP,
    BUTTON_DOWN
};

// simple parallax layer system
typedef struct ParallaxLayer {
    Texture2D texture;
    float scroll;
} ParallaxLayer;

typedef struct Sprite {
    Texture2D texture;
    Vector2 frameSize;
    int maxFrame;
    int framesWide;
    Vector2 origin;
    int frame;
    int frameDelay;
} Sprite;

void ParallaxLayerScroll(struct ParallaxLayer* layer, float offset);
void DrawSprite(Sprite* sprite, float x, float y, float ang, float scale, Color c);
void pakemon_scene(enum Scene scene);
bool pakemon_button_down(enum MappedInput button);
bool pakemon_button_up(enum MappedInput button);

enum Scene SCENE_CURRENT;

#endif