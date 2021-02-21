/* Double intrusive linked list */

#include <include/double_intrusive_linked_list.h>
#include <include/macros.h>


bool d_ill_create(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);

    if(!error) {
        ill->next = NULL;
        ill->prev = NULL;
    }

    return error;
}

bool d_ill_clean(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);

    return error;
}

bool d_ill_push(double_ill_t* ill_list, double_ill_t* ill)
{
    bool error = NULLCHECK(ill_list) || NULLCHECK(ill);
    double_ill_t* end = d_ill_get_end(ill_list);

    if(NULL == end) {
        error = true;
    } else {
        end->next = ill;
        ill->prev = end;
    }

    return error;
}

double_ill_t* d_ill_pop(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    double_ill_t* end = d_ill_get_end(ill);

    if(NULL == end) {
        error = true;
    } else {
        end->prev->next = NULL;
        end->prev = NULL;
    }

    return end;
}

double_ill_t* d_ill_get_front(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    double_ill_t* front = ill;

    if(!error) {
        while(front->prev != NULL) {
            front = d_ill_get_prev(front);
       }
    }

    return front;
}


double_ill_t* d_ill_get_end(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    double_ill_t* end = ill;

    if(!error) {
        while(end->next != NULL) {
            end = d_ill_get_next(end);
        }
    }

    return end;
}

double_ill_t*d_ill_get_next(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    double_ill_t* next = NULL;

    if(!error) {
        next = ill->next;
    }

    return next;
}

double_ill_t*d_ill_get_prev(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    double_ill_t* prev = NULL;

    if(!error) {
        prev = ill->prev;
    }

    return prev;
}

data_t* d_ill_get_data(double_ill_t* ill)
{
    bool error = NULLCHECK(ill);
    data_t* data = NULL;
    double_ill_item_t* item = NULL;

    if(!error) {
        item = container_of(ill, double_ill_item_t, list);
        data = &item->data;
    }

    return data;
}
