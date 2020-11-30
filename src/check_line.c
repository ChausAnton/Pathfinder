#include "../inc/pathfinder.h"

void check_line(char *temp, int line_num) {
    for(; *temp != ','; temp++) {
                if(mx_isdigit(*temp)) {
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(line_num));
                    mx_printerr(" is not valid");
                    exit(0);
                }
                if(*temp == '-'){
                    temp++;
                    if(!mx_islower(*temp) && !mx_isupper(*temp)) {
                        mx_printerr("error: line ");
                        mx_printerr(mx_itoa(line_num));
                        mx_printerr(" is not valid");
                        exit(0);
                    }
                }

            }
            temp++;
            for(; *temp != '\0'; temp++) {
                if(!mx_isdigit(*temp)) {
                    mx_printerr("error: line ");
                    mx_printerr(mx_itoa(line_num));
                    mx_printerr(" is not valid");
                    exit(0);
                }
            }
}
