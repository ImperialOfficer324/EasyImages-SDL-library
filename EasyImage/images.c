/* images.c - load, display, then free images */
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include "images.h"

/* LOAD IMAGES */
/*
    Loading Your Own Images:
    1. Copy the commented block of code beneath the if(renderer... statement.
    2. Replace the variables surrounded by <> with the requested values.
    
    *note: the surface must have been declared in images.h to work. Otherwise it is not a global variable.
*/
int LoadImages(){
    //renderer
    renderer = SDL_CreateRenderer(screen,-1,0);
    if (renderer == NULL){
        printf("Error Loading Renderer: %s\n",SDL_GetError());
        return 0;
    };
    
    /* ***copy and uncomment this to load an image***
    <image_name> = IMG_Load(<image_path>);
    if (<image_name> == NULL){
        printf("Error Loading Image: %s\n",SDL_GetError());
        return 0;
    };
    */
    return 1;
}

int FreeImages(){
    return 1;
}

/* Display Images */
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

int RenderPartialImageFromSurface(SDL_Surface* surface,int x,int y,int w,int h,int px,int py,int pw,int ph){
    SDL_Texture* texture;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_Rect port;
    port.x = px;
    port.y = py;
    port.w = pw;
    port.h = ph;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL){
        printf("Error Loading Texture: %s\n",SDL_GetError());
        return 0;
    };
    SDL_RenderCopy(renderer, texture, &port, &rect);
    SDL_DestroyTexture(texture);
    
    return 1;
}

int BlitDisplay(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    return 1;
}
