#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
            char *value = parsed_command[2];
            printf("%s was inserted successfully: %s\n", key, insert(key, value) ? "true" : "false");
        } else if (command == SEARCH) {
            char *key = parsed_command[1];
            char *value = search(key);
            if (value != NULL) {
                printf("search for %s found: %s\n", key, value);
            } else {
                printf("search for %s found nothing\n", key);
            }
        } else if (command == DELETE) {
            char *key = parsed_command[1];
            printf("value at key %s deleted successful: %s\n", key, delete(key) ? "true" : "false");
        } else if (command == EXIT) {
            printf("exiting\n");
            return 0;
        } else {
            printf("unable to parse command\n");
        }

        // free each parsed arg in the input
        for (int i = 0; parsed_command[i] != NULL; i++) {
            free(parsed_command[i]);
        }

        // free the allocated array of parsed input args for this submission
        free(parsed_command);
        parsed_command = NULL;
    }
}

