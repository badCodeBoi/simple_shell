#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
char *read_command(char *buffer);
void parse_command(char *buffer, char **args);
void execute_command(char **args);

/**
 * main - interpreter for commandline
 *
 * Return: 0 on success, non-zero on failure
 */
int main(void)
{
char buffer[BUFFER_SIZE];
char *args[BUFFER_SIZE / 2 + 1];

while (1)
{
display_prompt();

if (read_command(buffer) == NULL)
{
	printf("\n");
	break;
}

parse_command(buffer, args);

if (args[0] == NULL)
{
	continue;
}

execute_command(args);
}

return (0);
}

/**
 * display_prompt - displays the shell prompt
 */
void display_prompt(void)
{
printf("#cisfun$ ");
fflush(stdout);
}

/**
 * read_command - reads a command from the user and stores it in a buffer
 *
 * @buffer: the buffer to store the command in
 *
 * Return: a pointer to the buffer, or NULL if there was an error
 */
char *read_command(char *buffer)
{
if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
{
return (NULL);
}

buffer[strcspn(buffer, "\n")] = '\0';

return (buffer);
}

/**
 * parse_command - parses a command into an array of arguments
 *
 * @buffer: the command to parse
 * @args: the array to store the arguments in
 */
void parse_command(char *buffer, char **args)
{
int i = 0;
args[i] = strtok(buffer, " ");

while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " ");
}

args[i] = NULL;
}

/**
 * execute_command - executes a command with the given arguments
 *
 * @args: the arguments to pass to the command
 */
void execute_command(char **args)
{
pid_t pid;
int status;

pid = fork();

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
