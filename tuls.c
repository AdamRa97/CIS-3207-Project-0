#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]){

    if (argc > 2){
        printf("Cannot have more than one argument\n");
        exit(1);
    }


    return(0);
}