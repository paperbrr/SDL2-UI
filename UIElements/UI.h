#pragma once
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

extern char* fontPath;
extern int fontSize;
void fontInit(char* newPath, int fontSize);

typedef enum{
    LABEL,
    BUTTON,
    TEXTBOX,
    FRAME
}UITypes;

typedef struct{
    void* parentFrame;
    UITypes type;

    int visible;

    SDL_Rect sourceRect;
    SDL_Rect wrapperRect;
    SDL_Texture* labelTexture;

    SDL_Color color;
    char* text;
}Label;

typedef struct{
    void* parentFrame;
    UITypes type;

    int visible;

    SDL_Rect sourceRect;
    SDL_Rect wrapperRect;
    SDL_Texture* buttonTexture;

    SDL_Color color;
    char* text;
    void (*actionFunc) ();
}Button;

typedef struct{
    void* parentFrame;
    UITypes type;

    SDL_Rect sourceRect;
    void (*clickedFunc) (void*);  //set this up :D
}TextBox;

typedef struct{
    UITypes type;

    int visible;

    Label** labelArr;
    Button** buttonArr;
    TextBox** textBoxArr;

    int labelArrLen;
    int buttonArrLen;
    int textboxArrlen;

    int labelArrSize;
    int buttonArrSize;
    int textBoxArrSize;
}Frame;


Label* createLabel(Frame* parentFrame, SDL_Color color, int x, int y, int w, int h);
void label_SetText(Label* label, char* text, SDL_Renderer* renderer, SDL_Color textColor);
void label_free(Label* label);

Button* createButton(Frame* parentFrame, SDL_Color color,void (*actionFunc) (), int x, int y, int w, int h);
void button_handleClicks(Frame* frame, int mouseClickX, int mouseClickY);
void button_SetText(Button* button, char* text, SDL_Renderer* renderer, SDL_Color textColor);
void button_free(Button* button);

void frame_init(Frame* frame, int initialSize);
void renderFrame(SDL_Renderer* renderer, Frame* frame);
void frame_alloc(Frame* frame, UITypes type, void* uiElement);
void frame_free(Frame* frame);
int frame_DelChild(Frame* frame, void* child, UITypes type);

SDL_Texture* createCharTexture(char* text, int* wrapperW, int* wrapperH, SDL_Renderer* renderer, SDL_Color textColor);
void wrapText(SDL_Rect* wrapperRect, SDL_Rect* parentRect);