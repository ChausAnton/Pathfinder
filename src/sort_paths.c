#include "../inc/pathfinder.h"

void sort_paths(t_node **paths) {
    for(int i = 0; paths[i + 1] != NULL; i++) {
        char **paths1 = first_last_name(paths[i]);
        char **paths2 = first_last_name(paths[i + 1]);
        if(mx_strcmp(paths1[1], paths2[1]) == 0 
        && mx_strcmp(paths1[0], paths2[0]) == 0) {
            t_node *node_path1 = paths[i];
            t_node *node_path2 = paths[i + 1];
            for(; node_path1->parent != NULL && node_path2->parent != NULL;) {
                if(node_path1->to_parent > node_path2->to_parent) {
                    t_node *temp = paths[i];
                    paths[i] = paths[i + 1];
                    paths[i + 1] = temp;
                    break;
                }
                else {
                    node_path1 = node_path1->parent;
                    node_path2 = node_path2->parent;
                }
            }
        }
    }
}

