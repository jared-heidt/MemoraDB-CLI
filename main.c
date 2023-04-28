#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.c"
#include "executor.c"

int main() {
    while (true) {
        printf("> ");
        char *line = read_line();
        char **tokens = split_line(line);

        if (tokens[0] != NULL) {
            execute_command(tokens);
        }

        free(tokens);
        free(line);
    }
    return 0;
}