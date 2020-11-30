#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (head == NULL || *head == NULL) {
        return;
    }
    t_list *node = *head;
    node = node->next;
    free(*head);
    (*head) = NULL;
    *head = node;
}
