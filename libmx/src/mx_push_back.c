#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new = mx_create_node(data);
    t_list *current = *list;
    if (list == NULL || *list == NULL) {
        *list = new;
        return;
    }
    while (current->next != NULL){
        current = current->next;
    }
    current->next = new;    
} 
