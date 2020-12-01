#include "../inc/pathfinder.h"

char **list_of_islands(char **str) {
    int size = 0;
    for(;str[size] != NULL; size++);

    int temp = 1;
    bool dup = false;

    char **res = (char **) malloc((size) * sizeof(char *));
    for(int i = 0; i < size; i++) {
        res[i] = mx_strdup(str[0]);
    }

    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(mx_strcmp(str[i], res[j]) == 0 || mx_isdigit(str[i][0])) {
                dup = true;
            }
        }
        if(dup == false) {
            res[temp] = mx_strdup(str[i]);
            temp++;
        }
        dup = false;
    }

    int length = 1;
    for(;mx_strcmp(res[0], res[length]) != 0; length++);

    char **arr_res = (char **) malloc((length + 1) * sizeof(char *));

    for(int i = 0; i < length; i++) {
        arr_res[i] = NULL;
    }

    for(int i = 0; i < length; i++) {
        arr_res[i] = mx_strdup(res[i]);
    }

    for(int i = 0; i < length; i++) {
        free(res[i]);
    }
    free(res);

    return arr_res;
}
