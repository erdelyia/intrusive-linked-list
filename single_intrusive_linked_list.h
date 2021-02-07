/* Single intrusive linked list */

#include <stdbool.h>
#include "data.h"


typedef struct single_ill_t {
    struct single_ill_t* next;
} single_ill_t;


typedef struct single_ill_item_t {
    data_t data;
    single_ill_t list;
} single_ill_item_t;



bool s_ill_create(single_ill_t* ill);


bool s_ill_clean(single_ill_t* ill);


bool s_ill_push(single_ill_t* ill_list, single_ill_t* ill);


single_ill_t* s_ill_pop(single_ill_t* ill);


single_ill_t* s_ill_get_end(single_ill_t* ill);


single_ill_t* s_ill_get_next(single_ill_t* ill);


data_t* s_ill_get_data(single_ill_t* ill);
