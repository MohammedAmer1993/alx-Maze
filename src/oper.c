#include "oper.h"

int maze_init()
{
	int success = 0;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = 1;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		main_window = SDL_CreateWindow( "Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( main_window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = 2;
		}
		else
		{
			//Create renderer for window
			main_render = SDL_CreateRenderer( main_window, -1, SDL_RENDERER_ACCELERATED );
			if( main_render == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
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
int maze_load()
{
	return (0);
}
int maze_close()
{
	return (0);
}
