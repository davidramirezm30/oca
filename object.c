#include <stdio.h>
#include <stdlib.h>
#include "object.h"

STATUS game_set_object_location(Game* game, Id id) {
  
  int i = 0;

  if (id == NO_ID) {
    return ERROR;
  }

  game->object_location = id;

  return OK;
}

Id game_get_object_location(Game* game) {
  return game->object_location;
}