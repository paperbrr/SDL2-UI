#include <SDL_ttf.h>
#include <SDL.h>
#include <stdio.h>
#include "UI.h"

char* fontPath = NULL;
int fontSize = 0;

SDL_Texture* createCharTexture(char* text, int* wrapperW, int* wrapperH, SDL_Renderer* renderer, SDL_Color textColor){
    if (fontPath==NULL || fontSize==0){printf("Font path/size not initialised. Use fontInit() to proceed."); exit(1);}
    TTF_Font* font = TTF_OpenFont(fontPath, 25);
    if (!font){
        printf("font not found :D");
    }

    //TTF_SizeText(font, text, wrapperW, wrapperH);
    if (wrapperW && wrapperH) {TTF_SizeText(font, text, wrapperW, wrapperH);}
    // ^^for the wrapper, if needed :D

    //SDL_Color textColor = {0, 190, 190, 255};
    SDL_Surface* charSurface = TTF_RenderText_Blended(font, text, textColor);
    SDL_Texture* charTexture = SDL_CreateTextureFromSurface(renderer, charSurface);

    SDL_FreeSurface(charSurface);
    TTF_CloseFont(font);
    return charTexture;
}

void wrapText(SDL_Rect* wrapperRect, SDL_Rect* parentRect){
    wrapperRect->x = parentRect->x + (parentRect->w/2 - wrapperRect->w/2);
    wrapperRect->y = parentRect->y + (parentRect->h/2 - wrapperRect->h/2);
}

void fontInit(char* newFontPath, int newFontSize){
    fontPath = newFontPath;
    fontSize = newFontSize;
}