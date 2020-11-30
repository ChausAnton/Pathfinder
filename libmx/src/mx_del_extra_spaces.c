#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if(str == NULL) return NULL;
    char *res = mx_strtrim(str);
    if(res == NULL) return NULL;
    char *temp = mx_strnew(mx_strlen(res));
    if(temp == NULL) return NULL;
    int j=0;

    for (int i = 0; i < mx_strlen(res); i++) {
        if(mx_isspace(res[i])) {
            if(mx_isspace(res[i + 1])) {
                continue;
            }
            else {
                temp[j] = ' ';
                j++; 
            }
        }
        else {
            temp[j] = res[i];
            j++; 
        }
    }

    mx_strdel(&res);
    res = mx_strnew(mx_strlen(temp));
    if(res == NULL) return NULL;
    res = mx_strdup(temp);
    mx_strdel(&temp);
    return res;
}
