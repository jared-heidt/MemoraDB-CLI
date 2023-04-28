#include <sys/wait.h>
#include "commands.c"

void execute_command(char **args) {
    for (int i = 0; i < num_builtin_commands(); i++) {
        if (strcmp(args[0], builtin_commands[i].name) == 0) {
            builtin_commands[i].function(args);
            return;
        }
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
        execvp(args[0], args);
        perror("error");
        exit(1);
    } else if (child_pid > 0) {
        int status;
        do {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("error");
    }
}