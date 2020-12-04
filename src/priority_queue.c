#include "../inc/pathfinder.h"

t_queue* newNode(t_node *node) { 
    t_queue* temp = (t_queue*)malloc(sizeof(t_queue)); 
    temp->priority = node->all_way;
    temp->next = NULL;
    temp->node = node;
  
    return temp; 
} 

void pop(t_queue** head) { 
    t_queue* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 

void push(t_queue** head, t_node *node) { 
    t_queue* start = (*head); 
  
    t_queue* temp = newNode(node); 
  

    if ((*head)->priority > node->all_way) { 
  
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        while (start->next != NULL && 
               start->next->priority < node->all_way) { 
            start = start->next; 
        } 
  
        temp->next = start->next; 
        start->next = temp; 
    } 
} 

int isEmpty(t_queue** head) { 
    return (*head) == NULL; 
} 

int peek(t_queue** head) { 
    return (*head)->priority; 
} 

