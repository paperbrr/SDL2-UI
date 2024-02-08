#pragma once
#include <SDL.h>

typedef enum{
    label,
    button,
    textbox,
    frame
}UITypes;

typedef struct{
    void* parentFrame;
    UITypes type;

    SDL_Rect sourceRect;
    SDL_Rect wrapperRect;
    SDL_Texture* labelTexture;

    SDL_Color color;
    char* text;
}Label;

typedef struct{
    void* parentFrame;
    UITypes type;

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
void label_SetText(Label* label, char* text, SDL_Renderer* renderer);

Button* createButton(Frame* parentFrame, SDL_Color color,void (*actionFunc) (), int x, int y, int w, int h);
void button_handleClicks(Frame* frame, int mouseClickX, int mouseClickY);
void button_SetText(Button* button, char* text, SDL_Renderer* renderer);

void frame_init(Frame* frame);
void frame_alloc(Frame* frame, UITypes type, void* uiElement);
void frame_free(Frame* frame);