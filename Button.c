#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Declarations.h"

void buttonsArr_init(ButtonsArray* buttonArr, int initialSize){
    buttonArr->buttons = malloc(initialSize* sizeof(Button));
    if (buttonArr->buttons==NULL){
        printf("ERROR");
        exit(1);
    }
    buttonArr->arrDataSize = initialSize* sizeof(Button);
    buttonArr->length = 0;
};

void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w){
    Button* newButton = malloc(sizeof(Button));
    newButton->sourceRect.x = x;
    newButton->sourceRect.y = y;
    newButton->sourceRect.h = h;
    newButton -> sourceRect.w = w;

    buttonArr->buttons = realloc(buttonArr->buttons, buttonArr->arrDataSize+sizeof(newButton));
    buttonArr->buttons[buttonArr->length] = newButton;
    buttonArr->length += 1;
}

void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr){
    if (event->type == SDL_MOUSEBUTTONDOWN){
        if (event->button.button == SDL_BUTTON_LEFT){
            int clickX = event->button.x;
            int clickY = event->button.y;
                for (int i=0; i<buttonArr->length; i++){
                    SDL_Rect currentButton = buttonArr->buttons[i]->sourceRect;
                    if (currentButton.x+currentButton.w>clickX && currentButton.y+currentButton.h>clickY){
                        printf("I GOT CLICKED");
                    }            
                }
        }
    }
}