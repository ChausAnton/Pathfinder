#include "../inc/pathfinder.h"

t_node* newNode(int p) { 
    t_node* temp = (t_node*)malloc(sizeof(t_node)); 
    temp->priority = p; 
    temp->next = NULL; 
  
    return temp; 
} 

void pop(t_node** head) { 
    t_node* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 

void push(t_node** head, int p) { 
    t_node* start = (*head); 
  
    t_node* temp = newNode(p); 
  

    if ((*head)->priority > p) { 
  
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        while (start->next != NULL && 
               start->next->priority < p) { 
            start = start->next; 
        } 
  
        temp->next = start->next; 
        start->next = temp; 
    } 
} 

int isEmpty(t_node** head) { 
    return (*head) == NULL; 
} 

int peek(t_node** head) { 
    return (*head)->priority; 
} 

