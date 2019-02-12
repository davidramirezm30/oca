/** 
 * @brief It defines a player
 * 
 * @file player.c
 * @author David Ramirez
 * @version 1.0 
 * @date 08/02/2019
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

/** 
 * @brief The structure of the player
 *
 * It stores information of the player, 
 * such as the identification number, the name, the location
 * and the object is going to be moved
 */
struct _Player {
  Id id;
  char name[WORD_SIZE + 1];
  Id location;
  Id ported_object;
};

/**
* @brief Computes the creation of the player
*
* player_create creates a new player assigning a position of the 
* memory for its id number
*
* @date 08/02/2019
* @author David Ramirez
*
* @param id is the identification number of the player
* @return the new player which has been created
*/
Player* player_create(Id id) {

  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->location = NO_ID;
  
  newPlayer->ported_object = NO_ID;

  return newPlayer;
}

/**
* @brief Computes the destruction of players
*
* player_destroy destroy a player 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player which is going to be destroyed
* @return the status (if the game has been created successfully or not)
*/
STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

/**
* @brief sets a name to a player
*
* player_set_name sets the value of the name to the player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player which is going to be named
* @param name is the name which is going to be set to the player
* @return the status (if the game has been created successfully or not)
*/
STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

/**
* @brief sets a location 
*
* player_set_location sets the value of the location to the player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose location is going to be set
* @param id is the identification number of the player
* @return the status (if the game has been created successfully or not)
*/
STATUS player_set_location(Player* player, Id location) {
  if (!player || location == NO_ID) {
    return ERROR;
  }
  player->location = location;
  return OK;
}

/**
* @brief 
*
* player_set_ported_object 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player
* @param ported_object
* @return the status (if the game has been created successfully or not)
*/
STATUS player_set_ported_object(Player* player, Id ported_object) {
  if (!player || ported_object == NO_ID) {
    return ERROR;
  }
  player->ported_object = ported_object;
  return OK;
}

/**
* @brief gets the id of a player
*
* player_get_id gets the value of the id from a player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose id we want to know
* @return the id of the player
*/
Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

/**
* @brief gets the name of a player
*
* player_get_name gets the value of the name from a player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose name we want to know
* @return the name of the player
*/
const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

/**
* @brief gets the location of a player
*
* player_get_location gets the value of the location from a player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose location we want to know
* @return the location of the player
*/
Id player_get_location(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->location;
}

/**
* @brief gets the object a player has ported
*
* player_get_ported_object gets the value of the ported object by a player
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose ported object we want to know
* @return the ported object by the player
*/
Id player_get_ported_object(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->ported_object;
}

/**
* @brief Prints the information we want to know from a player
*
* player_print prints the id, the name, the location from a player and
* the object that has been ported 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param player is the player whose information we want to print
* @return the status (if the game has been created successfully or not)
*/
STATUS player_print(Player* player) {
  Id idaux = NO_ID;
	
  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  idaux = player_get_location(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Player location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No player location available.\n");
  }
  
  idaux = player_get_ported_object(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Object which has been ported: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No object has been ported.\n");
  }
  
  return OK;
}
