#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    while(mx_isspace(*str)) str++;

    int i = mx_strlen(str);
    while(mx_isspace(str[i - 1])) {
        i--;
    }

    return mx_strndup(str, i);
}
