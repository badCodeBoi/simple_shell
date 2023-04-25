/**
 * cmdshell.c - Command line using Shell
 *
 * Authors: Boitumello Taunyane and Pule Mathikha
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "cmdshell.h"

#define INITIAL_VALUE 42

/**
 * initialize_environment - Function to initialize
 *                          variables and set up the environment
 */
void initialize_environment(void)
{
int variable = INITIAL_VALUE;

printf("The value of the variable is: %d\n", variable);

if (variable > 0)
{
printf("The variable is positive.\n");
}
else if (variable < 0)
{
	printf("The variable is negative.\n");
}
else
{
	printf("The variable is zero.\n");
}
}

/**
 * execute_command - Function to create a child process and execute cmd
 */
void execute_command(void)
{
pid_t pid = fork();

if (pid == -1)
{
	perror("fork");
	exit(EXIT_FAILURE);
}
else if (pid == 0)
{
	execl("/bin/ls", "ls", "-l", NULL);
	perror("execl");
	exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);

printf("Child process exited with status %d\n", WEXITSTATUS(status));
}
}

/**
 * main - Main function
 * Return: 0 on success, error on failure
 */
int main(void)
{
initialize_environment();
execute_command();

return (0);
}
