#include "util.h"

/* Documentation for createsurface func */

SDL_Surface *loadSurface(char *str)
{
	SDL_Surface *surface = SDL_LoadBMP(str);

	if (surface == NULL)
	{
		printf("couldn't load the assed\nError: %s\n", SDL_GetError());
		return (NULL);
	}
	else
	{
		return (surface);
	}
}

/* Documentation for this function */

SDL_Texture *createTextureFromSurface(SDL_Surface *surface)
{
	SDL_Texture *texture = SDL_CreateTextureFromSurface(main_render, surface);

	if (texture == NULL)
	{
		printf("couldn't load texture\nError: %s\n", SDL_GetError());
		free(surface);
		return (NULL);
	}
	else
	{
		free(surface);
		return (texture);
	}
}

