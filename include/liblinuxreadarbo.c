#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#ifndef PATH_MAX
#define PATH_MAX 4096 
#endif
#include "liblinuxreadarbo.h"


char** listFilesfromDirectories(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    dir = opendir(path);

    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return NULL;
    }

    char **filePaths = NULL;
    int fileCount = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char entryPath[PATH_MAX];
            snprintf(entryPath, sizeof(entryPath), "%s/%s", path, entry->d_name);

            if (stat(entryPath, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
                char **subDirFiles = listFilesfromDirectories(entryPath);
                int i = 0;
                while (subDirFiles != NULL && subDirFiles[i] != NULL) {
                    filePaths = realloc(filePaths, (fileCount + 1) * sizeof(char*));
                    filePaths[fileCount] = subDirFiles[i];
                    fileCount++;
                    i++;
                }
                free(subDirFiles);
            } else {

                filePaths = realloc(filePaths, (fileCount + 1) * sizeof(char*));
                filePaths[fileCount] = strdup(entryPath);
                fileCount++;
            }
        }
    }

    closedir(dir);

    filePaths = realloc(filePaths, (fileCount + 1) * sizeof(char*));
    filePaths[fileCount] = NULL;

    return filePaths;
}