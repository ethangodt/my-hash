#include <string.h>
#include <stdlib.h>
#include "parse.h"

void parse_command(char *command, char ***parsed_command_args_ptr) {
    size_t len = strlen(command);
    size_t command_arg_count = 1; // bad

    if (len > 0 && command[len - 1] == '\n') {
        command[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len; ++i) {
        if (command[i] == ' ') {
            command_arg_count++;
        };
    }

    *parsed_command_args_ptr = malloc(sizeof(char *) * (command_arg_count + 1));

    int current_arg = 0;
    int current_arg_start = 0;
    for (int j = 0; j <= len; ++j) {
        if (command[j] == ' ' || command[j] == '\0') {
            command[j] = '\0';
            int current_arg_length = j - current_arg_start;
            char *arg = malloc(current_arg_length + 1);
            strcpy(arg, &command[current_arg_start]);
            (*parsed_command_args_ptr)[current_arg] = arg;
            current_arg++;
            current_arg_start = j + 1;
        }
    }

    (*parsed_command_args_ptr)[command_arg_count + 1] = NULL;
}

enum command match_command(char *possible_command) {
    if (strcmp(possible_command, "insert") == 0) {
        return INSERT;
    } else if (strcmp(possible_command, "search") == 0) {
        return SEARCH;
    } else if (strcmp(possible_command, "delete") == 0) {
        return DELETE;
    } else if (strcmp(possible_command, "exit") == 0) {
        return EXIT;
    } else {
        return NO_MATCH;
    }
}
