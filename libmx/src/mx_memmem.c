#include "libmx.h"
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len < little_len || big_len <= 0 || little_len <= 0) return NULL;
    unsigned char *big_temp = (unsigned char *)big;
    unsigned char *little_temp = (unsigned char *)little;

    for(size_t i = 0; i < big_len; i++) {
        if(mx_memcmp(big_temp, little_temp, little_len - 1) == 0) return big_temp;
        big_temp++;
    }
    return NULL;

}
