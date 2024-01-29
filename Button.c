#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Declarations.h"

void buttonsArr_init(ButtonsArray* buttonArr, int initialSize){
    buttonArr->buttons = malloc(initialSize* sizeof(Button*));
    if (buttonArr->buttons==NULL){
        printf("ERROR");
        exit(1);
    }
    buttonArr->arrDataSize = initialSize* sizeof(Button*);
    buttonArr->length = 0;
};

void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w, void (*action) (), SDL_Color color){
    Button* newButton = malloc(sizeof(Button));

    newButton->sourceRect.x = x;
    newButton->sourceRect.y = y;
    newButton->sourceRect.h = h;
    newButton -> sourceRect.w = w;

    newButton->actionFunc = action;
    newButton->color = color;

    buttonArr->buttons = realloc(buttonArr->buttons, buttonArr->arrDataSize+sizeof(newButton));
    buttonArr->buttons[buttonArr->length] = newButton;
    buttonArr->arrDataSize += sizeof(newButton);
    buttonArr->length += 1;
}

void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr){
    if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT){        
        int clickX = event->button.x;
        int clickY = event->button.y;
            for (int i=0; i<buttonArr->length; i++){
                Button* currentButton = buttonArr->buttons[i];
                int buttonLeftEdge = currentButton->sourceRect.x;
                int buttonRightEdge = buttonLeftEdge + currentButton->sourceRect.w;
                int buttonTop = currentButton->sourceRect.y;
                int buttonDown = currentButton->sourceRect.h + buttonTop;
                if (buttonLeftEdge<clickX && buttonRightEdge>clickX && buttonTop<clickY && buttonDown>clickY){
                    currentButton->actionFunc();
                }            
            }
    }
}

void renderButtons(ButtonsArray* buttonArr, SDL_Renderer* renderer){
    for (int i=0; i<buttonArr->length; i++){
        SDL_Color renderColor = buttonArr->buttons[i]->color;
        SDL_SetRenderDrawColor(renderer, renderColor.r, renderColor.g, renderColor.b, renderColor.a);
        SDL_RenderFillRect(renderer, &buttonArr->buttons[i]->sourceRect);
    }
}

void freeButtonArray(ButtonsArray* buttonArr){
    free(buttonArr->buttons);
    buttonArr->arrDataSize = 0;
    buttonArr->length = 0;
}