#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "map.h"

#define _DEFAULT_CAPACITY 128

map_t * map_new(map_hash hash, map_equals equals, size_t capacity) {
    map_t * map = 0;
    map = malloc(sizeof(*map));
    if(map) {
        map->nodes = malloc(sizeof(*(map->nodes)) * capacity);
        if(map->nodes) {
            memset(map->nodes, 0x00, sizeof(*(map->nodes)) * capacity);
            map->hash = hash ? hash : map_string_hash;
            map->equals = equals ? equals : map_string_equals;
            map->capacity = capacity ? capacity : _DEFAULT_CAPACITY;
        }
        else {
            free(map);
            map = 0;
        }
    }

    return map;
}

void map_delete(map_t *map) {
    int i;
    map_node_t *p, *q;
    for(i = 0; i < map->capacity; ++i) {
        for(p = map->nodes[i]; p;) {
            q = p;
            p = p->next;
            free(q);
        }
    }
    free(map->nodes);
    free(map);
}

void map_set(map_t *map, const void *key, const void *val) {
    int i;
    map_node_t *n, *p;
    
    i = map->hash(key) & map->capacity;
    if(!map->nodes[i]) {
        n = malloc(sizeof(*n));
        map->nodes[i] = n;
    }
    else {
        for(p = map->nodes[i]; p; p = p->next) {
            if(map->equals(p->key, key)) {
                n = p;
                break;
            }
            else if(!p->next) {
                n = malloc(sizeof(*n));
                p->next = n;
            }
        }
    }

    n->key = key;
    n->value = val;
}

const void * map_get(map_t *map, const void *key) {
    int i;
    map_node_t * n;
    i = map->hash(key) % map->capacity;
    for(n = map->nodes[i]; n; n = n->next) {
        if(map->equals(n->key, key)) {
            return n->value;
        }
    }
    return NULL;
}

void map_remove(map_t *map , const void *key) {
    int i;
    map_node_t *n, *pre;
    i = map->hash(key) % map->capacity;
    for(n = map->nodes[i], pre = NULL; n; pre = n, n = n->next) {
        if(map->equals(n->key, key)) {
            if(!pre) {
                map->nodes[i] = n->next;
            }
            else {
                pre->next = n->next;
            }
            free(n);
        }
   }
}

map_iter_t map_get_iter(map_t *map) {
    map_iter_t iter;
    memset(&iter, 0x00, sizeof(iter));
    iter._map = map;
    return iter;
}

int map_iter_next(map_iter_t *iter) {
    int i = 0;
    map_node_t *n = 0;
    assert(iter);
    assert(iter->_map);
    if(!iter) return 0;
    if(!iter->_map) return 0;
    
    i = iter->_index;
    n = iter->_node;
    if(n->next) {
        n = n->next;
    }
    else {
        i++;
        while(i<iter->_map->capacity) {
           n = iter->_map->nodes[i];
           if(!n) {
               i++;
           }
        }
    }
    iter->key = 0;
    iter->value = 0;
    iter->_index = i;
    iter->_node = n;
    if(i < iter->_map->capacity && n) {
        iter->key = (void *)n->key;
        iter->value = (void *)n->value;
        return 1;
    }

    return 0;
}

int map_has(map_t *map, const void *key) {
    int i;
    map_node_t *n;

    i = map->hash(key) % map->capacity;
    for(n = map->nodes[i]; n; n = n->next) {
        if(map->equals(n->key, key)) {
            return 1;
        }
    }
    return 0;
}

int map_string_hash(const void *key) {
    int i = 0;
    char *p = (char *)key;
    while (*p) {
        i += i * 131 + (*p++);
    }
    return i & 0x7FFFFFFF;
}

int map_string_equals(const void *key1, const void *key2) {
    return !strcmp((const char *)key1, (const char *)key2);
}
