/* Double intrusive linked list */

#include <stdbool.h>
#include "data.h"


typedef struct double_ill_t {
    struct double_ill_t* prev;
    struct double_ill_t* next;
} double_ill_t;


typedef struct double_ill_item_t {
    data_t data;
    double_ill_t list;
} double_ill_item_t;



bool d_ill_create(double_ill_t* ill);


bool d_ill_clean(double_ill_t* ill);


bool d_ill_push(double_ill_t* ill_list, double_ill_t* ill);


double_ill_t* d_ill_pop(double_ill_t* ill);


double_ill_t* d_ill_get_front(double_ill_t* ill);


double_ill_t* d_ill_get_end(double_ill_t* ill);


double_ill_t* d_ill_get_next(double_ill_t* ill);


double_ill_t* d_ill_get_prev(double_ill_t* ill);


data_t* d_ill_get_data(double_ill_t* ill);
