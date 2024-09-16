#ifndef DEF_H_
#define DEF_H_

#define  SCREEN_WIDTH      640
#define  SCREEN_HEIGHT     480
#define  MAP_WIDTH         100
#define  MAP_HEIGHT        100
#define  CELL_SIZE          32

extern SDL_Window* main_window;
extern SDL_Renderer* main_render;
extern SDL_Surface* surface1;
extern SDL_Texture* wall;
extern SDL_Texture* spr;
extern int mapArr[MAP_HEIGHT][MAP_WIDTH];
extern SDL_Rect sprite;

#endif /* DEF_H_ */
