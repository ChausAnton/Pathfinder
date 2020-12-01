#include "../inc/pathfinder.h"

int mx_get_last_char_index(const char *str, char c) {
    if (str == NULL) return -2;
    for (int i = mx_strlen(str) - 1; i >= 0; i--) {
        if (str[i] == c) return i;
    }
    return -1;
}
