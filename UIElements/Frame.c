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

void frame_free(Frame* frame){
    for (int i=0; i<frame->labelArrLen;i++){
        free(frame->labelArr[i]);
    }
    frame->labelArrLen = 0;
    frame->labelArrSize = 0;
}