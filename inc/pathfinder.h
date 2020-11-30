#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

int mx_atoi(const char *);

void mx_printerr(const char *);

void mx_pars_file(char *);

void check_line(char *, int);

typedef struct s_graph {
    size_t size;
    bool **visited;
    char **vertices;
    size_t **dependences;
} t_graph;

#endif
