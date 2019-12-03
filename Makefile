FLAGS = -F/Library/Frameworks
SDL2 = -I/Library/Frameworks/SDL2.framework/Headers -framework SDL2
SDL_IMAGE = -I/Library/Frameworks/SDL2_image.framework/Headers -framework SDL2_image
SDL_TTF = -I/Library/Frameworks/SDL2_ttf.framework/Headers -framework SDL2_ttf

macos:
	clang *.c source/*.c source/graphics/*.c maps/*.c -o potbellied $(FLAGS) $(SDL2) $(SDL_IMAGE) $(SDL_TTF)
