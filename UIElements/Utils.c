#include <SDL_ttf.h>
#include <SDL.h>

SDL_Texture* createCharTexture(char* text, int* wrapperW, int* wrapperH, SDL_Renderer* renderer){
    TTF_Font* openSans = TTF_OpenFont("../generic-platformer/fonts/OpenSans-Regular.ttf", 25);
    if (!openSans){
        printf("font not found :D");
    }

    //TTF_SizeText(openSans, text, wrapperW, wrapperH);
    if (wrapperW && wrapperH) {TTF_SizeText(openSans, text, wrapperW, wrapperH);}
    // ^^for the wrapper, if needed :D

    SDL_Color textColor = {0, 190, 190, 255};
    SDL_Surface* charSurface = TTF_RenderText_Blended(openSans, text, textColor);
    SDL_Texture* charTexture = SDL_CreateTextureFromSurface(renderer, charSurface);

    SDL_FreeSurface(charSurface);
    TTF_CloseFont(openSans);
    return charTexture;
}

void wrapText(SDL_Rect* wrapperRect, SDL_Rect* parentRect){
    wrapperRect->x = parentRect->x + (parentRect->w/2 - wrapperRect->w/2);
    wrapperRect->y = parentRect->y + (parentRect->h/2 - wrapperRect->h/2);
}