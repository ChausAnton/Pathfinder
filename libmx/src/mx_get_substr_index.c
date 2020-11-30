#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    char *temp = mx_strdup(str);
    int i = 0;
    for (; *temp; temp++, i++) {
        if (*temp == sub[0]) {
            if(mx_strncmp(temp, sub, mx_strlen(sub)) == 0 ) {
                for (int j = 0; j < i; j++, temp--);
                mx_strdel(&temp);
                return i;
            }
        }
    }
    for (int j = 0; j < i; j++, temp--);
    mx_strdel(&temp);
    return -1;
}
