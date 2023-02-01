#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

void getDir(char *cwd, const int num);

int main(int argc, char *argv[]){
    char path[100];

    // Checking arguments first to make sure there are no argument errors
    if (argc > 2){
        printf("Cannot have more than one argument\n");
        exit(EXIT_FAILURE);
    }

    // Making it so that the given arguments or none are able to be passed through the function with no issues
    if (argv[1] == NULL)
        strcpy(path,".");
    else
        strcpy(path,argv[1]);

    getDir(path, 0);

    return 0;
}


void getDir(char *cwd, const int num){
    int i;
    char path[1000];
    char *currWorkDir, *token;
    char buffer[PATH_MAX + 1];
    struct dirent *nameList;
    DIR *dir = opendir(cwd);
    
    if (!dir)
        return;

    // Adding in title of directory to have better idea of what the root is
    if ((strcmp(cwd,".")) == 0){
        // Getting current directory path and then shortening it to single directory (e.g blah/blah/blah/cwd -> cwd)
        currWorkDir = getcwd(buffer, PATH_MAX + 1 );
        token = strrchr(currWorkDir, '/');
        printf("[[%s]]\n",token);
    }
    else{
        currWorkDir = cwd;
        printf("[[%s]]\n",currWorkDir);
    }

    while ((nameList = readdir(dir)) != NULL){
        if (strcmp(nameList->d_name, ".") != 0 && strcmp(nameList->d_name, "..") != 0){
            for (i = 0; i < num; i++) {
                if (i % 2 == 0 || i == 0)
                    printf("|");
                else
                    printf(" ");
            }

            printf("| -> %s\n", nameList->d_name);

            strcpy(path, cwd);
            strcat(path, "/");
            strcat(path, nameList->d_name);
            getDir(path, num + 2);
        }
    }

    closedir(dir);
}