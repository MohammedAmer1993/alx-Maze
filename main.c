#include "maze.h"

/* Documetation for main */

SDL_Window* main_window = NULL;
SDL_Renderer* main_render = NULL;
SDL_Surface* surface1 = NULL;
SDL_Texture* wall = NULL;
SDL_Texture* spr = NULL;
SDL_Rect sprite = {50, 50, 5, 5};


int mapArr[MAP_HEIGHT][MAP_WIDTH] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1},
		{1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},

	};

int main()
{
	int status = 0;
	SDL_Event e;
	int quit = 1;
	double angle = 0;
	status = maze_init();
	if(status > 0)
	{
		printf("couldn't inialize the game\nError code: %d\n", status);
		return (status);
	}
	else
	{
		status = maze_load();
		if(status > 0)
		{
			printf("couldn't load the map");
			return (status);
		}
		status = create2Dmap();
		if(status > 0)
		{
			printf("couldn't load the map");
			return (status);
		}
		else
		{
			while (quit)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						quit = 0;
					}
					switch (e.key.keysym.sym)
					{
					case SDLK_UP:
						sprite.y -= 5;
						break;
					case SDLK_DOWN:
						sprite.y += 5;
						break;
					case SDLK_LEFT:
						if (angle <= -360)
						{
							angle += 360;
						}
						angle -= 1;
						break;
					case SDLK_RIGHT:
						if (angle >= 360)
						{
							angle -= 360;
						}
						angle += 1;
						break;
					case SDLK_w:
						sprite.y -= 5;
						break;
					case SDLK_s:
						sprite.y += 5;
						break;
					case SDLK_a:
						sprite.x -= 5;
						break;
					case SDLK_d:
						sprite.x += 5;
						break;
					
					default:
						break;
					}
				}
				SDL_RenderCopyEx(main_render, wall, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
				status = drawMainSprite(angle);
				if (status > 0)
				{
					printf("couldn't pring sprint");
					return (status);
				}
				SDL_RenderPresent(main_render);
			}
		}
	}
	
	return (status);
}
