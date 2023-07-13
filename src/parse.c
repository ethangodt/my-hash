#include <string.h>
#include <stdlib.h>
#include "parse.h"
#include "utils.h"

void parse_command(char *command, char ***parsed_command_args_ptr) {
    if (command[strlen(command) - 1] == '\n') {
        command[strlen(command) - 1] = '\0';
    }

    size_t command_arg_count = 1;
    for (int i = 0; i < strlen(command); ++i) {
        if (command[i] == ' ') {
            command_arg_count++;
        }
    }

    *parsed_command_args_ptr = calloc(sizeof(char *), command_arg_count + 1);

    int current_arg = 0;
    int current_arg_start = 0;
    for (int j = 0; j <= strlen(command); ++j) {
        if (command[j] == ' ' || command[j] == '\0') {
            char *arg = substr(command, current_arg_start, j);
            (*parsed_command_args_ptr)[current_arg] = arg;
            current_arg++;
            current_arg_start = j + 1;
        }
    }

    (*parsed_command_args_ptr)[command_arg_count] = NULL;
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
