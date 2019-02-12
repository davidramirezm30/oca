# Macros

CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = graphic_engine.o screen.o game.o command.o player.o object.o space.o game_reader.o game_loop.o


# Reglas implicitas
oca: $(OBJ)
	$(CC) -o oca $(OBJ)
game_loop.o: game_loop.c graphic_engine.h
	$(CC) -c $(CFLAGS) $<
graphic_engine.o: graphic_engine.c graphic_engine.h screen.h game.h
	$(CC) -c $(CFLAGS) $<
screen.o: screen.c screen.h graphic_engine.h
	$(CC) -c $(CFLAGS) $<
game.o: game.c game.h command.h space.h player.h object.h
	$(CC) -c $(CFLAGS) $<
game_reader.o: game_reader.c game_reader.h game.h
	$(CC) -c $(CFLAGS) $<
command.o: command.c command.h
	$(CC) -c $(CFLAGS) $<
player.o: player.c player.h types.h
	$(CC) -c $(CFLAGS) $<
object.o: object.c types.h
	$(CC) -c $(CFLAGS) $<
space.o: space.c space.h types.h
	$(CC) -c $(CFLAGS) $<

# Reglas explícitas

all: oca

clean:
	$(RM) $(OBJ) oca
	clear
