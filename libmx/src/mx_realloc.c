#include "libmx.h"
void *mx_realloc(void *ptr, size_t size) {
    void *temp;
    size_t cur_size;
    if (ptr == 0)
	    return malloc(size);
    cur_size = malloc_size(ptr);
    if (size <= cur_size)
	    return ptr;
    temp = malloc(size);
    mx_memcpy(temp, ptr, size);
    free(ptr);
    return temp;
}
