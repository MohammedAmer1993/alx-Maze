#include "maze.h"

/* Documetation for main */

SDL_Window *main_window = NULL;
SDL_Renderer *main_render = NULL;
SDL_Texture *wall = NULL;
SDL_Texture *spr = NULL;
SDL_Rect sprite = {80, 80, 5, 5};


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

/**
 * main - main entry point
 * @argc: number of command line argument passed
 * @argv: array of strings for comand line arguments
 * Return: 0 on succss ant a value on filure
 */
int main(int argc, char *argv[])
{
	int status = 0;
	SDL_Event e;
	int quit = 1;
	double angle = 0;
	double degree_angle = 0;

	(void) argc;
	(void) argv;
	status = maze_init();
	if (status > 0)
	{
		printf("couldn't inialize the game\nError code: %d\n", status);
		return (status);
	}
	else
	{
		status = maze_load();
		if (status > 0)
		{
			printf("couldn't load the map");
			return (status);
		}
		status = create2Dmap();
		if (status > 0)
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
					else
					{

						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							sprite.y -= 5;
							break;
						case SDLK_DOWN:
							sprite.y += 5;
							break;
						case SDLK_LEFT:
							angle -= 0.1;
							angle = angleIn360Range(angle);
							break;
						case SDLK_RIGHT:
							angle += 0.1;
							angle = angleIn360Range(angle);
							break;
						case SDLK_w:
							moveForward(&angle, MOV_STEPS);
							break;
						case SDLK_s:
							moveBackward(&angle, MOV_STEPS);
							break;
						case SDLK_a:
							moveLeft(&angle, MOV_STEPS);
							break;
						case SDLK_d:
							moveRight(&angle, MOV_STEPS);
							break;
						default:
							break;
						}
					SDL_RenderCopyEx(main_render, wall, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
					degree_angle = (180 / PI) * angle;
					status = drawMainSprite(degree_angle);
					if (status > 0)
					{
						printf("couldn't pring sprint");
						return (status);
					}
					SDL_RenderPresent(main_render);
					}
				}
			}
		}
	}
	maze_close();
	return (status);
}
