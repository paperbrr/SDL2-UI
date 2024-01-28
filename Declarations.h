#include <SDL.h>
#include <SDL_image.h>

typedef struct{
    int x;
    int y;
    int height;
    int width;
    SDL_Rect sourceRect;
    SDL_Color color;
    void (*actionFunc) (void* button);
} Button;

typedef struct{
    int length;
    int arrDataSize;
    Button** buttons;
} ButtonsArray;