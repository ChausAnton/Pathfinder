#include "../inc/pathfinder.h"

int mx_get_island_index(char **islands, char *island) {
    for(int i = 0; islands[i] != NULL; i++) {
        if(mx_strcmp(islands[i], island) == 0) {
            return i;
        }
    }
    return -1;
}

int **adjacency_matrix(char **islands, char **arr, int size) {
    int **res = (int **) malloc((size + 1) * sizeof(int *));
    for(int i = 0; i < size; i++) {
        res[i] = (int*)malloc(size * sizeof(int));
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            res[i][j] = -1;
        }
    }
    int arr_size = 0;
    for(;arr[arr_size] != NULL; arr_size++);

    for(int i = 0; i < arr_size; i += 3) {
        int index1 = mx_get_island_index(islands, arr[i]);
        int index2 = mx_get_island_index(islands, arr[i + 1]);
        res[index1][index2] = mx_atoi(arr[i + 2]);
        res[index2][index1] = mx_atoi(arr[i + 2]);
    }

    return res;
}

