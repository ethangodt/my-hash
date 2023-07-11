//
// Created by Ethan Godt on 7/11/23.
//

#ifndef MY_HASH_PARSE_H
#define MY_HASH_PARSE_H

enum command {
    INSERT, SEARCH, DELETE, EXIT, NO_MATCH
};

void parse_command(char *command, char ***parsed_command_args_ptr);

enum command match_command(char *possible_command);

#endif //MY_HASH_PARSE_H
