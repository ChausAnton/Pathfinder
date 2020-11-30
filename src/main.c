#include "../inc/pathfinder.h"

void mx_pars_str(char *str) {
    printf("%s", str);
}

int main () {
    mx_pars_str(mx_file_to_str("test.txt"));
}
