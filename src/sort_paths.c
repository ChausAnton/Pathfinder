#include "../inc/pathfinder.h"

char **mx_get_names(t_node *paths) {
    int i = 0;
    t_node *path = paths;
    for(;path != NULL; i++)
        path = path->parent;

    char **names = (char **) malloc((i + 1) * sizeof(char *));

    for(int j = 0; j <= i; j++)
        names[j] = NULL;

    path = paths;
    for(int j = 0; j < i; j++) {
        names[j] = mx_strdup(path->name);
        path = path->parent;
    }

    for (int j = 0; j < i/2; j++) {
        char *temp = names[j]; 
        names[j] = names[i - 1 - j];
        names[i - 1 - j] = temp;
    }

    return names;

}

void sort_paths(t_node **paths, char **islands) {

    for(int i = 0; paths[i + 1] != NULL; i++) {

        char **paths1 = first_last_name(paths[i]);
        char **paths2 = first_last_name(paths[i + 1]);
        if(mx_strcmp(paths1[1], paths2[1]) == 0 
        && mx_strcmp(paths1[0], paths2[0]) == 0) {

            t_node *temp1 = paths[i];
            t_node *temp2 = paths[i + 1];
            char **names1 = mx_get_names(temp1);
            char **names2 = mx_get_names(temp2);

            for(int b = 0 ; names1[b] != NULL && names2[b] != NULL; b++) {
                if(mx_strcmp(names1[b], names2[b]) != 0) {

                    int index1 = 0;
                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], names1[b]) == 0) {
                            break;
                        }
                        index1++;
                    }

                    int index2 = 0;
                    for(int j = 0; islands[j] != NULL; j++) {
                        if(mx_strcmp(islands[j], names2[b]) == 0) {
                            break;
                        }
                        index2++;
                    }

                    if(index1 > index2) {
                        t_node *temp = paths[i];
                        paths[i] = paths[i + 1];
                        paths[i + 1] = temp;
                        if(i >= 0)
                            i--;
                        break;
                    }
                }
            }

        
        }
    }



    /*for(;temp1->parent != NULL || temp2->parent != NULL;) {
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
        }*/




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

