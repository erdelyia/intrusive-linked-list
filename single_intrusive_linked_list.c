/* Single intrusive linked list */

#include "single_intrusive_linked_list.h"
#include "macros.h"


bool s_ill_create(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);

    if(!error) {
        ill->next = NULL;
    }

    return error;
}

bool s_ill_clean(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);

    return error;
}

bool s_ill_push(single_ill_t* ill_list, single_ill_t* ill)
{
    bool error = NULLCHECK(ill_list) || NULLCHECK(ill);
    single_ill_t* end = s_ill_get_end(ill_list);

    if(NULL == end) {
        error = true;
    } else {
        end->next = ill;
    }

    return error;
}

single_ill_t* s_ill_pop(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    single_ill_t* pop = NULL;
    single_ill_t* new_last = ill;

    if(!error) {
        if(new_last->next == NULL) {
            pop = new_last;
        } else {
            while(new_last->next->next != NULL) {
                new_last = s_ill_get_next(new_last);
            }

            pop = new_last->next;
            new_last->next = NULL;
        }
    }

    return pop;
}

single_ill_t* s_ill_get_end(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    single_ill_t* end = ill;

    if(!error) {
        while(end->next != NULL) {
            end = s_ill_get_next(end);
        }
    }

    return end;
}

single_ill_t* s_ill_get_next(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    single_ill_t* next = NULL;

    if(!error) {
        next = ill->next;
    }

    return next;
}

data_t* s_ill_get_data(single_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    data_t* data = NULL;
    single_ill_item_t* item = NULL;

    if(!error) {
        item = container_of(ill, single_ill_item_t, list);
        data = &item->data;
    }

    return data;
}
