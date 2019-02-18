/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author David Ramirez
 * @version 1.1 
 * @date 18/02/2019 
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30
#define N_CMD 7

char *cmd_to_str[N_CMD] = {"No command", "Unknown", "Exit", "Next", "Back", "Take", "Drop"};
char *short_cmd_to_str[N_CMD] = {"","","e","n","b","t","d"};

/**
* @brief Takes the parameters written with the keyboard
*
* get_user_input gets the input written with the keyboard to know what it has to do.
* The possibilities are "No command", "Unknown", "Exit", "Next", "Back", "Take", "Drop"
*
* @date 18/02/2019
* @author David Ramirez
*
* @return the parameter written with the keyboard
*/
T_Command get_user_input(){
	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	int i=UNKNOWN - NO_CMD + 1;
	  
	if (scanf("%s", input) > 0){    
		cmd = UNKNOWN;
		while(cmd == UNKNOWN && i < N_CMD){
			if (!strcasecmp(input,short_cmd_to_str[i]) || !strcasecmp(input,cmd_to_str[i])){
				cmd = i + NO_CMD;
			}else{
				i++;
			}
		}
	}
	return cmd;
}
