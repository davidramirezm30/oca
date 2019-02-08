/** 
 * @brief It defines the game loop 
 * 
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0 
 * @date 13-01-2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"

int main(int argc, char *argv[]){
	Game game;
	T_Command command = NO_CMD; 
	Graphic_engine *gengine;
  
	/*Comprueba el numero de argumentos*/
	if (argc < 2){
		fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); 
		return 1;
	}
	/*Crea el juego desde fichero argv[1]*/
	if (game_create_from_file(&game, argv[1]) == ERROR){
		fprintf(stderr, "Error while initializing game.\n"); 
		return 1;
		}
	/*Crea el motor grafico y si ha habido algun error lo escribe por consola y borra la memoria asignada*/
	if ((gengine = graphic_engine_create()) == NULL){
		fprintf(stderr, "Error while initializing graphic engine.\n");
		game_destroy(&game); 
		return 1;
	}
	
	while ( (command != EXIT) && !game_is_over(&game) ){
		graphic_engine_paint_game(gengine, &game); /*Pinta el juego*/
		command = get_user_input(); /*Lee el comando que mete el jugador*/
		game_update(&game, command); /*Actualiza el juego*/
	} 
	
	game_destroy(&game); /*Libera memoria*/
	graphic_engine_destroy(gengine);
	return 0;
}
