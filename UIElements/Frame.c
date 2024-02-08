#include "Declarations.h"

void frame_init(Frame* newFrame){
    newFrame->type = frame;

    newFrame->buttonArr = malloc(sizeof(Button*));
    newFrame->labelArr = malloc(sizeof(Label*));
    newFrame->textBoxArr = malloc(sizeof(TextBox*));

    if (newFrame->buttonArr==NULL || newFrame->labelArr==NULL || newFrame->textBoxArr==NULL){printf("error");return;}

    newFrame->buttonArrLen = 0;
    newFrame->labelArrLen = 0;
    newFrame->textboxArrlen = 0;

    newFrame->buttonArrSize = sizeof(Button*);
    newFrame->labelArrSize = sizeof(Label*);
    newFrame->textBoxArrSize = sizeof(TextBox*);
}

void frame_alloc(Frame* frame, UITypes type, void* uiElement){
    if (type==button){
        frame->buttonArr = realloc(frame->buttonArr, frame->buttonArrSize+sizeof(Button*));
        if (frame->buttonArr==NULL){printf("error");return;}
        frame->buttonArr[frame->buttonArrLen] = (Button*) uiElement;
        frame->buttonArrLen += 1;
        frame->buttonArrSize += sizeof(Button*);
    }
    else if (type==label){
        frame->labelArr = realloc(frame->labelArr, frame->labelArrSize+sizeof(Label*));
        if (frame->labelArr==NULL){printf("error");return;}
        frame->labelArr[frame->labelArrLen] = (Label*) uiElement;
        frame->labelArrLen += 1;
        frame->labelArrSize += sizeof(Label*);
    }
}

void renderFrame(SDL_Renderer* renderer, Frame* frame){

    for (int i=0; i<frame->buttonArrLen; i++){
        Button* button = frame->buttonArr[i];
        SDL_SetRenderDrawColor(renderer, button->color.r, button->color.g, button->color.b, button->color.a);
        SDL_RenderFillRect(renderer, &button->sourceRect);
        SDL_RenderFillRect(renderer, &button->wrapperRect);
        if (button->buttonTexture!=NULL) {SDL_RenderCopy(renderer, button->buttonTexture, NULL, &button->wrapperRect);}
    }
    for (int i=0; i<frame->labelArrLen; i++){
        Label* label = frame->labelArr[i];
        SDL_SetRenderDrawColor(renderer, label->color.r, label->color.g, label->color.b, label->color.a);
        SDL_RenderFillRect(renderer, &label->sourceRect);
        SDL_RenderFillRect(renderer, &label->wrapperRect);
        if(label->labelTexture!=NULL) {SDL_RenderCopy(renderer, label->labelTexture, NULL, &label->wrapperRect);}
    }
}

void frame_free(Frame* frame){
    for (int i=0; i<frame->labelArrLen;i++){
        free(frame->labelArr[i]);
    }
    frame->labelArrLen = 0;
    frame->labelArrSize = 0;
}