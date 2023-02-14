#include <stdio.h>
#include <string.h>
#include <time.h>

char act_time(void){
    time_t t = time(NULL);
    struct tm *ts = localtime(&t);
    char *time = asctime(ts);
    return time;
}


int main(int argc, char *argv[]) {

    int time = act_time();

    //Speicherzugriffsfehler falls argv nicht gesetzt
    if(strcmp(argv[1], "--version") == 0){
        printf("Ninja Virtual Machine version 0 (compiled %s )", time);
    }
    else if(strcmp(argv[1], "--help") == 0){
        printf(
            "usage: ./njvm [option] [option] ...\n"
            "--version      show version and exit\n"
            "--help         show this help and exit\n"
        );
    }
    else{
        printf("unknown command line argument '%s', try './njvm --help' \n", argv[1]);
    }
    return 0;
}