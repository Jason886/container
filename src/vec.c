/*******************************************************************************
* Copyright (C), 2017-2022, 359152155@qq.com.
*
* FileName    : vec.c
* Author      : xianchen.p
* Date        : 2017-08-15 
* Description : 
* Github      : https://github.com/Jason886/container
*------------------------------------------------------------------------------*
* Record      :
*******************************************************************************/
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include "vec.h"

#define _ORI_CAPACITY 4 

static int _expand_capacity(vec_t *vec) {
	void *data = 0;
	size_t capacity = vec->_capacity << 1;
	
	if(vec->_size == vec->_capacity) {
		if(capacity < vec->_capacity) {
			return -1;
		}
		data = (void *) realloc(vec->_data, vec->_element_size * capacity);
		if(!data) {
			return -1;
		}
		vec->_data = data;
		vec->_capacity = capacity;
	}
	return 0;
}

vec_t * vec_new(size_t element_size) {
	vec_t * vec = 0;
	void * data = 0;
	data = malloc(element_size * _ORI_CAPACITY);
	if(!data) {
		return vec;
	}
	vec = malloc(sizeof(*vec));
	if(!vec) {
		free(data);
		return vec;
	}
	vec->_size = 0;
	vec->_capacity = _ORI_CAPACITY;
	vec->_element_size = element_size;
	vec->_data = data;
	return vec;
}

void vec_del(vec_t * vec) {
	assert(vec);
	if(vec->_data) { 
		free(vec->_data);
	}
	memset(vec, 0x00, sizeof(*vec));
	free(vec);
}

size_t vec_size(vec_t * vec) {
	assert(vec);
	return vec->_size;
}

size_t vec_capacity(vec_t * vec) {
	assert(vec);
	return vec->_capacity;
}

size_t vec_element_size(vec_t *vec) {
	assert(vec);
	return vec->_element_size;
}

int vec_empty(vec_t * vec) {
	assert(vec);
	return vec->_size == 0;
}

int vec_insert(vec_t *vec, const void *elem, size_t idx) {
	size_t i, offset, offset_prev;
	assert(vec);
	assert(idx <= vec->_size);
	if(idx <= vec->_size) {
		if(0 != _expand_capacity(vec)) {
			return -1;
		}
		if(vec->_capacity > vec->_size) {
			vec->_size++;
			i = vec->_size-1;
			while(i>idx) {
				offset = vec->_element_size *i;
                offset_prev = offset - vec->_element_size;
				memcpy(((char *)vec->_data)+offset, ((char *)vec->_data)+offset_prev, vec->_element_size);
				i--;
			}
			offset = vec->_element_size * idx;
			memcpy(((char *)vec->_data)+offset, (char *)elem, vec->_element_size);
			return 0;
		}
	}
	return -1;
}

int vec_append(vec_t *vec, const void *elem) {
	size_t offset;
	assert(vec);
	assert(elem);
	_expand_capacity(vec);
	if(vec->_capacity > vec->_size) {
		offset = vec->_element_size * vec->_size;
		memcpy(((char *)vec->_data) + offset, (char *)elem, vec->_element_size);
		vec->_size++;
		return 0;
	}
	return -1;
}

void vec_remove(vec_t *vec, size_t idx) {
	int i, offset, offset_next;
	assert(vec);
	assert(idx < vec->_size);
	if(idx < vec->_size) {
		i=idx;
		for(; i<(vec->_size-1); ++i) {
			offset = vec->_element_size * i;
			offset_next = offset + vec->_element_size;
			memcpy(((char *)vec->_data)+offset, ((char *)vec->_data)+offset_next, vec->_element_size);
		}
		vec->_size--;
	}
}

void vec_remove_back(vec_t *vec) {
	assert(vec);
	if(vec->_size > 0) {
		vec->_size--;
	}
}

int vec_value_at(vec_t *vec, size_t idx, void *ele_o) {
	void *ele = 0;
	assert(ele_o);
	if(ele_o) {
		ele = vec_ref_at(vec, idx);
		if(ele) {
			memcpy(ele_o, ele, vec->_element_size);
			return 0;
		}
	}
	return -1;
}

void * vec_ref_at(vec_t *vec, size_t idx) {
	size_t offset;
	assert(vec);
	assert(idx < vec->_size);
	if(idx < vec->_size) {
		offset = vec->_element_size *idx;
		return ((char *)vec->_data) + offset;
	}
	return NULL;
}

int vec_back(vec_t *vec, void *ele_o) {
	void *ele = 0;
	assert(ele_o);
	if(ele_o) {
		ele = vec_ref_back(vec);
		if(ele) {
			memcpy(ele_o, ele, vec->_element_size);
			return 0;
		}
	}
	return -1;
}

void * vec_ref_back(vec_t *vec) {
	size_t offset;
	assert(vec);
	assert(vec->_size > 0);
	if(vec->_size > 0) {
		offset = vec->_element_size * (vec->_size -1);
		return ((char *)vec->_data) + offset;
	}
	return NULL;
}

void vec_clear(vec_t *vec) {
	assert(vec);
	vec->_size = 0;
}

void vec_shrink(vec_t * vec) {
	void *data = 0;
	assert(vec);
	
	if(vec->_size <= _ORI_CAPACITY) {
		if(vec->_capacity > _ORI_CAPACITY) {
			data = realloc(vec->_data, vec->_element_size *_ORI_CAPACITY);
			if(data) {
				vec->_data = data;
				vec->_capacity = _ORI_CAPACITY;
			}
		}
		return;
	}

	if(vec->_size < vec->_capacity) {
		data = realloc(vec->_data, vec->_element_size * vec->_size);
		if(data) {
			vec->_data = data;
			vec->_capacity = vec->_size;
		}
	}
}
