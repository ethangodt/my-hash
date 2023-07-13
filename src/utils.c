#include <stdlib.h>
#include <string.h>

char *substr(char *string, size_t start, size_t end /* exclusive */) {
    int len = end - start;
    char *new_string = calloc(sizeof(char), (end - start) + 1); // chars + terminal char
    strncpy(new_string, &string[start], len);
    new_string[len] = '\0';
    return new_string;
}