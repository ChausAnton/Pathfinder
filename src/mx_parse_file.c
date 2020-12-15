#include "../inc/pathfinder.h"

char **mx_parse_file(char *str) {
    int size = mx_atoi(str);
    if(str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    }

    int temp_lines = 1;
    for(int i = 0; str[i + 1] != '\0'; i++) {
        if(mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            if(str[i] == '\n')
                temp_lines++;
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(temp_lines));
            mx_printerr(" is not valid\n");
            exit(0);
        }
        else if(str[i] == '\n')  {
            temp_lines++;
        }
    }

    for(int i = 0; *str != '\n'; i++) {
        if(!mx_isdigit(*str)) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        str++;
    }

    
    int lin_num = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '\n')
            lin_num++;
    }

    str = mx_strtrim(str);

    char **str_res = (char **) malloc((3 * lin_num + 1) * sizeof(char *));
    for(int i = 0; i < size; i++) {
        str_res[i] = NULL;
    }

    char **arr_str = mx_strsplit(str, '\n');

    int iter = 0;
    int line_num = 1;
    for(int i = 0; arr_str[i] != NULL; i++) {

            line_num++;
            char *temp = mx_strtrim(arr_str[i]);
            mx_check_str(temp, line_num);
            
            temp = mx_strdup(arr_str[i]);
            temp = mx_strtrim(temp);
            char **arr_temp = mx_strsplit(temp, '-');

            str_res[iter] = mx_strdup(arr_temp[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[1]);
            iter++;

    }
    mx_check_dup(str_res, iter);
    char **islands = list_of_islands(str_res);
    int islands_size = 0;
    for(int i = 0; islands[i] != NULL; i++) {
        islands_size++;
    }
    if (size != islands_size) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    for(int i = 0; islands[i] != NULL; i++) {
        free(islands[i]);
    }
    free(islands);

    return str_res;
}
