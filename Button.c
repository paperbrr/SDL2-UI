#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Declarations.h"

void buttonsArr_init(ButtonsArray* buttonArr){
    buttonArr->buttons = malloc(sizeof(Button));
    if (buttonArr->buttons==NULL){
        printf("ERROR");
        exit(1);
    }
    buttonArr->arrDataSize = sizeof(Button);
    buttonArr->length = 0;
};

void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w){
    Button* newButton = malloc(sizeof(Button));
    newButton->x = x;
    newButton->y = y;
    newButton->height = h;
    newButton -> width = w;

    buttonArr->buttons = realloc(buttonArr->buttons, buttonArr->arrDataSize+sizeof(newButton));
    buttonArr->length += 1;
}

void buttonClicked(ButtonsArray* buttonArr, int clickX, int clickY){
    for (int i=0; i<buttonArr->length; i++){
        Button* currentButton = buttonArr->buttons[i];
        if (currentButton->x+currentButton>clickX && currentButton->y+currentButton>clickY){
            printf("I GOT CLICKED");
        } 
    }
}