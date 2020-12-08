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

t_node *new_node(int, int, char *);

void push_node(int, int, char *, t_node*);

void sum_check(int **, int);

char **first_last_name(t_node *);

void print_node(t_node *);

bool mx_compare_paths(t_node *, t_node *, t_node **);

void clean_and_output(t_node **, int );

t_node **generate_successors(int **, t_node*, char **);

t_node **pathfinder_alg(int **, char **, int, int);

void sort_paths(t_node **);

int mx_atoi(const char *);

void mx_printerr(const char *);

char **mx_parse_file(char *);

void check_line(char *, int);

void mx_check_str(char *, int);

int mx_get_last_char_index(const char *, char);

void mx_check_dup(char **, int);

char **list_of_islands(char **);

int **adjacency_matrix(char **, char **, int);

#endif
