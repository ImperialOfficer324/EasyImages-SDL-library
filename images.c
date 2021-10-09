/* images.c - main C file for EasyImages library. */
/*
    add this file to your Makefile.
    include the images.h header file into the project file you want to draw images from.
    add neccessary information to the load.c file and add that to your Makefile as well.
    call LoadImages at the beginning of your program, after the SDL initiation.
*/
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include "images.h"

// loads the renderer and loads images from load.c
int LoadImages(){
    //renderer
    renderer = SDL_CreateRenderer(screen,-1,0);
    if (renderer == NULL){
        printf("Error Loading Renderer: %s\n",SDL_GetError());
        return 0;
    };
    return 1;
}

int FreeImages(

/* Display Images */
    
// displays a full PNG image loaded directly from a file
int RenderFromFile(char* filename,int x,int y,int w,int h){
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    surface = IMG_Load(filename);
    if (surface == NULL){
        printf("Error Loading Image: %s\n",SDL_GetError());
        return 0;
    };
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL){
        printf("Error Loading Texture: %s\n",SDL_GetError());
        return 0;
    };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    
    return 1;
}

// displays a full PNG image from a surface
int RenderFromSurface(SDL_Surface* surface,int x,int y,int w,int h){
    SDL_Texture* texture;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL){
        printf("Error Loading Texture: %s\n",SDL_GetError());
        return 0;
    };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    
    return 1;
}

//draws the contents of the renderer to the screen. call this every frame
int BlitDisplay(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    return 1;
}
