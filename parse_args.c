#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

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
