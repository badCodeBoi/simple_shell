#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmdshell.h"

/**
 * main - Entry point for the cmdshell program
 *
 * Return: Always 0
 */

#define PROMPT "cmdshell..$ "

void process_input(char *buffer);

int main(void)
{
char *buffer = NULL;
size_t bufsize = 0;
ssize_t nread;

printf("Welcome to the cmdshell program.\n");

while (1)
{
printf(PROMPT);
nread = getline(&buffer, &bufsize, stdin);
if (nread == -1)
{
printf("\n");
break;
}
buffer[nread - 1] = '\0';
process_input(buffer);
}

free(buffer);
return (0);
}

/**
 *  exit_terminal - function to exit the terminal.
 *
 * Return: 0 exit to exit terminal.
 */

void exit_terminal(void)
{
printf("Exiting the cmdshell program.\n");
exit(0);
}

/**
 * process_input - Process the input received from user
 *
 * @buffer: Pointer to the input buffer
 *
 * Return: None
 */

void process_input(char *buffer)
{
char *token;
char *args[2];

token = strtok(buffer, " ");
args[0] = token;
args[1] = NULL;

if (strcmp(args[0], "exit") == 0)
{
exit_terminal();
}
else
{
if (execve(args[0], args, NULL) == -1)
{
perror("Error");
}
}
}
