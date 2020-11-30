#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *dst_temp = (unsigned char *)dst;
    unsigned char *src_temp = (unsigned char *)src;
    for (size_t i = 0; i < n; i++)
        dst_temp[i] = src_temp[i];
    return dst;
}
