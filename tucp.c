#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]){
    FILE *src, *dst;
    size_t in, out;
    char buf[BUF_SIZE];
    struct stat path_stat;
    struct stat dst_stat;
    int checkFile,dstCheck;

    // To check first if there are any errors with the arguments
    if (argc < 3)
        fprintf(stderr, "Expected more arguments or folder error");

    // Storing the value of whether destination is file or folder
    stat(argv[argc-1],&dst_stat);
    dstCheck = S_ISREG(dst_stat.st_mode);

    // To loop through each source
    for (int i = 1; i < argc-1; i++){
        // Checking if the sources are directories error
        stat(argv[i],&path_stat);
        checkFile = S_ISREG(path_stat.st_mode);

        if (checkFile == 0){
            fprintf(stderr, "Source can't be a directory");
            exit(1);
        }

        src = fopen(argv[i], "r");
        if (src == NULL)
            exit(2);

        // Checking if the destination is a file or folder
        if ((dstCheck == 0) && ((access(argv[argc-1],F_OK)) == 0)){
            // To concatenate file name and destination path
            if (strcmp(argv[argc-1],"..")== 0)
                break;
            char *a = argv[i];
            char *b = argv[argc-1];
            char *c = malloc(strlen(a)+strlen(b)+1);
            strcpy(c,b);
            strcat(c,a);

            dst = fopen(c, "w");

            if ((dst < 0) || (dst == NULL)){
                fprintf(stderr, "Directory doesn't exist");
                exit(3);
            }

            while (1){
                in = fread(buf, 1, 1, src);
                if (in == 0)
                    break;
                out = fwrite(buf, 1, in, dst);
                if (out == 0)
                    break;
            }
            free(c);
        }
        else{
            dst = fopen(argv[argc-1], "w");

            if ((dst < 0) || (dst == NULL)){
                fprintf(stderr, "Directory doesn't exist");
                exit(3);
            }

            while (1){
                in = fread(buf, 1, 1, src);
                if (in == 0)
                    break;
                out = fwrite(buf, 1, in, dst);
                if (out == 0)
                    break;
            }

        }
        fclose(src);
        fclose(dst);
    }
    exit(0);
}