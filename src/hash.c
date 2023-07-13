#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hash.h"

Node table[HASH_SIZE] = {0};

int hash(char *key) {
    int num = 0;
    for (int i = 0; i < strlen(key); ++i) {
        num += key[i] * (i + 1);
    }
    return num % HASH_SIZE;
}

bool insert(char *key, char *value) {
    if (table[hash(key)].key != NULL) {
        return false;
    } else {
        table[hash(key)].key = strdup(key);
        table[hash(key)].value = strdup(value);
        return true;
    }
}

char *search(char *key) {
    if (table[hash(key)].key != NULL) {
        return table[hash(key)].value;
    }
    return NULL;
}

static void erase(Node *node) {
    free(node->key);
    free(node->value);
    node->key = NULL;
    node->value = NULL;
}

bool delete(char *key) {
    Node *node = &table[hash(key)];
    if (node->key != NULL) {
        erase(node);
        return true;
    }
    return false;
}
