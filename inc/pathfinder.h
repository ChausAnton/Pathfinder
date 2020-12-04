#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

typedef struct s_node { ////graph 
  
    int to_parent; 
    int all_way;
    char *name;
    struct s_node* parent; 
  
} t_node; 

typedef struct s_queue { 
  
    int priority; 
    t_node *node;
    struct s_queue* next; 
  
} t_queue; 

///////queue
int peek(t_queue**);

int isEmpty(t_queue**);

void push(t_queue**, t_node*);

void pop(t_queue**);

t_queue* newNode(t_node*);
///////queue

int mx_atoi(const char *);

void mx_printerr(const char *);

char **mx_pars_file(char *);

void check_line(char *, int);

void mx_check_str(char *, int);

int mx_get_last_char_index(const char *, char);

void mx_check_dup(char **, int);

char **list_of_islands(char **);

int **adjacency_matrix(char **, char **, int);

#endif
