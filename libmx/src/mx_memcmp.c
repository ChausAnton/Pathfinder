#include "libmx.h"
int mx_memcmp(const void *s1, const void *s2, size_t n) {
    if(n == 0) return 0;
    const unsigned char *s1_temp = (unsigned char *)s1;
    const unsigned char *s2_temp = (unsigned char *)s2;

    size_t i = 0;
    while(s1_temp[i] == s2_temp[i] && i != n) {
        if (s2_temp[i] == '\0')
            return 0;
        i++;
    }
    return (s1_temp[i] - s2_temp[i]);
}
