#pragma once
#include "assert.h"

// Instead of doing this c-style CONFIG_ thing, just name space it.

#define CONFIG_BALL_RADIUS 3
#define CONFIG_BALL_DIAMETER CONFIG_BALL_RADIUS*2
#define CONFIG_GRAV_CONST 40.f
#define CONFIG_MAX_BALLS 30000 // MUST BE GREATER THAN 1
#define CONFIG_NUM_SUBSTEPS 2
#define CONFIG_VIDEO_WIDTH 1200 //must be divisible by ball diameter or else grid incomplete.
#define CONFIG_VIDEO_HEIGHT 960 


#define CONFIG_BORDER_LEFT CONFIG_BALL_DIAMETER
#define CONFIG_BORDER_RIGHT (CONFIG_VIDEO_WIDTH - CONFIG_BALL_DIAMETER)
#define CONFIG_BORDER_TOP CONFIG_BALL_DIAMETER
#define CONFIG_BORDER_BOTTOM (CONFIG_VIDEO_HEIGHT - CONFIG_BALL_DIAMETER)


#define CONFIG_60FPS (1.f / 60.f)
#define CONFIG_FPS_LIMIT CONFIG_60FPS*3 
#define CONFIG_NUM_BALL_SOURCES 40
#define CONFIG_SPAWN_START_X 15.f
#define CONFIG_SPAWN_X_VEL .5f
#define CONFIG_SPAWN_START_Y 15.f
#define CONFIG_SPAWN_Y_VEL 0.3f
#define CONFIG_SPAWN_Y_SPACING_FACTOR 2.3f
#define CONFIG_FONT_SIZE_PIX 14
#define CONFIG_COLOR_SPEED .4f
#define CONFIG_STATISTICS_PRINT_INTERVAL 0.1f

// FILL THESE OUT
static_assert(CONFIG_MAX_BALLS > 1, "Must be more than 1 ball.");
static_assert(CONFIG_VIDEO_WIDTH % (CONFIG_BALL_DIAMETER) == 0, "Video width must be divisible by ball diameter.");
static_assert(CONFIG_VIDEO_HEIGHT % (CONFIG_BALL_DIAMETER) == 0, "Video width must be divisible by ball diameter.");
