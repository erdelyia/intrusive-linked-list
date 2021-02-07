#include <stdio.h>
#include "single_intrusive_linked_list.h"

#define ERROR 1

/* usage L_CHECK(expression, "tested_funcion") */

#define L_CHECK(expression, tested_function) if(!expression) {\
                                printf("'%s' failed\n", tested_function);\
                                return ERROR;\
                            }

int main()
{
    bool error = false;
    uint8_t i = 0;

    single_ill_item_t item0 = {.data.value = 0, .list.next = NULL};
    single_ill_item_t item1 = {.data.value = 1, .list.next = NULL};
    single_ill_item_t item2 = {.data.value = 2, .list.next = NULL};
    single_ill_item_t item3 = {.data.value = 3, .list.next = NULL};

    single_ill_t* ill = NULL;
    data_t* data = NULL;

    printf("Single intrusive linked list demo\n");

    /* CHECK CREATE */
    error = s_ill_create(&item0.list);
    L_CHECK(error == false, "s_ill_create()")

    /* CHECK PUSH */
    error = error || s_ill_push(&item0.list, &item1.list);
    error = error || s_ill_push(&item0.list, &item2.list);
    error = error || s_ill_push(&item0.list, &item3.list);
    L_CHECK(error == false, "s_ill_push()")

    /* CHECK GET_DATA, and GET_NEXT */
    ill = &item0.list;
    for(i = 0; ill != NULL; i++) {
        data = s_ill_get_data(ill);
	L_CHECK(data->value == i, "s_ill_get_data()")
        printf("Item%d's value = %ld\n", i, data->value);
        ill = s_ill_get_next(ill);
    }

    /* CHECK GET_END */
    ill = s_ill_get_end(&item0.list);
    data = s_ill_get_data(ill);
    printf("List's end's value = %ld\n", data->value);
    L_CHECK(data->value == 3, "s_ill_end()")

    /* CHECK POP */
    ill = s_ill_pop(&item0.list);
    data = s_ill_get_data(ill);
    printf("Popped: %ld\n", data->value);
    L_CHECK(data->value == 3, "s_ill_pop()")

    ill = &item0.list;
    for(i = 0; ill != NULL; i++) {
        data = s_ill_get_data(ill);
        L_CHECK(data->value == i, "s_ill_get_data()")
        printf("Item%d's value = %ld\n", i, data->value);
        ill = s_ill_get_next(ill);
    }

    /* CHECK CLEAN */
    error = error || s_ill_clean(&item0.list);
    L_CHECK(error == false, "s_ill_clean()")


    if(!error) {
        printf("All tests have succeeded\n");
    } else {
        printf("Tests have failed\n");
    }

    return error;
}

