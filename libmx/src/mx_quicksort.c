#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL) return -1;
    int counter = 0;

    if (left < right) {
        int left_temp = left;
        int right_temp = right;
        char *mid = arr[(right_temp + left_temp) / 2];

        while (left_temp <= right_temp) {
            while (mx_strlen(arr[left_temp]) < mx_strlen(mid)) left_temp++;
            while (mx_strlen(arr[right_temp]) > mx_strlen(mid)) right_temp--;

            if (left_temp <= right_temp) {
                if (mx_strlen(arr[right_temp]) != mx_strlen(arr[left_temp])) {
                    char *temp = arr[left_temp];
                    arr[left_temp] = arr[right_temp];
                    arr[right_temp] = temp;
                    counter++;
                }
                right_temp--;
                left_temp++;
            }
        }
        counter += mx_quicksort(arr, left, right_temp);
        counter += mx_quicksort(arr, left_temp, right);
    }    
    return counter;
}

