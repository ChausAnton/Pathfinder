#include "../inc/pathfinder.h"

void sort_paths(t_node **paths, char **islands) {

    for(int i = 0; paths[i + 1] != NULL; i++) {

        char **paths1 = first_last_name(paths[i]);
        char **paths2 = first_last_name(paths[i + 1]);
        if(mx_strcmp(paths1[1], paths2[1]) == 0 
        && mx_strcmp(paths1[0], paths2[0]) == 0) {

        t_node *temp1 = paths[i];
        t_node *temp2 = paths[i + 1];
        for(;temp1->parent != NULL || temp2->parent != NULL;) {
        int index1 = 0;
        for(int j = 0; islands[j] != NULL; j++) {
            if(mx_strcmp(islands[j], temp1->name) == 0) {
                break;
            }
            index1++;
        }

        int index2 = 0;
        for(int j = 0; islands[j] != NULL; j++) {
            if(mx_strcmp(islands[j], temp2->name) == 0) {
                break;
            }
            index2++;
        }

        if(index1 > index2) {
            t_node *temp = paths[i];
            paths[i] = paths[i + 1];
            paths[i + 1] = temp;
            
        }
        if(temp1->parent != NULL)
            temp1 = temp1->parent;
        if(temp2->parent != NULL)
            temp2 = temp2->parent;
        }
        }
    }


    /*for(int i = 0; paths[i + 1] != NULL; i++) {
        char **paths1 = first_last_name(paths[i]);
        char **paths2 = first_last_name(paths[i + 1]);
        if(mx_strcmp(paths1[1], paths2[1]) == 0 
        && mx_strcmp(paths1[0], paths2[0]) == 0) {
            for(int j = 0; islands[j] != NULL; j++) {
                if(mx_strcmp(islands[j], paths1[1]) == 0) {
                    break;
                }
                else if(mx_strcmp(islands[j], paths2[1]) == 0) {
                    i--;
                    t_node *temp = paths[i];
                    paths[i] = paths[i + 1];
                    paths[i + 1] = temp;
                    break;
                }
            }
        }
    }*/
}

