all:
	gcc Main.c EventHandler.c Render.c Block.c ColorHandler.c -ISDL2\include\SDL2 -LSDL2\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o bootlegpaint
