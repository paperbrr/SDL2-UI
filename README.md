A simple button for SDL2 projects :D

Features ->
1) Custom color for your button
2) Freedom to define its dimensions
3) Option to assign a custom event when it is clicked
4) An array of all buttons created for easy tracking

Usage ->
1) Place ```Button.c``` and ```Declarations.h``` in the same directory
2) Initialise the ```buttonArray``` struct
3) To create a block, use the ```createButton()``` function with appropriate parameters [the button array, x, y, w, h, action-function, color]
4) Use the ```renderButtons``` function to render all the buttons in your ```buttonArray``` (should be placed before a ```SDL_RenderPresent```)
5) Use the ```buttonClickHandler``` function in your event loop to sort out button click events and react with the assigned action function

Make sure to use the ```freeButtonArray``` at the end of your program to prevent memory leaks!
