#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * freeline - Simple Shell entry point
 *
 * Return: Always 0.
 */
int freeline(void)
{
char *line = NULL;
char *args[BUF_SIZE];
int status = 0;
pid_t pid;

while (1)
    {
printf("$ ");
fflush(stdout);

if (getline(&line, &(size_t){BUF_SIZE}, stdin) == -1)
{
if (errno == EINTR)
continue;
break;
}

if (strcmp(line, "exit\n") == 0)
break;

parse_args(line, args);

pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* Child process */
execve(args[0], args, NULL);
/* execve only returns on error */
perror("execve");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(pid, &status, 0);
}
}

free(line);

return (0);
}





/**
 * parse_args - Splits a string into tokens.
 *
 * @str: String to be splitted.
 * @args: Array of strings that will store the tokens.
 *
 * Return: Number of tokens.
 */
int parse_args(char *str, char **args)
{
int i = 0;
char *token = strtok(str, " \t\n");


while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \t\n");
}
args[i] = NULL;

return (i);
}
