#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#ifndef PATH_MAX
#define PATH_MAX 4096 
#endif


char **listFilesfromDirectories(char *path);