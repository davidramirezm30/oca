/** 
 * @brief It defines an object
 * 
 * @file object.h
 * @author David Ramirez
 * @version 1.0 
 * @date 08/02/2019
 */

#ifndef OBJECT_H
#define OBJECT_H
 
#include "types.h"

typedef struct _Object Object;

#define MAX_OBJECTS 4

Object* object_create(Id id);
STATUS object_destroy(Object* object);
Id object_get_id(Object* object);
const char * object_get_name(Object* object);
STATUS object_set_name(Object* object, char* name);
STATUS object_print(Object* object);

#endif