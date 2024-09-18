#ifndef DEF_H_
#define DEF_H_

#define  PI                 3.14159265358979323846
#define  SCREEN_WIDTH       1280
#define  SCREEN_HEIGHT      960
#define  MAP_WIDTH          20
#define  MAP_HEIGHT         15
#define  CELL_SIZE          64
#define  MOV_STEPS          5

/**
 * struct pos - position of sprite in 2dmap
 * @x: the x coordinate
 * @y: the y coordinate
 */
typedef struct pos
{
	int x;
	int y;
} pos;

/**
 * enum collision - states of collision
 * @COLLISION_NONE: No collision
 * @COLLISION_DETECTED: collision detected against a wall in any side
 * @COLLISION_X_DIR: collision detected against a wall in x direction
 * @COLLISION_Y_DIR: collision detected against a wall in y direction
 */
typedef enum collision
{
	COLLISION_NONE, COLLISION_DETECTED, COLLISION_X_DIR, COLLISION_Y_DIR
} collision;

extern SDL_Window *main_window;
extern SDL_Renderer *main_render;
extern SDL_Texture *wall;
extern SDL_Texture *spr;
extern int mapArr[MAP_HEIGHT][MAP_WIDTH];
extern SDL_Rect sprite;

#endif /* DEF_H_ */
