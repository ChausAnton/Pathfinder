#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *s_temp = (unsigned char *)s + mx_strlen(s);

    for(size_t i = 0; i < n; i++) {
        if(*s_temp == (unsigned char)c) {
            return s_temp;
        }
        s_temp--;
    }
    return NULL;
}
