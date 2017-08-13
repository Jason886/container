#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include "list.h"

static list_node_t * _new_node(list_t *list, void *data, size_t len) {
	list_node_t *node = 0;
	node = malloc(sizeof(*node) + len);
	if(node) {
		memset(node, 0x00, sizeof(*node) + len);
		node->list = list;
		node->len = len;
		memcpy(node->data, data, len);
	}
	return node;
}

list_t * list_new() {
	list_t * list = 0;
	list = malloc(sizeof(*list));
	if(list) {
		list->head_guard = malloc(sizeof(*list->head_guard));
		if(!list->head_guard) {
			free(list);
			list = NULL;
		}
		else {
			memset(list->head_guard, 0x00, sizeof(*list->head_guard));
			list->head_guard->prev = list->head_guard;
			list->head_guard->next = list->head_guard;
		}
	}
	return list;
}

void list_del(list_t * list) {
	assert(list);
	if(list) {
		list_clear(list);
		free(list->head_guard);
		free(list);
	}
}

int list_empty(list_t * list) {
	assert(list);
	return list->head_guard->next == list->head_guard;
}

void list_remove_back(list_t *list) {
	list_node_t *removed;
	assert(list);
	if(list) {
		if(list->head_guard->next != list->head_guard) {
			removed = list->head_guard->prev;
			removed->next->prev = removed->prev;
			removed->prev->next = removed->next;
			free(removed);
		}
	}
}

void list_remove_front(list_t *list) {
	list_node_t *removed;
	assert(list);
	if(list) {
		if(list->head_guard->next != list->head_guard) {
			removed = list->head_guard->next;
			removed->next->prev = removed->prev;
			removed->prev->next = removed->next;
			free(removed);
		}
	}
}

void list_remove(list_node_t * node) {
	list_t * list = 0;
	assert(node);
	assert(node->list);
	assert(node->list->head_guard != node);
	if(node) {
		list = node->list;
		if(node != list->head_guard) {
			node->next->prev = node->prev;
			node->prev->next = node->next;
			free(node);
		}
	}
}

int list_add_back(list_t * list, void *data, size_t len) {
	assert(list);
	if(!list) {
		return -1;
	}
	return list_insert_before(list->head_guard, data, len);
}


int list_add_front(list_t * list, void *data, size_t len) {
	assert(list);
	if(!list) {
		return -1;
	}
	return list_insert_after(list->head_guard, data, len);
}

int list_insert_after(list_node_t * node, void *data, size_t len) {
	list_node_t * ins_node = 0;
	assert(node);
	assert(node->list);
	assert(data || len == 0);
	if(!node) {
		return -1;
	}
	if(!data && len > 0) {
		return -1;
	}

	ins_node = _new_node(node->list, data, len);
	if(!ins_node) {
		return -1;
	}
	ins_node->next = node->next;
	ins_node->prev = node;
	node->next->prev = ins_node;
	node->next = ins_node;
	return 0;
}

int list_insert_before(list_node_t * node, void *data, size_t len) {
	list_node_t * ins_node = 0;
	assert(node);
	assert(node->list);
	assert(data || len == 0);
	if(!node) {
		return -1;
	}
	if(!data && len > 0) {
		return -1;
	}

	ins_node = _new_node(node->list, data, len);
	if(!ins_node) {
		return -1;
	}
	ins_node->prev = node->prev;
	ins_node->next = node;
	node->prev->next = ins_node;
	node->prev = ins_node;
	return 0;
}

void list_clear(list_t *list) {
	list_node_t *p, *q;
	assert(list);
	if(list) {
		for(p=list->head_guard->next; p != list->head_guard;) {
			q = p;
			p = p->next;
			free(q);
		}
		list->head_guard->next = list->head_guard;
		list->head_guard->prev = list->head_guard;
	}
}

list_node_t * list_find(list_node_t * begin, void *data, size_t len) {
	list_node_t * p = 0;
	list_t * list = 0;
	assert(begin);
	assert(begin->list);
	assert(data || len == 0);

	if(begin && begin->list && (data || len == 0) ) {
		list = begin->list;
		p = begin == list->head_guard ? begin->next : begin;
		while(p && p != list->head_guard) {
			if(len == 0 && p->len == 0) {
				return p;
			}
			else if(data && memcmp(data, p->data, len) == 0) {
				return p;
			}
			p = p->next;
		}
	}
	return 0;
}

list_node_t * list_find_r(list_node_t * begin, void *data, size_t len) {
	list_node_t * p = 0;
	list_t * list = 0;
	assert(begin);
	assert(begin->list);
	assert(data || len == 0);

	if(begin && begin->list && (data || len == 0) ) {
		list = begin->list;
		p = begin;
		while(p != list->head_guard) {
			if(len == 0 && p->len == 0) {
				return p;
			}
			else if(data && memcmp(data, p->data, len) == 0) {
				return p;
			}
			p = p->prev;
		}
	}
	return 0;
}

