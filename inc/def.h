#ifndef DEF_H_
#define DEF_H_

/* Mathmatical pi number */
#define  PI                       3.14159265358979323846

/* Dimensions of game */
#define  SCREEN_WIDTH             1280
#define  SCREEN_HEIGHT            960
#define  MAP_WIDTH                20
#define  MAP_HEIGHT               15
#define  CELL_SIZE                64
#define  MOV_STEPS                5

/* some symbols and angles for moving function */
#define  MOV_FORWARD              0.0
#define  FORWARD_SIGN             1
#define  MOV_BACKWARD             0.0
#define  BACKWARD_SIGN            -1
#define  MOV_LEFT                 (-(PI / 2))
#define  LEFT_SIGN                1
#define  MOV_RIGHT                (PI / 2)
#define  RIGHT_SIGN               1

/* these are some angles used in analisis */
#define  CENTER_ANGLE        (PI / 4)       /* angle for center point of the sprite */
#define  FRONT_POINT_ANGLE        0.463647609    /* angle for front and in the middle of line of the sprite */
#define  BOTTOM_POINT_ANGLE       (PI / 2)	 /* angle for the bottom point of sprite */

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

typedef enum collisionType {
	VERTICAL_COLLISION,
	HORIZONTAL_COLLISION,
} collisionType;

/**
 * enum collision - states of collision
 * @COLLISION_NONE: No collision
 * @COLLISION_DETECTED: collision detected against a wall in any side
 * @COLLISION_DETECTED_TEXT_1: collision detected with texture number 1
 * @COLLISION_DETECTED_TEXT_2: collision detected with texture number 2
 * @COLLISION_DETECTED_TEXT_3: collision detected with texture number 3
 * @COLLISION_DETECTED_TEXT_4: collision detected with texture number 4
 * @COLLISION_X_DIR: collision detected against a wall in x direction
 * @COLLISION_Y_DIR: collision detected against a wall in y direction
 */
typedef enum collision
{
	COLLISION_NONE,
	COLLISION_DETECTED_TEXT_1,
	COLLISION_DETECTED_TEXT_2,
	COLLISION_DETECTED_TEXT_3,
	COLLISION_DETECTED_TEXT_4,
	COLLISION_DETECTED,
	COLLISION_X_DIR,
	COLLISION_Y_DIR
} collision;


/**
 * enum direction - enum defines 8 states possible for beam direction
 * @BEAM_ERR: something wrong with the angle
 * @BEAM_FORWARD: beam in forward direction                    beam = 0
 * @BEAM_FORWARD_DOWN: beam in forward down direction      0 < beam < 90
 * @BEAM_DOWN: beam in down direction                          beam = 90
 * @BEAM_BACKWARD_DOWN: beam in backward down             90 < beam < 180
 * @BEAM_BACKWARD: beam in backward direction                  beam = 180
 * @BEAM_BACKWARD_UP: beam in backward up direction      180 < beam < 270
 * @BEAM_UP: beam in up direction                              beam = 270
 * @BEAM_FORWARD_UP: beam in forward up direction        270 < beam < 360
 *
 */
typedef enum direction
{
	BEAM_ERR,
	BEAM_FORWARD = 1,
	BEAM_FORWARD_DOWN,
	BEAM_DOWN,
	BEAM_BACKWARD_DOWN,
	BEAM_BACKWARD,
	BEAM_BACKWARD_UP,
	BEAM_UP,
	BEAM_FORWARD_UP,
} direction;

extern SDL_Window *main_window;
extern SDL_Renderer *main_render;
extern SDL_Texture *wall;
extern SDL_Texture *spr;
extern int mapArr[MAP_HEIGHT][MAP_WIDTH];
extern SDL_Rect sprite;

#endif /* DEF_H_ */
