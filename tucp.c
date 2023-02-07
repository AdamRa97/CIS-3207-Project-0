#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]){
    
    // FILE *src, *dst;
    // size_t in, out;
    // char buf[BUF_SIZE];
    
    printf("size of argv[] : %d\n", argc);
    printf("arg[-1] : %s", argv[argc-1]);


    // for (int i = 1; i < argc; i++){
        
    //     src = fopen(argv[i], "r");

    //     if (src == NULL)
    //         exit(2);

    //     dst = fopen(argv[argc-1], "w");

    //     if (dst < 0)
    //         exit(3);

    //     while (1){
    //         in = fread(buf, 1, 1, src);
    //         if (0 == in)
    //             break;
    //         out = fwrite(buf, 1, in, dst);
    //         if (0 == out)
    //             break;
    //     }
    // }
    // src = fopen(argv[1], "r");

    // if (NULL == src) exit(2);
    //     dst = fopen(argv[2], "w");
    // if (dst < 0)
    //     exit(3);

    // while (1){
    //     in = fread(buf, 1, 1, src);
    //     if (0 == in)
    //         break;
    //     out = fwrite(buf, 1, in, dst);
    //     if (0 == out)
    //         break;
        // }
    // fclose(src);
    // fclose(dst);
    // exit(0);
}