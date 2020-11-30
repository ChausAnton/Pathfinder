#pragma once
#ifndef HEADER_path
#define HEADER_path

#include "../libmx/inc/libmx.h"

typedef struct s_graph {
    size_t sum;
    size_t size;
    bool **visited;
    char **vertices;
    size_t **dependences;
} t_graph;

#endif
