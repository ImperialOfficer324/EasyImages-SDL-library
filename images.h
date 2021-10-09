/* images.h - setup surfaces and image function prototypes */
#include <SDL.h>
#ifndef __IMAGES_H__
#define __IMAGES_H__

SDL_Renderer * renderer;

/* prototypes */
//render an image from a file (PNG)
int RenderFromFile(char* filename,int x,int y,int w,int h);
//render an image from a preloaded SDL surface
int RenderFromSurface(SDL_Surface* surface,int x,int y,int w,int h);
//render part of an image from a preloaded SDL surface
int RenderPartialImageFromSurface(SDL_Surface* surface,int x,int y,int w,int h,int px,int py,int pw,int ph);
//load all images needed for the game
int LoadImages();
//free all images loaded with LoadImages
int FreeImages();
//Draw all rendered images to the screen and clear the renderer
int BlitDisplay();

/* image surfaces */
SDL_Surface *MapBackground;

#endif