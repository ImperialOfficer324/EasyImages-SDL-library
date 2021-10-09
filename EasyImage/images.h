/* images.h - setup surfaces and image function prototypes */
/*
    SETUP:
      1. make sure you have SDL2 installed and initiated in your project. For more information on SDL, go to https://www.libsdl.org/
      2. download SDL_Image and get that set up for your system. Include and Initiate this for PNG images in your project. For more information on SDL_Image, 
            go to https://www.libsdl.org/projects/SDL_image/
      3. place the EasyImage folder in your project's source folder
      4. Add EasyImage/images.c to your Makefile to make sure it gets compiled.
      5. Include EasyImage/images.h in the file you want to draw images from
      6. Call LoadImages() after your SDL initiation
      7. Call FreeImages() at the end of your project
      8. If you want to render an image many times, it is reccommended to load it from the beginning of your program. To do this, either load 
            the SDL_Surface yourself, or go to LoadImages() in the images.c file and follow the instructions for loading images
      9. Render some Images!

    AVAILABLE FUNCTIONS:
      open the images.h file to view the prototypes for all available functions in the library.
*/
#include <SDL.h>
#ifndef __IMAGES_H__
#define __IMAGES_H__

/* CREATE RENDERER */
SDL_Renderer * renderer;

/* PROTOTYPES */

// RenderFromFile
/*
    renders a full image loaded directly from a PNG file.
    paramaters:
        char * filename - the path of the PNG file you want to display
        int x - the x position of the image onscreen
        int y - the y position of the image onscreen
        int w - the width of the image onscreen
        int h - the height of the image onscreen
*/
int RenderFromFile(char* filename,int x,int y,int w,int h);


// RenderFromSurface
/*
    renders a full image from a preloaded SDL_Surface.
    paramaters:
        SDL_Surface * surface - the SDL_Surface pointer to the image.
        int x - the x position of the image onscreen
        int y - the y position of the image onscreen
        int w - the width of the image onscreen
        int h - the height of the image onscreen
*/
int RenderFromSurface(SDL_Surface* surface,int x,int y,int w,int h);


// RenderPartialImageFromSurface
/*
    renders a part of an image from a preloaded SDL_Surface.
    paramaters:
        SDL_Surface * surface - the SDL_Surface pointer to the image
        int x - the x position of the image onscreen
        int y - the y position of the image onscreen
        int w - the width of the image onscreen
        int h - the height of the image onscreen
        int px - the x position on the image of the image portion's left corner
        int py - the y position on the image of the image portion's left corner
        int pw - the width of the image portion
        int ph - the height of the image portion
*/
int RenderPartialImageFromSurface(SDL_Surface* surface,int x,int y,int w,int h,int px,int py,int pw,int ph);


// LoadImages()
// loads all images needed for your project, and initializes the renderer
int LoadImages();


// FreeImages
// free the images loaded with LoadImages
int FreeImages();


// BlitDisplay
// Draw all rendered images to the screen and clear the renderer. Call this every frame of your project
int BlitDisplay();


/* IMAGE SURFACES */
/* 
    for every image you intend to load with LoadImages, create an SDL_Surface pointer here
    example:
    SDL_Surface * foo_image;
*/

#endif
