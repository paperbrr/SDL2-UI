#include "UI.h"

void frame_init(Frame* newFrame, int initialSize){
    newFrame->type = frame;

    newFrame->buttonArr = malloc(sizeof(Button*)*initialSize);
    newFrame->labelArr = malloc(sizeof(Label*)*initialSize);
    newFrame->textBoxArr = malloc(sizeof(TextBox*)*initialSize);

    if (newFrame->buttonArr==NULL || newFrame->labelArr==NULL || newFrame->textBoxArr==NULL){printf("error");return;}

    newFrame->buttonArrLen = 0;
    newFrame->labelArrLen = 0;
    newFrame->textboxArrlen = 0;

    newFrame->buttonArrSize = sizeof(Button*)*initialSize;
    newFrame->labelArrSize = sizeof(Label*)*initialSize;
    newFrame->textBoxArrSize = sizeof(TextBox*)*initialSize;
}

void frame_alloc(Frame* frame, UITypes type, void* uiElement){
    if (type==button){
        if (frame->buttonArrSize - (sizeof(Button*)*frame->buttonArrLen) < 10*sizeof(Button*)) {frame->buttonArr = realloc(frame->buttonArr, frame->buttonArrSize+10*sizeof(Button*));}
        if (frame->buttonArr==NULL){printf("error");return;}
        frame->buttonArr[frame->buttonArrLen] = (Button*) uiElement;
        frame->buttonArrLen += 1;
        frame->buttonArrSize += sizeof(Button*);
    }
    else if (type==label){
        if (frame->labelArrSize - (sizeof(Label*)*frame->labelArrLen) < 10*sizeof(Label*)) {frame->labelArr = realloc(frame->labelArr, frame->labelArrSize+10*sizeof(Label*));}
        if (frame->labelArr==NULL){printf("error");return;}
        frame->labelArr[frame->labelArrLen] = (Label*) uiElement;
        frame->labelArrLen += 1;
        frame->labelArrSize += sizeof(Label*);
    }
}

void renderFrame(SDL_Renderer* renderer, Frame* frame){

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    for (int i=0; i<frame->buttonArrLen; i++){
        Button* button = frame->buttonArr[i];
        SDL_SetRenderDrawColor(renderer, button->color.r, button->color.g, button->color.b, button->color.a);
        SDL_RenderFillRect(renderer, &button->sourceRect);
        SDL_SetRenderDrawColor(renderer, button->color.r, button->color.g, button->color.b, 0);
        SDL_RenderFillRect(renderer, &button->wrapperRect);
        if (button->buttonTexture!=NULL) {SDL_RenderCopy(renderer, button->buttonTexture, NULL, &button->wrapperRect);}
    }
    for (int i=0; i<frame->labelArrLen; i++){
        Label* label = frame->labelArr[i];
        SDL_SetRenderDrawColor(renderer, label->color.r, label->color.g, label->color.b, label->color.a);
        SDL_RenderFillRect(renderer, &label->sourceRect);
        SDL_SetRenderDrawColor(renderer, label->color.r, label->color.g, label->color.b, 0);
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