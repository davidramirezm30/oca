/** 
 * @brief It takes the information from a file to create 
 * the game and defines the interface.
 * 
 * @file game_reader.c
 * @author David Ramirez
 * @version 1.0 
 * @date 10/02/2019
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

/**
* @brief Computes the creation of the game
*
* game_reader_load_spaces 
*
* @date 11/02/2019
* @author David Ramirez
* @param game is the game which has been created
* @param filename is the file which is going to be read
* @return the status (if the game has been created successfully or not)
*/
STATUS game_reader_load_spaces(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space* space = NULL;
  STATUS status = OK;
  
  if (!filename) {
    return ERROR;
  }
  
  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG 
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
	space_set_name(space, name);
	space_set_north(space, north);
	space_set_east(space, east);
	space_set_south(space, south);
	space_set_west(space, west);
	game_add_space(game, space);
      }
    }
  }
  
  if (ferror(file)) {
    status = ERROR;
  }
  
  fclose(file);
  
  return status;
}

/**
* @brief Computes the creation of the game
*
* game_create_from_file creates the game, loading all necessary information
* from a file
*
* @date 11/02/2019
* @author David Ramirez
* @param game is the game is going to be created
* @param filename is the file which is going to be read
* @return the status (if the game has been created successfully or not)
*/
STATUS game_create_from_file(Game* game, char* filename) {
  if (game_create(game) == ERROR)
    return ERROR;

  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  /*game_set_player_location(game, game_get_space_id_at(game, 0));*/
  player_set_location(game->player, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}