**A simple and easy to use UI Framework for SDL2 projects**

**NOTE : LABELS ARE RENDERED AFTER BUTTONS. IF A LABEL AND A BUTTON ARE CREATED IN THE SAME LOCATION, THE LABEL GETS RENDERING PRIORITY (WORKING ON FIXES FOR THIS). BUTTON CLICK FUNCTIONALITY FOR HIDDEN BUTTONS DOES NOT CHANGE.**

***DEPENDANCIES***
1) SDL2
2) SDL_ttf

***INITIALISATION INSTRUCTIONS***
1) Place the ``UIElements`` directory inside your working directory.
2) Include ``UI.h`` inside your file.
3) Add compilation instructions for ``Button.c``, ``Frame.c``, ``Label.c`` and ``Utils.c``.
4) Make sure that ``SDL_ttf`` is included and initialised.
5) Use the ``fontInit()`` function to set a font path and size.

***USAGE***

1) *Frames*
All UI elements are associated with a parent ``Frame`` object. Multiple frames can be created, and each frame has to be rendered separately. To create a frame, instantiate a new ``Frame`` struct and initialise it with the ``frame_init()`` function. Make sure to use ``free_frame()`` at the end (for each frame) to prevent memory leaks!

2) *Labels*
Label elements can be created using the ``createLabel()`` function. Changeable attributes include *x*, *y*, *w*, *h* and *color*. To set *text* for the label, use the ``label_SetText()`` function. The *text* property can be set without this function, but changes won't render. The rendered text is centered, but may explode if the size of the text is bigger than the size of the label.

3) *Buttons*
Button elements can be created using the ``createButton()`` function. Changeable attributes include *x*, *y*, *w*, *h*, *color* and *actionFunc*. The *actionFunc* attribute is a pointer to a user-defined function which will execute when it is clicked. The custom function should not take any arguments. To register clicks, use the ``button_HandleClicks()`` function. 