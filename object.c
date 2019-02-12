/** 
 * @brief It defines an object
 * 
 * @file object.c
 * @author David Ramirez
 * @version 1.0 
 * @date 08/02/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/** 
 * @brief The structure of the object
 *
 * It stores information of the object, 
 * such as the identification number and the name 
 */
struct _Object {
  Id id; /*!< Id of the object */
  char name[WORD_SIZE + 1]; /*!< Name of the object*/
};

/**
* @brief Computes the creation of objects
*
* object_create creates a new object assigning a position of the 
* memory for its id number
*
* @date 08/02/2019
* @author David Ramirez
*
* @param id is the identification number of the object
* @return the new object which has been created
*/
Object* object_create(Id id) {

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0';

  return newObject;
}

/**
* @brief Computes the destruction of objects
*
* object_destroy destroy an object 
*
* @date 08/02/2019
* @author David Ramirez
*
* @param object is the object which is going to be destroyed
* @return the status (if the game has been created successfully or not)
*/
STATUS object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

/**
* @brief sets a name to an object 
*
* object_set_name sets the value of the name to the object
*
* @date 08/02/2019
* @author David Ramirez
*
* @param object is the object which is going to be named
* @param name is the name which is going to be set to the object
* @return the status (if the game has been created successfully or not)
*/
STATUS object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

/**
* @brief gets the name of an object
*
* object_get_name gets the value of the name from an object
*
* @date 08/02/2019
* @author David Ramirez
*
* @param object is the object whose name we want to know
* @return the name of the object
*/
const char * object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

/**
* @brief gets the id of an object
*
* object_get_id gets the value of the id from an object
*
* @date 08/02/2019
* @author David Ramirez
*
* @param object is the object whose id we want to know
* @return the id of the object
*/
Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

/**
* @brief Prints the information we want to know from an object
*
* object_print prints the id and the name from an object
*
* @date 08/02/2019
* @author David Ramirez
*
* @param object is the object whose information we want to print
* @return the status (if the game has been created successfully or not)
*/
STATUS object_print(Object* object) {
  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}


