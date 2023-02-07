#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]){
    
    FILE *src, *dst;
    size_t in, out;
    char buf[BUF_SIZE];
    int bufsize;
    int count = 0;
    
    printf("size of argv[] : %d\n", argc);
    printf("arg[-1] : %s\n", argv[argc-1]);


    for (int i = 1; i < argc-1; i++){
        bufsize = atoi(argv[i]);

        if (bufsize > BUF_SIZE) {
            fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[i], BUF_SIZE);
            exit(1);
        }

        src = fopen(argv[i], "r");
        if (src == NULL){
            printf("the src is null");
            exit(2);
        }
        printf("arg[%d]: %s\n", i,argv[i]);

        dst = fopen(argv[argc-1], "w");
        printf("arg[%d]: %s\n", argc-1,argv[argc-1]);

        if (dst < 0){
            printf("dst is less than 0");
            exit(3);
        }

        while (1){
            count++;
            printf("count = %d\n",count);
            printf("this is being called from the While Loop\n");
            in = fread(buf, 1, bufsize, src);
            if (0 == in){
                printf("in == 0");
                break;
            }
            out = fwrite(buf, 1, in, dst);
            if (0 == out){
                printf("out == 0");
                break;
            }
        }

        fclose(src);
        fclose(dst);
    }
    exit(0);
}