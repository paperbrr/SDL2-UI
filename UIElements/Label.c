#include "UI.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <string.h>


//creates a new button object (on the heap) and returns the pointer location to it
Label* createLabel(Frame* parentFrame, SDL_Color color, int x, int y, int w, int h){
    Label* newLabel = malloc(sizeof(Label));
    if (newLabel==NULL){printf("error");return NULL;}

    newLabel->type = label;

    newLabel->color = color;
    newLabel->parentFrame = parentFrame;

    newLabel->labelTexture = NULL;

    newLabel->sourceRect.x = x;
    newLabel->sourceRect.y = y;
    newLabel->sourceRect.w = w;
    newLabel->sourceRect.h = h;

    frame_alloc(parentFrame, label, (void*) newLabel);
    return newLabel;
}


void label_SetText(Label* label, char* text, SDL_Renderer* renderer, SDL_Color textColor){
    label->labelTexture = createCharTexture(text, &label->wrapperRect.w, &label->wrapperRect.h, renderer, textColor);
    wrapText(&label->wrapperRect, &label->sourceRect);
    label->text = strdup(text);
}