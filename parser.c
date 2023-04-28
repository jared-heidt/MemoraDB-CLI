/**
 * Source: https://github.com/dmulholl/kash
 */
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Tokenize a string, splitting on whitespace characters. Leading and trailing
// whitespace is ignored. Consecutive whitespace characters are treated as a
// single delimiter. The return value is a NULL terminated array of string
// pointers which needs to be freed once we're finished with it.
char** split_line(char *line) {
    int length = 0;
    int capacity = 16;

    char **tokens = malloc(capacity * sizeof(char*));
    if (!tokens) {
        perror("token error");
        exit(1);
    }

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    while (token != NULL) {
        tokens[length] = token;
        length++;

        if (length >= capacity) {
            capacity = (int) (capacity * 1.5);
            tokens = realloc(tokens, capacity * sizeof(char*));
            if (!tokens) {
                perror("toker error");
                exit(1);
            }
        }

        token = strtok(NULL, delimiters);
    }

    tokens[length] = NULL;
    return tokens;
}

// Read a single line of input from stdin. The return value is a string pointer
// which needs to be freed once we're finished with it.
char* read_line() {
    char *line = NULL;
    size_t buflen = 0;
    errno = 0;
    ssize_t strlen = getline(&line, &buflen, stdin);
    if (strlen < 0) {
        if (errno) {
            perror("error");
        }
        exit(1);
    }
    return line;
}