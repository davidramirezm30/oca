#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "types.h"

STATUS game_set_player_location(Game* game, Id id) {
    
  if (id == NO_ID) {
    return ERROR;
  }

  game->player_location = id;

}


Id game_get_player_location(Game* game) {
  return game->player_location;
}
