#include "game_build.h"

/**
 * maze_init - inilization of maze
 *
 * this fuction take care of inializing sdl library
 * creating window and rendere for the game
 * Return: 0 on success any othe value represents error
 */
int maze_init(void)
{
	int success = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = 1;
	}
	else
	{
		/* Set texture filtering to linear */
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		/* Create window */
		main_window = SDL_CreateWindow("Maze", SDL_WINDOWPOS_UNDEFINED,
						 SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (main_window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = 2;
		}
		else
		{
			/* Create renderer for window */
			main_render = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
			if (main_render == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = 3;
			}
			else
			{
				SDL_SetRenderDrawColor(main_render, 0, 0, 0, 255);
			}
		}
	}
	return (success);
}

/**
 * maze_load - loading assets
 *
 * this function loads differnt bmp images and create
 * textures from it
 * Return: 0 on success any othe value represents error
 */
int maze_load(void)
{
	int status = 0;
	SDL_Surface *surface = NULL;
	SDL_Texture *texture = NULL;
	SDL_Surface *surface2 = NULL;
	SDL_Texture *texture2 = NULL;

	surface = loadSurface("assets/wall.bmp");
	if (surface == NULL)
		status = 1;
	else
	{
		texture = createTextureFromSurface(surface);
		if (texture == NULL)
		{
			status = 1;
		}
		else
		{
			wall = texture;
		}
	}

	surface2 = loadSurface("assets/sprite.bmp");
	if (surface2 == NULL)
	{
		status = 1;
	}
	else
	{
		texture2 = createTextureFromSurface(surface2);
		if (texture2 == NULL)
		{
			status = 1;
		}
		else
		{
			spr = texture2;
		}
	}
	return (status);
}

/**
 * create2Dmap - create the map
 *
 * this function uses creates temp texture to
 * render the map on it and then makes the wall
 * texture points to it and to be considered the map
 * image
 * Return: 0 on success any othe value represents error
 */
int create2Dmap(void)
{
	int status = 0;
	SDL_Texture *texture = NULL;
	SDL_Rect fillRect = {0, 0, CELL_SIZE, CELL_SIZE};

	texture = SDL_CreateTexture(main_render, SDL_PIXELFORMAT_RGBA8888,
				    SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_SetRenderTarget(main_render, texture);
	SDL_SetRenderDrawColor(main_render, 0, 0, 0, 255);
	SDL_RenderClear(main_render);
	SDL_SetTextureBlendMode(wall, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(wall, 255);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			fillRect.x = j * CELL_SIZE;
			fillRect.y = i * CELL_SIZE;
			if (mapArr[i][j] == 1)
			{
				if (SDL_RenderCopyEx(main_render, wall, NULL, &fillRect,
					 0.0, NULL, SDL_FLIP_NONE) < 0)
				{
					printf("couldn't render the texture\nError: %s\n", SDL_GetError());
					status = 1;
				}
			}
		}
	}
	SDL_SetRenderDrawColor(main_render, 150, 150, 150, 255);
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		SDL_RenderDrawLine(main_render, 0, i * CELL_SIZE , SCREEN_WIDTH, i * CELL_SIZE);
	}
	for (int j = 0; j < MAP_WIDTH; ++j)
	{
		SDL_RenderDrawLine(main_render, j * CELL_SIZE, 0 , j * CELL_SIZE, SCREEN_HEIGHT);
	}
	SDL_SetRenderTarget(main_render, NULL);
	SDL_DestroyTexture(wall);
	wall = texture;
	return (status);
}

/**
 * drawMainSprite - draw the sprite
 * @angle: the angle of the sprite
 * Return: 0 on success any othe value represents error
 */
int drawMainSprite(double angle)
{
	int w = 0;
	int h = 0;
	int status = 0;

	SDL_QueryTexture(spr, NULL, NULL, &w, &h);
	sprite.w = w;
	sprite.h = h;
	if (SDL_RenderCopyEx(main_render, spr, NULL, &sprite,
				 angle, NULL, SDL_FLIP_NONE) < 0)
	{
		printf("couldn't render the texture\nError: %s\n", SDL_GetError());
		status = 1;
	}
	return (status);
}

/**
 * maze_close - releases all memory
 * Return: Nothing (void function)
 */
void maze_close(void)
{
	SDL_DestroyTexture(wall);
	SDL_DestroyTexture(spr);
	SDL_DestroyRenderer(main_render);
	SDL_DestroyWindow(main_window);
	wall = NULL;
	spr = NULL;
	main_render = NULL;
	main_window = NULL;
	SDL_Quit();
}

