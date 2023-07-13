#ifndef MY_HASH_HASH_H
#define MY_HASH_HASH_H

#define HASH_SIZE 5

typedef struct {
    char *key;
    char *value;
} Node;

int hash(char *key);

bool insert(char *key, char *value);

char *search(char *key);

static void erase(Node *key);

bool delete(char *key);

#endif //MY_HASH_HASH_H

