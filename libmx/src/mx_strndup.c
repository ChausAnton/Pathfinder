#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t lenght = mx_strlen(s1);
    if(n < lenght) lenght = n;
    char *DupStr = mx_strnew(lenght);
    if(DupStr == NULL) {
        return NULL;
    }
    return mx_strncpy(DupStr, s1, lenght);
}
