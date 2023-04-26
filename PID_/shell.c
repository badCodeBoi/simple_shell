#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void)
{
    char *argv[MAX_LINE / 2 + 1];
    char buf[MAX_LINE];
    pid_t pid;
    int should_run = 1;
    int argc;

    while (should_run) {
        printf("#cisfun$ ");
        fflush(stdout);

        fgets(buf, MAX_LINE, stdin);
        buf[strlen(buf) - 1] = '\0';

        argc = 0;
        argv[argc] = strtok(buf, " \n");

        while (argv[argc] != NULL && argc < MAX_LINE / 2) {
            argc++;
            argv[argc] = strtok(NULL, " \n");
        }

        argv[argc] = NULL;

        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Fork failed");
            return 1;
        } else if (pid == 0) {
            if (execvp(argv[0], argv) < 0) {
                printf("Command not found\n");
            }
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
