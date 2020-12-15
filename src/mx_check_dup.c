#include "../inc/pathfinder.h"

void mx_check_dup(char **arr_str, int size) {
    for(int i = 0; i < size; i += 3) {
        if(mx_strcmp(arr_str[i], arr_str[i + 1]) == 0) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa((i / 3) + 2));
            mx_printerr(" is not valid\n");
            exit(0);
        }
    }

    for(int i = 0; i < size; i += 3) {
        for (int j = i + 3; j < size; j += 3) {
            if((mx_strcmp(arr_str[i], arr_str[j]) == 0 && mx_strcmp(arr_str[i + 1], arr_str[j + 1]) == 0)
            || (mx_strcmp(arr_str[i + 1], arr_str[j]) == 0 && mx_strcmp(arr_str[i], arr_str[j + 1]) == 0)) {
                mx_printerr("error: duplicate bridges\n");
                exit(0);
            }
        }
    }
}
