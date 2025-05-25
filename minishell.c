#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("$ ");
        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (!args[0]) continue;
        if (strcmp(args[0], "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("$ ");
        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (!args[0]) continue;
        if (strcmp(args[0], "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("$ ");
        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (!args[0]) continue;
        if (strcmp(args[0], "exit") == 0) break;

        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

