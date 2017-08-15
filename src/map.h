/*******************************************************************************
* Copyright (C), 2017-2022, 359152155@qq.com.
*
* FileName    : map.h
* Author      : xianchen.p
* Date        : 2017-08-15 
* Description : 
* Github      : https://github.com/Jason886/container
*------------------------------------------------------------------------------*
* Record      :
*******************************************************************************/
#ifndef _MAP_H_
#define _MAP_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*map_hash)(const void *key);
typedef int (*map_equals)(const void *key1, const void *key2);

typedef struct _map_node_t {
    const void *key;
    const void *value;
    struct _map_node_t *next;
} map_node_t;

typedef struct {
    map_hash hash;
    map_equals equals;
    size_t capacity;
    map_node_t **nodes;
} map_t;

typedef struct _map_iter_t {
    void *key;
    void *value;
    map_t *_map;
    size_t _index;
    map_node_t *_node;
} map_iter_t;


map_t * map_new(map_hash hash, map_equals equals, size_t capacity);
void map_delete(map_t *map);
void map_set(map_t *map, const void *key, const void *val);
const void * map_get(map_t *map, const void *key);
void map_remove(map_t *map , const void *key);
int map_has(map_t *map, const void *key);

int map_string_hash(const void * key);
int map_string_equals(const void *key1, const void *key2);

map_iter_t map_get_iter(map_t *map);
int map_iter_next(map_iter_t *iter);


#ifdef __cplusplus
}
#endif

#endif
