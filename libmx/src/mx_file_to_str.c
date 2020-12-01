#include "libmx.h"

char *mx_file_to_str(const char *filename) {
    int src = open(filename, O_RDONLY);
	if (src == -1) {
        close(src);
		mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(0);
    }

    int size = 0;
    char buf;
    short tmp = read(src, &buf, 1);
    size += tmp;
    while (tmp > 0) {
        tmp = read(src, &buf, 1);
        size += tmp;
    }
    close(src);

    src = open(filename, O_RDONLY);
	if (src == -1) {
        close(src);
		return NULL;
    }

    if(size == 0) {
        return NULL;
    }
    int temp = 0;
    char *str = mx_strnew(size);
    for(int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    temp = read(src, str, size);
    close(src);

    return str;
}
