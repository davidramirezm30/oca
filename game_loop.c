/** 
 * @brief It defines the game loop 
 * 
 * @file game_loop.c
 * @author Profesores PPROG && David Ramirez
 * @version 1.0 
 * @date 13/01/2015 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game_reader.h"

int main(int argc, char *argv[]){
	Game game;
	T_Command command = NO_CMD; 
	Graphic_engine *gengine;
  
	/*Check the number of arguments*/
	if (argc < 2){
		fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); 
		return 1;
	}
	/*Creates the game from the file loaded in argv[1]*/
	if (game_create_from_file(&game, argv[1]) == ERROR){
		fprintf(stderr, "Error while initializing game.\n"); 
		return 1;
		}
	/*Creates the graphic engine */
	if ((gengine = graphic_engine_create()) == NULL){
		fprintf(stderr, "Error while initializing graphic engine.\n");
		game_destroy(&game); /*Deletes the dynamic memory*/
		return 1;
	}
	
	while ( (command != EXIT) && !game_is_over(&game) ){
		graphic_engine_paint_game(gengine, &game); /*Paints the game*/
		command = get_user_input(); /*Reads the commands from the keyboard*/
		game_update(&game, command); /*Upgrades the game*/
	} 
	
	game_destroy(&game); /*Frees the memory*/
	graphic_engine_destroy(gengine); /*Frees the memory*/
	return 0;
}
