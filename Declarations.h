#include <SDL.h>

typedef struct{
    SDL_Rect sourceRect;
    SDL_Color color;
    void (*actionFunc) (void* button);
} Button;

typedef struct{
    int length;
    int arrDataSize;
    Button** buttons;
} ButtonsArray;

void buttonsArr_init(ButtonsArray* buttonArr, int initialSize);
void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w);
void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr);