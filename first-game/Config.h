#pragma once
#include "assert.h"

#define CONFIG_BALL_RADIUS 5
#define CONFIG_GRAV_CONST 40.f
#define CONFIG_MAX_BALLS 3200 // MUST BE GREATER THAN 1
#define CONFIG_VIDEO_WIDTH 1000 //must be divisible by ball diameter or else grid incomplete.
#define CONFIG_VIDEO_HEIGHT 1000 
#define CONFIG_BORDER_TOPLEFT {0,0}
#define CONFIG_BORDER_DIM {CONFIG_VIDEO_WIDTH , CONFIG_VIDEO_HEIGHT}
#define CONFIG_BORDER_THICKNESS CONFIG_BALL_RADIUS*2
#define CONFIG_60FPS (1.f / 60.f)
#define CONFIG_FPS_LIMIT CONFIG_60FPS*4
#define CONFIG_NUM_BALL_SOURCES 9
#define CONFIG_SPAWN_START_X 15.f
#define CONFIG_SPAWN_X_VEL 0.6f
#define CONFIG_SPAWN_START_Y 15.f
#define CONFIG_SPAWN_Y_VEL 0.3f
#define CONFIG_SPAWN_Y_SPACING_FACTOR 3.f
#define CONFIG_FONT_SIZE_PIX 14
#define CONFIG_COLOR_SPEED 0.2f
#define CONFIG_STATISTICS_PRINT_INTERVAL 0.1f

// FILL THESE OUT
//static_assert(CONFIG_VIDEO_WIDTH % (CONFIG_BALL_RADIUS * 2) == 0, "Video width must be divisible by ball diameter.");
//static_assert(CONFIG_VIDEO_HEIGHT % (CONFIG_BALL_RADIUS * 2) == 0, "Video width must be divisible by ball diameter.");
