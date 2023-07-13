#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include "hash.h"

int main() {
    char *input = NULL;
    char **parsed_command = NULL;
    size_t len = 0;
    ssize_t read;
    while (1) {
        read = getline(&input, &len, stdin);
        if (read == -1) {
            return 1;
        }

        parse_command(input, &parsed_command);
        enum command command = match_command(parsed_command[0]);

        if (command == INSERT) {
            char *key = parsed_command[1];
            int result = insert(key);
            printf("%s was inserted successfully: %s\n", key, result ? "true" : "false");
        }

        // I should probably just reuse the input
        // so I don't have to free all of this
        for (int i = 0; parsed_command[i] != NULL; i++) {
            printf("token %d address: %p\n", i, parsed_command[i]);
            free(parsed_command[i]);
        }
        printf("array %p\n", parsed_command);
        free(parsed_command);
        parsed_command = NULL;
    }
}

