#include "util.h"

/**
 * loadSurface - loading surface from bmp imge
 * @str: the path of the image
 * Return: pointer to SDL_surface structure
 */

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

/**
 * createTextureFromSurface - create a texture
 * @surface: pointer to SDL_surface
 * Return: ponter to newly created SDL_Texture
 */

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

