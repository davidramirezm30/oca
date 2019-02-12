/** 
 * @brief It takes the information from a file to create 
 * the game and defines the interface.
 * 
 * @file game_reader.c
 * @author David Ramirez
 * @version 1.0 
 * @date 10/02/2019
 */

#ifndef GAME_READER_H
#define GAME_READER_H
#include "game.h"

STATUS game_create_from_file(Game* game, char* filename);
STATUS game_reader_load_spaces(Game* game, char* filename);

#endif