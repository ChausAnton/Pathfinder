#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {

    unsigned char *ptr = (unsigned char *)b;

    while (b && len > 0) {
        *ptr = c;
        ptr++;
        len--;
    }
    return b;
}
