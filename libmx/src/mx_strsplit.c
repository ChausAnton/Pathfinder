#include "libmx.h"

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) return NULL;
    int length = 0;
    int i = 0;
    char **arr = (char **) malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    while((*s) && (*s != '\0')) {
        if(*s != c) {
            length = 0;
            while (s[length] != c && s[length]) {
                length++;
            }
            arr[i] = mx_strndup(s, length);
            s += length;
            i++;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    return arr;
}
