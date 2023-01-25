#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void *getCurrentDir(void);

int main(int argc, char const *argv[]){

    // Checking arguments first to make sure there are no argument errors
    if (argc > 2){
        printf("Cannot have more than one argument\n");
        exit(EXIT_FAILURE);
    }
    
    // Checking current directory number of files / folders
    struct dirent **namelist;
    int n;
    n = scandir(".",&namelist,NULL,alphasort);

    // Printing out the directory
    char *dir = getCurrentDir();
    printf("[[%s]]\n",dir);
    free(dir);

    // Printing out the files / folders and checks for any errors
    if (n == -1){
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    while (n--){
        printf("    -> %s\n", namelist[n]->d_name);
        free(namelist[n]);
    }


    return(0);
}


// Function that 
void *getCurrentDir(void){
    char *currWorkDir, *token;
    char buffer[PATH_MAX + 1];
    char *directory;
    size_t length;

    currWorkDir = getcwd(buffer, PATH_MAX + 1 );
    token = strrchr(currWorkDir, '/');

    if( currWorkDir == NULL ){
        printf("Directory does not exist");
        exit(1);
    }

    if (token == NULL) {
        printf("Directory does not exist");
        exit(1);
    }

    length = strlen(token);
    directory = malloc(length);
    memcpy(directory, token+1, length);

    return directory;
}