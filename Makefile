mac2019:
	clang *.c -o potbellied -F/Library/Frameworks -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2 -I/Library/Frameworks/SDL2_image.framework/Headers -framework SDL2_image -I/Library/Frameworks/SDL2_ttf.framework/Headers -framework SDL2_ttf

Windows:
	gcc -I"..\SDL2\include" -o .\potBelliedPig.exe .\main.c .\source\utilities.c .\source\run.c .\source\update.c .\source\game.c .\source\containers.c .\source\character.c .\source\init.c .\source\graphics\graphic.c .\source\food.c .\source\mainmenu.c .\source\fight.c .\source\free.c .\maps\worlds.c .\source\record.c .\source\button.c .\source\levelmenu.c .\source\deathscreen.c .\source\winscreen.c .\source\startscreen.c -L"..\SDL2\lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lopengl32

Mac:
	gcc -o ./potBelliedPig ./main.c ./source/utilities.c ./source/run.c ./source/update.c ./source/game.c ./source/containers.c ./source/character.c ./source/init.c ./source/graphics/graphic.c ./source/food.c ./source/mainmenu.c ./source/fight.c ./source/free.c ./maps/worlds.c ./source/record.c ./source/button.c ./source/levelmenu.c ./source/deathscreen.c ./source/winscreen.c ./source/startscreen.c `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
