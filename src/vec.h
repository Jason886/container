#ifndef _VEC_H_
#define _VEC_H_

#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

typedef int (*vec_compare_f)(const void *e1, const void *e2);
typedef void (*vec_map_f)(const void *e1, const void *e2);
typedef void (*vec_free_f)(const void *e);
typedef void (*vec_copy_f)(void *dest, const void *src);

typedef struct {
	void * _data;
	size_t _size;		/* element count */
	size_t _cap;		/* capacity */
	size_t _elem_size;	/* element size */
	vec_free_f _free_f;
	vec_copy_f _copy_f;
	vec_compare_f _compare_f;
} vec;





#ifdef __cplusplus
}
#endif


#endif
