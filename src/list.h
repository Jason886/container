#ifndef _LIST_H_
#define _LIST_H_

#ifdef __cplusplus
extern "C" {
#endif

struct _list_node_t;

typedef struct {
	struct _list_node_t * head_guard;
}list_t;

typedef struct _list_node_t {
	struct _list_node_t * next;
	struct _list_node_t * prev;
	list_t * list;
	size_t len;
	char data[1];
}list_node_t;

list_t * list_new();
void list_del(list_t * list);
int list_empty(list_t * list);
void list_remove_back(list_t *list);
void list_remove_front(list_t *list);
void list_remove(list_node_t * node);
int list_add_back(list_t * list, void *data, size_t len);
int list_add_front(list_t * list, void *data, size_t len);
int list_insert_after(list_node_t * node, void *data, size_t len);
int list_insert_before(list_node_t * node, void *data, size_t len);
void list_clear(list_t *list);
list_node_t * list_find(list_node_t * begin, void *data, size_t len);
list_node_t * list_find_r(list_node_t * begin, void *data, size_t len);


#define list_insert(node, data, len) list_insert_after(node, data, len)

#ifdef __cplusplus
}
#endif

#endif
