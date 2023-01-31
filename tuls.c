#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void *getDir(char *newDir);

int main(int argc, char *argv[]){

    // Checking arguments first to make sure there are no argument errors
    if (argc > 2){
        printf("Cannot have more than one argument\n");
        exit(EXIT_FAILURE);
    }

    getDir(argv[1]);
    
    return(0);
}


// Function that finds current working directory and other directories
void *getDir(char *dir){
    char *currWorkDir, *token, *newDir;
    char buffer[PATH_MAX + 1];
    char *directory;
    size_t length;

    // Checking if user entered in argument or not; also acts as base case for recursion
    if (dir == NULL){

        // Getting current directory path and then shortening it to single directory (e.g blah/blah/blah/cwd -> cwd)
        currWorkDir = getcwd(buffer, PATH_MAX + 1 );
        token = strrchr(currWorkDir, '/');

        // Making sure that the directories even exist
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

        // Checking current directory number of files / folders
        struct dirent **namelist;
        int n;
        n = scandir(".",&namelist,NULL,alphasort);

        // Printing out the directory and freeing up the memory
        char *dir = directory;
        printf("[[%s]]\n",dir);
        free(dir);

        // Printing out the files / folders while freing up memory and checks for any errors
        if (n == -1){
            perror("scandir");
            exit(EXIT_FAILURE);
        }
        while (n--){
            printf("    -> %s\n", namelist[n]->d_name);
            free(namelist[n]);
        }
    }
    else{
        newDir = dir;
        token = newDir;

        // Checking if given argument directory exists
        if(newDir == NULL){
            printf("Directory does not exist");
            exit(1);
        }

        if (token == NULL) {
            printf("Directory does not exist");
            exit(1);
        }

        length = strlen(token);
        directory = malloc(length);
        memcpy(directory, token, length);

        // Checking current directory number of files / folders
        struct dirent **namelist;
        int n;
        n = scandir(token,&namelist,NULL,alphasort);

        // Printing out the directory
        char *dir = directory;
        printf("[[%s]]\n",dir);
        free(dir);

        // Printing out the files / folders while freeing up memory and checks for any errors
        if (n == -1){
            perror("scandir");
            exit(EXIT_FAILURE);
        }
        while (n--){
            printf("    -> %s\n", namelist[n]->d_name);
            free(namelist[n]);
        }

        // recursion
        return getDir(NULL);
    }
    return 0;
}