# Macros

CC = gcc
CFLAGS = -g -Wall -pedantic -ansi
OBJ = graphic_engine.o screen.o game.o command.o player.o object.o space.o game_reader.o game_loop.o


# Reglas implicitas
game_loop: $(OBJ)
	$(CC) -o game_loop $(OBJ)
game_loop.o: game_loop.c graphic_engine.h
	#$(CC) $(CFLAGS) -c game_loop.c
	$(CC) -c $(CFLAGS) $^
graphic_engine.o: graphic_engine.c graphic_engine.h screen.h game.h
	#$(CC) $(CFLAGS) -c graphic_engine.c
	$(CC) -c $(CFLAGS) $^
screen.o: screen.c screen.h graphic_engine.c graphic_engine.h
	#$(CC) $(CFLAGS) -c screen.c
	$(CC) -c $(CFLAGS) $^
game.o: game.c game.h command.h space.h
	#$(CC) $(CFLAGS) -c game.c
	$(CC) -c $(CFLAGS) $^
command.o: command.c command.h game_loop.c game.c game.h
	#$(CC) $(CFLAGS) -c command.c
	$(CC) -c $(CFLAGS) $^
player.o: player.c player.h game.c game.h
	#$(CC) $(CFLAGS) -c player.c
	$(CC) -c $(CFLAGS) $^
object.o: object.c game.c game.h
	#$(CC) $(CFLAGS) -c object.c
	$(CC) -c $(CFLAGS) $^
space.o: space.c space.h types.h
	#$(CC) $(CFLAGS) -c space.c
	$(CC) -c $(CFLAGS) $^

# Reglas explícitas

all: game_loop

clean:
	$(RM) $(OBJ) game_loop.o game_loop