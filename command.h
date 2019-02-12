/** 
 * @brief It implements the command interpreter
 * 
 * @file command.h
 * @author David Ramirez
 * @version 1.1 
 * @date 12/02/2019 
 */

#ifndef COMMAND_H
#define COMMAND_H

typedef enum enum_Command {
  NO_CMD = -1, 
  UNKNOWN, 
  EXIT, 
  NEXT, 
  BACK,
  TAKE,
  DROP} T_Command;

T_Command get_user_input();

#endif
