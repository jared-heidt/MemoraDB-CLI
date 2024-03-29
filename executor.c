#include <sys/wait.h>
#include "commands.c"

void execute_command(char **args) {
    void (*func)(char**) = hash_table_lookup(&command_table, args[0]);

    if (func == NULL) {
        printf("Unknown command: %s\n", args[0]);
        return;
    }

    if (func == exit_cli) {
        exit(0);
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
        func(args);
        exit(1);
    } else if (child_pid > 0) {
        int status;
        do {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("error creating child process");
    }
}