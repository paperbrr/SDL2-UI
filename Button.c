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

void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w, void (*action) ()){
    Button* newButton = malloc(sizeof(Button));
    newButton->sourceRect.x = x;
    newButton->sourceRect.y = y;
    newButton->sourceRect.h = h;
    newButton -> sourceRect.w = w;
    newButton->actionFunc = action;

    buttonArr->buttons = realloc(buttonArr->buttons, buttonArr->arrDataSize+sizeof(newButton));
    buttonArr->buttons[buttonArr->length] = newButton;
    buttonArr->length += 1;
}

void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr){
    if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT){        
        int clickX = event->button.x;
        int clickY = event->button.y;
            for (int i=0; i<buttonArr->length; i++){
                Button* currentButton = buttonArr->buttons[i];
                if (currentButton->sourceRect.x+currentButton->sourceRect.w>clickX && currentButton->sourceRect.y+currentButton->sourceRect.h>clickY){
                    currentButton->actionFunc();
                }            
            }
    }
}

void renderButtons(ButtonsArray* buttonArr, SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 180, 255);
    for (int i=0; i<buttonArr->length; i++){
        SDL_RenderFillRect(renderer, &buttonArr->buttons[i]->sourceRect);
    }
}

void freeButtonArray(ButtonsArray* buttonArr){
    free(buttonArr->buttons);
    buttonArr->arrDataSize = 0;
    buttonArr->length = 0;
}