#include "util.h"

/* Documentation for createsurface func */

int createSurface(char* str)
{
	/* to be impelmented later */
	(void) str;
	return (0);
}

/* Documentation for this function */

int createTextureFromSurface(SDL_Surface* surface)
{
	/* to be impemented later */
	(void) surface;
	return (0);
}

/* Documentation for this functiion */
void create2Dmap()
{
	SDL_Rect fillRect = {0, 0, CELL_SIZE, CELL_SIZE};

	SDL_SetRenderDrawColor(main_render, 0, 0, 0, 255);
	SDL_RenderClear(main_render);
	SDL_SetRenderDrawBlendMode(main_render, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(main_render, 101, 107, 117, 255);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			fillRect.x = j * CELL_SIZE;
			fillRect.y = i * CELL_SIZE;
			if (mapArr[i][j] == 1)
			{
				SDL_RenderFillRect(main_render, &fillRect);
			}
		}
	}
}


void drawMainSprite()
{
	SDL_SetRenderDrawColor(main_render, 255, 255, 0, 255);
	SDL_RenderFillRect(main_render, &sprite);
}
