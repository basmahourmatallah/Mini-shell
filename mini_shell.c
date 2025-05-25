
---

### `mini_shell.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD];        // Stores the user input
    char *args[MAX_ARGS];     // Stores the parsed arguments

    while (1) {
        printf("$ ");         // Print shell prompt
        fflush(stdout);

        // Read user input
        if (!fgets(cmd, MAX_CMD, stdin)) break;

        // Remove newline character
        cmd[strcspn(cmd, "\n")] = 0;

        // Exit condition
        if (strcmp(cmd, "exit") == 0) break;

        // Tokenize input into command and arguments
        int i = 0;
        char *token = strtok(cmd, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // Null-terminate the args array

        // Create a child process
        pid_t pid = fork();

        if (pid == 0) {
            // In child process: execute command
            execvp(args[0], args);
            perror("execvp"); // If exec fails
            exit(EXIT_FAILURE);
        } else if (pid > 0) {
            // In parent process: wait for child
            wait(NULL);
        } else {
            // Fork failed
            perror("fork");
        }
    }

    return 0;
}

