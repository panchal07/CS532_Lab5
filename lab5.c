#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void listFiles(const char* dirname) {
    struct dirent* dirent;
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

//https://www.youtube.com/watch?v=j9yL30R6npk
//https://code-vault.net/lesson/18ec1942c2da46840693efe9b526daa4

    printf("Reading files in: %s\n", dirname);

    int count = 1; 
    dirent = readdir(dir);

//https://iq.opengenus.org/traversing-folders-in-c/
//https://codeforwin.org/2018/03/c-program-to-list-all-files-in-a-directory-recursively.html#program-recursive
    
    while (dirent != NULL) {

        printf (" %s\n", (*dirent).d_name); 
         
        if (strcmp((*dirent).d_name, ".") != 0 && strcmp((*dirent).d_name, "..") != 0) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, (*dirent).d_name);
            listFiles(path);
        }
        dirent = readdir(dir);
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    
    if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
    } 
    
    listFiles(argv[1]);

    return 0;
}