#include "UI.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>


//creates a new button object (on the heap) and assigns it to the frame
Button* createButton(Frame* parentFrame, SDL_Color color, void (*actionFunc) (), int x, int y, int w, int h){
    Button* newButton = malloc(sizeof(Button));
    if (newButton==NULL){printf("error");return NULL;}

    newButton->type = button;

    newButton->actionFunc = actionFunc;
    newButton->color = color;
    newButton->parentFrame = parentFrame;

    newButton->buttonTexture = NULL;

    newButton->sourceRect.x = x;
    newButton->sourceRect.y = y;
    newButton->sourceRect.w = w;
    newButton->sourceRect.h = h;

    frame_alloc(parentFrame, button, (void*) newButton);
    return newButton;
}


//button click handler for a certain frame (put in mousex and mousey when a click is detected)
void button_handleClicks(Frame* frame, int mouseClickX, int mouseClickY){
    for (int i=0; i<frame->buttonArrLen; i++){
        int leftEdge = frame->buttonArr[i]->sourceRect.x;
        int rightEdge = frame->buttonArr[i]->sourceRect.w + leftEdge;
        int topEdge = frame->buttonArr[i]->sourceRect.y;
        int bottomEdge = frame->buttonArr[i]->sourceRect.h + topEdge;
        if (mouseClickX>leftEdge && mouseClickX<rightEdge && mouseClickY>topEdge && mouseClickY<bottomEdge){
            frame->buttonArr[i]->actionFunc();
        }
    }
}

void button_SetText(Button* button, char* text, SDL_Renderer* renderer){
    button->buttonTexture = createCharTexture(text, &button->wrapperRect.w, &button->wrapperRect.h, renderer);
    wrapText(&button->wrapperRect, &button->sourceRect);
    button->text = text;
}