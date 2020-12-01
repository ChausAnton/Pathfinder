#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

int mx_atoi(const char *);

void mx_printerr(const char *);

char **mx_pars_file(char *);

void check_line(char *, int);

void mx_check_str(char *, int);

int mx_get_last_char_index(const char *, char);

void mx_check_dup(char **, int);

char **list_of_islands(char **);

typedef struct s_graph {
    size_t size;
    bool **visited;
    char **vertices;
    size_t **dependences;
} t_graph;

#endif
