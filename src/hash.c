#include <string.h>
#include "hash.h"

int hash(char *key) {
    int num = 0;
    for (int i = 0; i < strlen(key); ++i) {
        num += key[i] * (i + 1);
    }
    return num % HASH_SIZE;
}