#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if(str == NULL || sub == NULL || replace == NULL || mx_strlen(str) <= mx_strlen(sub)) return NULL;
    char *temp = mx_strdup(str);
    
    int index = mx_get_substr_index(str, sub);
    if(index < 0) return temp;

    char *temp2 = mx_strndup(temp, index);
    temp2 = mx_strjoin(temp2, replace);

    for (int i = 0; i <= (index + mx_strlen(sub) - 1); i++) {
        temp++;
    }

    char *temp_str = mx_strjoin(temp2, temp);

    mx_strdel(&temp2);

    for (int i = 0; i <= (index + mx_strlen(sub) - 1); i++) {
        temp--;
    }
    mx_strdel(&temp);
    if(mx_get_substr_index(temp_str, sub) < 0)
        return temp_str;
    return mx_replace_substr(temp_str, sub, replace);
}
