#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

int mx_atoi(const char *s);

typedef struct s_graph {
    size_t size;
    bool **visited;
    char **vertices;
    size_t **dependences;
} t_graph;

#endif
