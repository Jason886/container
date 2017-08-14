#include <stdio.h>
#include "con.h"

int test_list1() {
    list_t *list = 0;
    list_node_t *p;
    int num1=1, num2=2, num3=3, num4=4;
    int num;
    list = list_new();
    
    printf("after new:\n");
    printf("list = %p\n", (void *)list);
    printf("head_guard = %p\n", (void *)list->head_guard);
    printf("head_guard->next = %p\n", (void *)list->head_guard->next);
    printf("head_guard->prev = %p\n", (void *)list->head_guard->prev);
    printf("head_guard->list = %p\n", (void *)list->head_guard->list);
    printf("empty = %d\n", list_empty(list));

    list_add_back(list, &num1, sizeof(int));
    list_add_back(list, &num2, sizeof(int));
    list_add_back(list, &num3, sizeof(int));
    list_add_back(list, &num4, sizeof(int));

    printf("\nresult 1:\n");
    printf("list = %p\n", (void *)list);
    printf("head_guard = %p\n", (void *)list->head_guard);
    printf("head_guard->next = %p\n", (void *)list->head_guard->next);
    printf("head_guard->prev = %p\n", (void *)list->head_guard->prev);
    printf("head_guard->list = %p\n", (void *)list->head_guard->list);
    printf("empty = %d\n", list_empty(list));

    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_remove_back(list);
    
    printf("\nresult 2:\n");
    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_remove_front(list);
    
    printf("\nresult 3:\n");
    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    p = list_find(list->head_guard, &num2, sizeof(int));
    printf("\nresult 4:\n");
    printf("p = %p, p->data = %d\n", (void *)p, *((int*)p->data));

    list_insert_before(p, &num1, sizeof(int));
    printf("\nresult 5:\n");
    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }

    p = list_find_r(list->head_guard->prev, &num2, sizeof(int));
    printf("\nresult 6:\n");
    printf("p = %p, p->data = %d\n", (void *)p, *((int*)p->data));
   
    list_insert_after(p, &num4, sizeof(int));
    printf("\nresult 7:\n");
    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    p = list_find_r(list->head_guard->prev, &num2, sizeof(int));
    list_remove(p);
    printf("\nresult 8:\n");
    list_foreach(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_foreach_r(list, p) {
        num = *((int *)p->data);
        printf("%d, ", num);
    }
    printf("\n");

    list_clear(list);
    printf("\nresult 9:\n");
    printf("list = %p\n", (void *)list);
    printf("head_guard = %p\n", (void *)list->head_guard);
    printf("head_guard->next = %p\n", (void *)list->head_guard->next);
    printf("head_guard->prev = %p\n", (void *)list->head_guard->prev);
    printf("head_guard->list = %p\n", (void *)list->head_guard->list);
    printf("empty = %d\n", list_empty(list));

    list_del(list);
    
    return 0;
}

int test_list() {
    test_list1();
    return 0;
}
