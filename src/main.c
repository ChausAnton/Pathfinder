#include "../inc/pathfinder.h"

void mx_pars_file(char *str) {
    char **str_res = (char **) malloc((3 * mx_atoi(&str[0])+ 1) * sizeof(char *));
    str += 2;
    int iter = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '\n') {

            char *temp = mx_strndup(str, i);
            char **arr_temp = mx_strsplit(temp, '-');

            str_res[iter] = mx_strdup(arr_temp[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[0]);
            iter++;
            str_res[iter] = mx_strdup(mx_strsplit(arr_temp[1], ',')[1]);
            iter++;

            for(int m = 0; m < mx_strlen(temp) + 1; m++)
                str++;
            i = 0;
        }
    }
    for(int j = 0; j < iter; j++) {
        printf("%s\n", str_res[j]);
    }
}

int main () {
    mx_pars_file(mx_file_to_str("test.txt"));
}
