CFLAGS=-std=c17 -Wall -Wextra -Werror
SDLFLAGS=`sdl2-config --cflags --libs`
all:
	clear
	gcc main.c -o main.out $(CFLAGS) $(SDLFLAGS)
	./main.out