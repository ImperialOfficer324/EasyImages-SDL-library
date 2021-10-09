/* images.c - load, display, then free images */
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"
#include "images.h"

// load images that are needed for the entire cycle. Other images can be loaded as needed
int LoadImages(){
    //renderer
    renderer = SDL_CreateRenderer(screen,-1,0);
    if (renderer == NULL){
        printf("Error Loading Renderer: %s\n",SDL_GetError());
        return 0;
    };
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

int BlitDisplay(){
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    return 1;
}