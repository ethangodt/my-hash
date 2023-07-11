#include <stdio.h>
#include <string.h>
#include "parse.h"
#include "hash.h"

int main() {
    char *command = NULL;
    char **parsed_command = NULL;
    size_t len = 0;
    ssize_t read;
    while (1) {
        read = getline(&command, &len, stdin);
        if (read == -1) {
            return 1;
        }
        if (strcmp(command, "exit\n") == 0) {
            return 0;
        } else {
            printf("you entered: %s", command);
            parse_command(command, &parsed_command);
            for (int i = 0; parsed_command[i] != NULL; ++i) {
                printf("arg %d is: %s\n", i, parsed_command[i]);
                printf("is command insert: %s\n", match_command(parsed_command[i]) == INSERT ? "true" : "false");
                printf("hash value of this is: %d\n", hash(parsed_command[i], HASH_SIZE));
            }
        }
    }
}
