#include "libmx.h"
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *dst_temp = (unsigned char *)dst;
    unsigned char *src_temp = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        if(src_temp[i] == (unsigned char)c) {
            dst_temp[i] = src_temp[i];
            return (void *)&dst_temp[i + 1];
        }
        dst_temp[i] = src_temp[i];
    }
    return NULL;
}
