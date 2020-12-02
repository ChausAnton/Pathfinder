#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

typedef struct s_node { 
  
    int priority; 
  
    struct s_node* next; 
  
} t_node; 

///////queue
int peek(t_node**);

int isEmpty(t_node**);

void push(t_node**, int);

void pop(t_node**);

t_node* newNode(int);
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
