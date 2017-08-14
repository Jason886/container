#include <stdio.h>
#include "con.h"

int test_vec1() {
	vec_t * vec_int = 0;
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4, num5 = 5, num6 = 6;
	int i, num, *pnum, ret;

	vec_int = vec_new(sizeof(int));
	
	printf("after_new:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_append(vec_int, &num1);
	vec_insert(vec_int, &num1, 0);
	vec_insert(vec_int, &num2, 0);
	
	printf("\nshow result 1:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_int, &num3, 1);
	vec_insert(vec_int, &num4, 1);

	printf("\nshow result 2:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_int, &num5, 5);

	printf("\nshow result 3:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_int, &num6, 6);
	vec_shrink(vec_int);

	printf("\nshow result 4:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_append(vec_int, &num1);
	vec_append(vec_int, &num2);

	printf("\nshow result 5:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	/*vec_insert(vec_int, &num3, 10);*/

	vec_remove_back(vec_int);

	printf("\nshow result 6:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	/*vec_remove(vec_int, 8); */
	vec_remove(vec_int, 7);

	printf("\nshow result 7:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_remove(vec_int, 0);

	printf("\nshow result 8:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	ret = vec_value_at(vec_int, 0, &num);
	printf("\nshow result 9:\n");
	printf("at 0: ret = %d, num = %d\n", ret, num);
	printf("\n");

	ret = vec_value_at(vec_int, 5, &num);
	printf("\nshow result 10:\n");
	printf("at 5: ret = %d, num = %d\n", ret, num);
	printf("\n");

	/*ret = vec_value_at(vec_int, 6, &num); */
	/* vec_value_at(vec_int, -1, &num); */

	pnum = vec_ref_at(vec_int, 0);
	printf("\nshow result 11:\n");
	printf("at 0: pnum = %p, *pnum = %d\n", (void *)pnum, *pnum);
	printf("\n");

	pnum = vec_ref_at(vec_int, 3);
	printf("\nshow result 12:\n");
	printf("at 3: pnum = %p, *pnum = %d\n", (void *)pnum, *pnum);
	printf("\n");

	/* pnum = vec_ref_at(vec_int, 6); */ 
	/* pnum = vec_ref_at(vec_int, -1); */

	ret = vec_back(vec_int, &num);
	printf("\nshow result 13:\n");
	printf("back: num = %d\n", num);
	printf("\n");

	pnum = vec_ref_back(vec_int);
	printf("\nshow result 14:\n");
	printf("back: num = %d\n", *pnum);
	printf("\n");

	vec_remove(vec_int, 4);

	printf("\nshow result 15:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_remove_back(vec_int);
	/*vec_remove(vec_int, 4); */
	vec_remove_back(vec_int);

	printf("\nshow result 16:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_shrink(vec_int);

	printf("\nshow result 17:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_clear(vec_int);

	printf("\nshow result 19:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");


	vec_del(vec_int);

	printf("\nshow result 19:\n");
	printf("size = %lu\n", vec_size(vec_int));
	printf("capacity = %lu\n", vec_capacity(vec_int));
	printf("element_size = %lu\n", vec_element_size(vec_int));
	printf("data = %p\n", vec_int->_data);
	printf("empty = %d\n", vec_empty(vec_int));

	vec_foreach(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_int, i, pnum) {
		printf("[%d]=%d, ", i, *pnum);
	}
	printf("\n");
	return 0;
}

int test_vec2() {
	vec_t * vec_str = 0;
	char *num1 = "1", *num2 = "2", *num3 = "3", *num4 = "4", *num5 = "5", *num6 = "6";
	int i, ret;
	char *num, **pnum;

	vec_str = vec_new(sizeof(char*));
	
	printf("after_new:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_append(vec_str, &num1);
	vec_insert(vec_str, &num1, 0);
	vec_insert(vec_str, &num2, 0);
	
	printf("\nshow result 1:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_str, &num3, 1);
	vec_insert(vec_str, &num4, 1);

	printf("\nshow result 2:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_str, &num5, 5);

	printf("\nshow result 3:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_insert(vec_str, &num6, 6);
	vec_shrink(vec_str);

	printf("\nshow result 4:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_append(vec_str, &num1);
	vec_append(vec_str, &num2);

	printf("\nshow result 5:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	/*vec_insert(vec_str, &num3, 10); */

	vec_remove_back(vec_str);

	printf("\nshow result 6:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	/*vec_remove(vec_str, 8); */
	vec_remove(vec_str, 7);

	printf("\nshow result 7:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_remove(vec_str, 0);

	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	ret = vec_value_at(vec_str, 0, &num);
	printf("\nshow result 9:\n");
	printf("at 0: ret = %d, num = %s\n", ret, num);
	printf("\n");

	ret = vec_value_at(vec_str, 5, &num);
	printf("\nshow result 10:\n");
	printf("at 5: ret = %d, num = %s\n", ret, num);
	printf("\n");

	/* ret = vec_value_at(vec_str, 6, &num); */
	/* vec_value_at(vec_str, -1, &num); */

	pnum = vec_ref_at(vec_str, 0);
	printf("\nshow result 11:\n");
	printf("at 0: pnum = %p, *pnum = %s\n", (void *)pnum, *pnum);
	printf("\n");

	pnum = vec_ref_at(vec_str, 3);
	printf("\nshow result 12:\n");
	printf("at 3: pnum = %p, *pnum = %s\n", (void *)pnum, *pnum);
	printf("\n");

	/* pnum = vec_ref_at(vec_str, 6); */ 
	/* pnum = vec_ref_at(vec_str, -1); */

	ret = vec_back(vec_str, &num);
	printf("\nshow result 13:\n");
	printf("back: num = %s\n", num);
	printf("\n");

	pnum = vec_ref_back(vec_str);
	printf("\nshow result 14:\n");
	printf("back: num = %s\n", *pnum);
	printf("\n");

	vec_remove(vec_str, 4);

	printf("\nshow result 15:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_remove_back(vec_str);
	/* vec_remove(vec_str, 4); */
	vec_remove_back(vec_str);

	printf("\nshow result 16:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_shrink(vec_str);

	printf("\nshow result 17:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_clear(vec_str);

	printf("\nshow result 19:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");


	vec_del(vec_str);

	printf("\nshow result 19:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pnum) {
		printf("[%d]=%s, ", i, *pnum);
	}
	printf("\n");
	return 0;
}



typedef struct {
	char str[100];
} block_t;

int test_vec3() {
	vec_t * vec_str = 0;

	block_t block1 = {"1"}, block2 = {"2"}, block3 = {"3"};
	int i;
	block_t *pbl;

	vec_str = vec_new(sizeof(block_t));

	printf("after_new:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pbl) {
		printf("[%d]=%s, ", i, (*pbl).str);
	}
	printf("\n");

	vec_foreach_r(vec_str, i, pbl) {
		printf("[%d]=%s, ", i, (*pbl).str);
	}
	printf("\n");

	vec_append(vec_str, &block1);
    vec_insert(vec_str, &block2, 0);
	vec_insert(vec_str, &block3, 0);
	
	printf("\nshow result 1:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));

	vec_foreach(vec_str, i, pbl) {
		printf("[%d]=%s, ", i, (*pbl).str);
    }
	printf("\n");

	vec_foreach_r(vec_str, i, pbl) {
        printf("[%d]=%s, ", i, (*pbl).str);
    }
	printf("\n");
	
    vec_del(vec_str);
	
    printf("\nshow result 19:\n");
	printf("size = %lu\n", vec_size(vec_str));
	printf("capacity = %lu\n", vec_capacity(vec_str));
	printf("element_size = %lu\n", vec_element_size(vec_str));
	printf("data = %p\n", vec_str->_data);
	printf("empty = %d\n", vec_empty(vec_str));
	return 0;
}

int test_vec() {
	/*
    test_vec1();
	*/
	test_vec2();
    /*
	test_vec3();
    */
	return 0;
}
