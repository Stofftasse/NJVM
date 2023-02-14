#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    time_t now;
    struct tm *local_time;
    char time_str[30];

    time(&now);
    local_time = localtime(&now);

    strftime(time_str, 30, "%b %d %Y, %H:%M:%S", local_time);

//Argumenteprüfung:
    if(argc > 1){
        if (strcmp(argv[1], "--version") == 0) {
            printf("Ninja Virtual Machine version 0 (compiled %s) \n", time_str);
        } else if (strcmp(argv[1], "--help") == 0) {
            printf("usage: ./njvm [option] [option] ...\n");
            printf("--version \t show version and exit \n");
            printf("--help \t \t show this help and exit \n");
        }else {
            printf("unknown command line argument '%s', try './njvm --help' \n", argv[1]);
    }
    }else if (argc == 1) {
        printf("Ninja Virtual Machine started \n");
        printf("Ninja Virtual Machine stopped \n");
    }


    //Ende der Main
    return 0;
}