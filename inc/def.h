#ifndef DEF_H_
#define DEF_H_

#define  PI                 3.14159265358979323846
#define  SCREEN_WIDTH       1280
#define  SCREEN_HEIGHT      960
#define  MAP_WIDTH          20
#define  MAP_HEIGHT         15
#define  CELL_SIZE          64
#define  MOV_STEPS          5

/* Documentation */
typedef struct pos
{
	int x;
	int y;
} pos;

/* Documentation */
typedef enum
{
	COLLISION_NONE, COLLISION_DETECTED, COLLISION_X_DIR, COLLISION_Y_DIR
} collision;

extern SDL_Window *main_window;
extern SDL_Renderer *main_render;
extern SDL_Surface *surface1;
extern SDL_Texture *wall;
extern SDL_Texture *spr;
extern int mapArr[MAP_HEIGHT][MAP_WIDTH];
extern SDL_Rect sprite;

#endif /* DEF_H_ */
