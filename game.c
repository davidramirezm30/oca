/** 
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 * 
 * @file game.c
 * @author David Ramirez
 * @version 1.0 
 * @date 09/01/2019 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

#define N_CALLBACK 6

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game 
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_next(Game* game);
void game_callback_back(Game* game);
void game_callback_take(Game* game);
void game_callback_drop(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop};

/**
   Private functions
*/

/*STATUS game_load_spaces(Game* game, char* filename);*/
STATUS game_add_space(Game* game, Space* space);
Id     game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

/**
   Game interface implementation
*/



STATUS game_create(Game* game) {
  int i;
  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  
  game->player = NULL;
  game->object = NULL;
  game->last_cmd = NO_CMD;
  
  return OK;
}

STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }
        
  return OK;
}

STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }
    
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }
    
  return NULL;
}

STATUS game_set_player_location(Game* game, Id id) {
    
  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player,id);
  
  return OK;
}

STATUS game_set_object_location(Game* game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }
  
  return OK;
}

Id game_get_player_location(Game* game) {
  return player_get_location(game->player);
}

Id game_get_object_location(Game* game) {
  int i = 0;
  Id space_id = NO_ID;
  Id possible_object = NO_ID;

  /*************************************************************/
  if(player_get_ported_object(game->player)){
  	return player_get_location(game->player);
  }
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_id = space_get_id(game->spaces[i]);
	fprintf(stdout, "--> Space (Id: %ld)\n", space_id);
	possible_object = space_get_object(game->spaces[i]);
	fprintf(stdout, "--> Object (Id: %ld)\n", possible_object);
    if (space_id == possible_object) {
      /*space_id = space_get_south(game->spaces[i]);
      if (space_id != NO_ID) {
        game_set_player_location(game, space_id);
      }*/
      return space_get_id(game->spaces[i]);
    }
  }/***************************************************************/
	
  return NO_ID;
}

STATUS game_update(Game* game, T_Command cmd) {
  game->last_cmd = cmd;
  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}

/**
* @brief Prints the information we want to know
*
* game_print_data prints the location of the object and the player
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game
*/
void game_print_data(Game* game) {
  int i = 0;
  
  printf("\n\n-------------\n\n");
  
  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }
  
  printf("=> Object location: %ld\n", (Id) game->object);    
  printf("=> Player location: %ld\n", (Id) game->player);
  printf("prompt:> ");
}

/**
* @brief when the game ends
*
* game_is_over used when the game ends
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game
* @return FALSE
*/
BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action 
*/

/**
* @brief when there is and unknown command, it does not do anything
*
* game_callback_unknown used if something unknown is written with the keyboard
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game
* @return it doesn't return anything because it's type void
*/
void game_callback_unknown(Game* game) {
}

/**
* @brief when write e with the keyboard, exit the game
*
* game_callback_exit used to go exit the game
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game
* @return it doesn't return anything because it's type void
*/
void game_callback_exit(Game* game) {
}

/**
* @brief when write n with the keyboard, go to the next space in the game
*
* game_callback_next used to go to the next space
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game
* @return it doesn't return anything because it's type void
*/
void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/**
* @brief when write b with the keyboard, go a space back in the game
*
* game_callback_back used to go to the back space
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game
* @return it doesn't return anything because it's type void
*/
void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  
  if (NO_ID == space_id) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/**
* @brief when write t with the keyboard, take the object
*
* game_callback_take takes the object
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game where we want to take an object
* @return it doesn't return anything because it's type void
*/
void game_callback_take(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;  
  /*Id object = NO_ID;*/
  Id player_id = NO_ID;
  
  player_id = game_get_player_location(game);
  if (NO_ID == player_id) {
    return;
  }
  /*object = space_get_object(game->player);*/
  space_id = game_get_object_location(game);
  
  if (NO_ID == space_id) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

/**
* @brief when write d with the keyboard, drops the object
*
* game_callback_drop drops the object
*
* @date 12/02/2019
* @author David Ramirez
*
* @param game is the game where we want to drop an object
* @return it doesn't return anything because it's type void
*/
void game_callback_drop(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_object_location(game);
  
  if (NO_ID == space_id) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_object_location(game, current_id);
      }
      return;
    }
  }
}
