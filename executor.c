#include <sys/wait.h>
#include "commands.c"

void execute_command(char **args) {
    /*
    for (int i = 0; i < num_builtin_commands(); i++) {
        if (strcmp(args[0], builtin_commands[i].name) == 0) {
            builtin_commands[i].function(args);
            return;
        }
    }
    */
    void (*func)(char**) = hash_table_lookup(&command_table, args[0]);

    if (func == NULL) {
        printf("Unknown command: %s\n", args[0]);
        return;
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
        func(args);
        exit(0);
    } else if (child_pid > 0) {
        int status;
        do {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("error creating child process");
    }
}