#include <string.h>
#include "hash.h"

char *table[HASH_SIZE] = {NULL};

int hash(char *key) {
    int num = 0;
    for (int i = 0; i < strlen(key); ++i) {
        num += key[i] * (i + 1);
    }
    return num % HASH_SIZE;
}

_Bool insert(char *str) {
    if (table[hash(str)] != NULL) {
        return 0;
    } else {
        table[hash(str)] = str;
    }
    return 1;
};
