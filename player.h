/** 
 * @brief It defines a player
 * 
 * @file player.h
 * @author David Ramirez
 * @version 1.0 
 * @date 18/02/2019
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

Player *player_create(Id id);
STATUS player_destroy(Player *player);
STATUS player_set_name(Player *player, char *name);
STATUS player_set_location(Player *player, Id location);
Id player_get_id(Player *player);
const char *player_get_name(Player *player);
Id player_get_location(Player *player);
BOOL player_object(Player *player);
STATUS player_print(Player *player);

STATUS player_take_object(Player *player, Id id);
STATUS player_drop_object(Player *player);

#endif