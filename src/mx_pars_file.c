#include "../inc/pathfinder.h"

char **mx_pars_file(char *str) {
    int size = mx_atoi(str);
    if(str[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        exit(0);
    } 
    for(int i = 0; *str != '\n'; i++) {
        if(!mx_isdigit(*str)) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        str++;
    }

    str = mx_strtrim(str);
    char **str_res = (char **) malloc((3 * size + 1) * sizeof(char *));
    for(int i = 0; i < size; i++) {
        str_res[i] = NULL;
    }

    int iter = 0;
    int line_num = 1;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '\n') {
            if(str[i + 1] == '\0')
                i++;

            line_num++;
            char *temp = mx_strndup(str, i);
            temp = mx_strtrim(temp);
            mx_check_str(temp, line_num);

            temp = mx_strndup(str, i);
            temp = mx_strtrim(temp);
            char **arr_temp = mx_strsplit(temp, '-');

            str_res[iter] = mx_strdup(arr_temp[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[1]);
            iter++;

            if(str[i + 1] == '\0')
                break;
            
            for(int m = 0; m <= i; m++)
                str++;
            i = 0;
        }
    }
    mx_check_dup(str_res, iter);
    if (size != (iter / 3) + 2) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
    return str_res;
}
