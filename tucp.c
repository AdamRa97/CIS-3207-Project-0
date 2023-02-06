#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]){
    
    FILE *src, *dst;
    size_t in, out;
    char buf[BUF_SIZE];
    int bufsize;

    bufsize = atoi(argv[1]);
    printf("bufsize = %d",bufsize);

    src = fopen(argv[2], "r");

    if (NULL == src) exit(2);
        dst = fopen(argv[3], "w");
    if (dst < 0)
        exit(3);

    while (1){
        in = fread(buf, 1, bufsize, src);
        if (0 == in)
            break;
        out = fwrite(buf, 1, in, dst);
        if (0 == out)
            break;
    }

    fclose(src);
    fclose(dst);
    exit(0);
}