#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    bool was_c = true;
    if (str == NULL) return -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] != '\0')
            was_c = true;
        else if (was_c == true) {
            was_c = false;
            count++;
        }        
    }
    return count;
}
