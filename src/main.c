#include "../inc/pathfinder.h"

int main () {
    char **res = mx_pars_file(mx_file_to_str("test.txt"));
    char **res_str = list_of_islands(res);
    for(int i = 0; res_str[i] != NULL; i++) {
        printf("%s\n", res_str[i]);
    }
}
