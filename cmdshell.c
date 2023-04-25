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

/**
 * initialize_environment - Function to initialize
 *                      variables and set up the enviroment
 *
 * Return: void
 */

#define INITIAL_VALUE 42

/* Function to initialize variables and set up the environment */
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
 *
 * Return: void
 */

/* Function to create a child process and execute a command */
void execute_command(void)
{
pid_t pid = fork();
/* create a child process */

if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/* This code runs in the child process */
execl("/bin/ls", "ls", "-l", NULL);
/* execute the "ls -l" command*/
perror("execl");
/* This line will be reached only if execl fails*/
exit(EXIT_FAILURE);
}
else
{
/* This code runs in the parent process*/
int status;
waitpid(pid, &status, 0);
/* wait for the child process to exit */
printf("Child process exited with status %d\n", WEXITSTATUS(status));
}
}
/**
 * main - main function
 *
 * Return: 0 on success, error on failure
 */

/* Main function */
int main(void)
{
initialize_environment(); /* Call the initialize_environment function */
execute_command(); /* Call the execute_command function */

return (0);
}
