/*******************************************************************************
* Copyright (C), 2017-2022, 359152155@qq.com.
*
* FileName    : vec.h
* Author      : xianchen.p
* Date        : 2017-08-15 
* Description : 
* Github      : https://github.com/Jason886/container
*------------------------------------------------------------------------------*
* Record      :
*******************************************************************************/
#ifndef _VEC_H_
#define _VEC_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void * _data;
	size_t _size;
	size_t _capacity;
	size_t _element_size;
} vec_t;


vec_t * vec_new(size_t element_size);
void vec_del(vec_t * vec);
size_t vec_size(vec_t *vec);
size_t vec_capacity(vec_t *vec);
size_t vec_element_size(vec_t *vec);
int vec_empty(vec_t *vec);
int vec_insert(vec_t *vec, const void *data, size_t idx);
int vec_append(vec_t *vec, const void *data);
void vec_remove(vec_t *vec, size_t idx);
void vec_remove_back(vec_t *vec);
int vec_value_at(vec_t *vec, size_t idx, void *ele_o);
void * vec_ref_at(vec_t *vec, size_t idx);
int vec_back(vec_t *vec, void *ele_o);
void * vec_ref_back(vec_t *vec);
void vec_clear(vec_t *vec);
void vec_shrink(vec_t *vec);

#define _vec_element_addr(vec, i) \
((void *)((i < vec->_size && i >= 0) ? (((char *)vec->_data) + i * vec->_element_size) : 0 ))

#define vec_foreach(vec, i, ele) \
for(i = 0; (ele = _vec_element_addr(vec, i)) != 0; ++i)

#define vec_foreach_r(vec, i, ele) \
for(i = vec->_size-1; (ele = _vec_element_addr(vec, i)) != 0; --i )

#define vec_push_back(v, e) vec_append(v, e)
#define vec_pop_back(v) vec_remove_back(v)


#ifdef __cplusplus
}
#endif


#endif
