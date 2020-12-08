#include "../inc/pathfinder.h"

void print_node(t_node *node) {
    mx_printstr("========================================\n");

    mx_printstr("Path: ");
    mx_printstr(first_last_name(node)[1]);
    mx_printstr(" -> ");
    mx_printstr(first_last_name(node)[0]);
    mx_printchar('\n');

    int arr_size  = 0;
    t_node *temp = node;
    for (; temp != NULL; arr_size ++){
        temp = temp->parent;
    }

    temp = node;
    char **names_arr = (char **) malloc(arr_size * sizeof(char*));
    for (int i = 0; temp != NULL; i++){
        names_arr[i] = mx_strdup(temp->name);
        temp = temp->parent;
    }

    mx_printstr("Route: ");
    for (int i = arr_size - 1; i >= 0; i--){
        mx_printstr(names_arr[i]);
        if(i - 1 >= 0)
            mx_printstr(" -> ");
    }

    if(arr_size == 2) {
        mx_printstr("\nDistance: ");
        mx_printint(node->to_parent);
    }
    else {
        mx_printstr("\nDistance: ");

        temp = node;
        int *int_arr = (int *) malloc(arr_size * sizeof(int));
        for (int i = 0; temp != NULL; i++){
            int_arr[i] = temp->to_parent;
            temp = temp->parent;
        }

        for (int i = arr_size - 2; i >= 0; i--){
            mx_printint(int_arr[i]);
            if(i - 1 >= 0) 
                mx_printstr(" + ");
        }
        mx_printstr(" = ");
        int sum = 0;
        for(int i = 0; i < arr_size - 1; i++) {
            sum += int_arr[i];
        }
        mx_printint(sum);
    }
    mx_printstr("\n========================================\n");
}
