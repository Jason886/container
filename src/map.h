#ifndef _MAP_H_
#define _MAP_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*map_hash)(void *key);
typedef int (*map_equals)(void *key1, void *key2);

typedef struct _map_node_t {
    void *key;
    void *value;
    struct _map_node_t *next;
} map_node_t;

typedef struct {
    map_hash hash;
    map_equals equals;
    int capacity;
    map_node_t *nodes;
} map_t;


map_t * map_new(map_hash hash, map_equals equals, int capacity);
void map_delete(map_t *map);
void map_set(map_t *map, void *key, void *val);
const void * map_get(map_t *map, void *key);
void map_remove(map_t *map , void *key);
void map_has(map_t *map, void *key);

int map_string_hash(void * key);
int map_string_equals(void *key1, void *key2);

#define map_foreach(map, key, value) \
nothing

#ifdef __cplusplus
}
#endif

#endif
