#include <SDL.h>

typedef struct{
    SDL_Rect sourceRect;
    SDL_Color color;
    void (*actionFunc) ();
} Button;

typedef struct{
    int length;
    int arrDataSize;
    Button** buttons;
} ButtonsArray;

void buttonsArr_init(ButtonsArray* buttonArr, int initialSize);
void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w, void (*actionPtr) ());
void renderButtons(ButtonsArray* buttonArr, SDL_Renderer* renderer);
void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr);
void freeButtonArray(ButtonsArray* buttonArr);