/** 
 * @brief It defines a space
 * 
 * @file space.c
 * @author David Ramirez
 * @version 1.1
 * @date 08/02/2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "space.h"

/** 
 * @brief The structure of the space
 *
 * It stores information of the space, 
 * such as the identification number, the name, the object and
 * the North, South, East and West
 */
struct _Space
{
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Id object;
};

/**
* @brief Computes the creation of the space
*
* space_create creates a new space 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param id is the identification number of the space
* @return the new space which has been created
*/
Space *space_create(Id id)
{

  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));

  if (newSpace == NULL)
  {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->object = NO_ID;

  return newSpace;
}

/**
* @brief Computes the destruction of the space
*
* space_destroy destroys an space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space which is going to be destroyed
* @return the status
*/
STATUS space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }

  free(space);
  space = NULL;

  return OK;
}

/**
* @brief sets a name to a space
*
* space_set_name sets the value of the name to the space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space which is going to be named
* @param name is the name which is going to be set to the space
* @return the status
*/
STATUS space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }

  return OK;
}

/**
* @brief sets the id of the space in the North
*
* space_set_north sets the value of the spache which is in the North
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space
* @param id is the identification number
* @return the status
*/
STATUS space_set_north(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->north = id;
  return OK;
}

/**
* @brief sets the id of the space in the South
*
* space_set_south sets the value of the spache which is in the South
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space
* @param id is the identification number
* @return the status
*/
STATUS space_set_south(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->south = id;
  return OK;
}


/**
* @brief sets the id of the space in the East
*
* space_set_east sets the value of the spache which is in the East
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space
* @param id is the identification number
* @return the status
*/
STATUS space_set_east(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->east = id;
  return OK;
}


/**
* @brief sets the id of the space in the West
*
* space_set_west sets the value of the spache which is in the West
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space
* @param id is the identification number
* @return the status
*/
STATUS space_set_west(Space *space, Id id)
{
  if (!space || id == NO_ID)
  {
    return ERROR;
  }
  space->west = id;
  return OK;
}


/**
* @brief sets and object to the space
*
* space_set_object sets and object to the space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space
* @param id is the identification number of the object
* @return the status
*/
STATUS space_set_object(Space *space, Id object)
{
  if (!space)
  {
    return ERROR;
  }
  space->object = object;
  return OK;
}

/**
* @brief gets the name of a space
*
* space_get_name gets the value of the name from a space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space whose name we want to know
* @return the name of the space
*/
const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}

/**
* @brief gets the id of a space
*
* space_get_id gets the value of the id from a space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space whose id we want to know
* @return the id of the space
*/
Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

/**
* @brief gets the id of the space in the North
*
* space_get_north gets the value of the id in the North of 
* the current space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the current space
* @return the id of the space in the North
*/
Id space_get_north(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->north;
}

/**
* @brief gets the id of the space in the South
*
* space_get_south gets the value of the id in the South of 
* the current space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the current space
* @return the id of the space in the South
*/
Id space_get_south(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->south;
}

/**
* @brief gets the id of the space in the East
*
* space_get_east gets the value of the id in the East of 
* the current space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the current space
* @return the id of the space in the East
*/
Id space_get_east(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->east;
}

/**
* @brief gets the id of the space in the West
*
* space_get_west gets the value of the id in the West of 
* the current space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the current space
* @return the id of the space in the West
*/
Id space_get_west(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->west;
}

/**
* @brief gets the object of a space
*
* space_get_object gets the value of the object from a space
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space where we want to know 
* if there is an object
* @return the id of the object
*/
Id space_get_object(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->object;
}

/**
* @brief Prints the information we want to know from a space
*
* space_print prints the id, the name, the location from a space and
* the object that has been ported 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param space is the space whose information we want to print
* @return the status
*/
STATUS space_print(Space *space)
{
  Id idaux = NO_ID;

  if (!space)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  }
  else
  {
    fprintf(stdout, "---> No west link.\n");
  }

  if (space_get_object(space))
  {
    fprintf(stdout, "---> Object in the space.\n");
  }
  else
  {
    fprintf(stdout, "---> No object in the space.\n");
  }

  return OK;
}
